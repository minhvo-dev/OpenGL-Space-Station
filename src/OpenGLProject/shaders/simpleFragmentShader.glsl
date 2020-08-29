/*
 *	File name:	"simpleFragmentShader.glsl"
 *	Date:		6/29/2020 3:46:04 PM
 *	Author:		Vo, Dinh Tue Minh
 *	Purpose:	Fragment shader - color/texture
 */

#version 420

// colors come from Vertex Shader
in vec4 fCol; // used to be color
in vec4 fNorm; 
in vec4 fUVx2;
in vec4 fVertWorldPos;

// color of the pixel will be drawn on the screen
out vec4 pixelCol; // explicitly 

// STARTOF: added for lighting
uniform vec4 diffuseColour;
uniform vec4 specularColour;

uniform vec4 eyeLocation;

// if this is true, then don't apply the lighting calculation
// (used for wireframe and debug type objects)
uniform bool hasNoLighting;

// Can't make arrays of samplers
uniform sampler2D texture0A;		
uniform sampler2D texture0B;		
uniform sampler2D texture0C;
uniform sampler2D texture0D;

uniform vec4 textureRatios;

// Skybox texture
uniform samplerCube skyboxTexture0A;
uniform bool bIsSkybox;


// Fragment shader
struct sLight
{
	vec4 position;			
	vec4 diffuse;	
	vec4 specular;	// rgb = highlight colour, w = power
	vec4 atten;		// x = constant, y = linear, z = quadratic, w = DistanceCutOff
	vec4 direction;	// Spot, directional lights
	vec4 param1;	// x = lightType, y = inner angle, z = outer angle, w = TBD
	                // 0 = pointlight
					// 1 = spot light
					// 2 = directional light
	vec4 param2;	// x = 0 for off, 1 for on
};

const int POINT_LIGHT_TYPE = 0;
const int SPOT_LIGHT_TYPE = 1;
const int DIRECTIONAL_LIGHT_TYPE = 2;

//const int NUMBEROFLIGHTS = 10;
const int NUMBEROFLIGHTS = 40;
uniform sLight theLights[NUMBEROFLIGHTS];  	// 80 uniforms

vec4 calculateLightContrib( vec3 vertexMaterialColour, vec3 vertexNormal, 
                            vec3 vertexWorldPos, vec4 vertexSpecular );

// ENDOF: added for lighting

uniform mat4 matTextRotation;

void main()
{
    //gl_FragColor = fCol; // implicitly
    // pixelCol = fNorm;
    // pixelCol = fCol;

	if (hasNoLighting) {
		//pixelCol = vec4(diffuseColour, 1.0f);
		pixelCol = fCol;
		return;
	}
	
	// Skybox texture
	if (bIsSkybox) { 
		vec3 skyboxNormal = (matTextRotation * fNorm).xyz;
		// make it project from sphere to the inside of skybox
		skyboxNormal = -skyboxNormal;

		vec4 skyboxPixel_0A = texture(skyboxTexture0A, skyboxNormal);

		pixelCol.rgb = skyboxPixel_0A.rgb;
		// No lighting
		pixelCol.a = 1.0f;

		return;
	}
	
	vec4 texturePixelRGBA_0A = texture( texture0A, fUVx2.st );
	vec4 texturePixelRGBA_0B = texture( texture0B, fUVx2.st );
	vec4 texturePixelRGBA_0C = texture( texture0C, fUVx2.st );
	vec4 texturePixelRGBA_0D = texture( texture0D, fUVx2.st );

	vec4 combinePixelRGBA =		( texturePixelRGBA_0A * textureRatios.x ) 
								+ ( texturePixelRGBA_0B * textureRatios.y )
								+ ( texturePixelRGBA_0C * textureRatios.z )
								+ ( texturePixelRGBA_0D * textureRatios.w );

	pixelCol = calculateLightContrib(	//diffuseColour.rgb, // mesh color
										//vec3(fCol.rgb), // actual object color
										vec3(combinePixelRGBA.rgb),
										vec3(fNorm.xyz),
										vec3(fVertWorldPos.xyz),
										specularColour); // using specular now
										// With alpha blending, there is hardware 
	// that reads the 4th value (the "alpha channel")
	// directly. 
	

	pixelCol.a =  diffuseColour.a;	// mesh alpha
					//	fCol.a;				// actual object alpha
					//combinePixelRGBA.a;	// combine texture alpha
	

}

// Source: INFO3111
// Calculate the color of the vertex 
vec4 calculateLightContrib( vec3 vertexMaterialColour, vec3 vertexNormal, 
                            vec3 vertexWorldPos, vec4 vertexSpecular )
{
	vec3 norm = normalize(vertexNormal);
	
	vec4 finalObjectColour = vec4( 0.0f, 0.0f, 0.0f, 1.0f );
	
	for ( int index = 0; index < NUMBEROFLIGHTS; index++ )
	{	
		// ********************************************************
		// is light "on"
		if ( theLights[index].param2.x == 0.0f )
		{	// it's off
			continue;
		}
		
		// Cast to an int (note with c'tor)
		int intLightType = int(theLights[index].param1.x);
		
		// We will do the directional light here... 
		// (BEFORE the attenuation, since sunlight has no attenuation, really)
		if ( intLightType == DIRECTIONAL_LIGHT_TYPE )		// = 2
		{
			// This is supposed to simulate sunlight. 
			// SO: 
			// -- There's ONLY direction, no position
			// -- Almost always, there's only 1 of these in a scene
			// Cheapest light to calculate. 

			vec3 lightContrib = theLights[index].diffuse.rgb;
			
			// Get the dot product of the light and normalize
			float dotProduct = dot( -theLights[index].direction.xyz,  
									   normalize(norm.xyz) );	// -1 to 1

			dotProduct = max( 0.0f, dotProduct );		// 0 to 1
			
			lightContrib *= dotProduct;		
			
			finalObjectColour.rgb += (vertexMaterialColour.rgb * theLights[index].diffuse.rgb * lightContrib); 
									 //+ (materialSpecular.rgb * lightSpecularContrib.rgb);
			// NOTE: There isn't any attenuation, like with sunlight.
			// (This is part of the reason directional lights are fast to calculate)


			return finalObjectColour;		
		}
		
		// Assume it's a point light 
		// intLightType = 0
		
		// Contribution for this light
		vec3 vLightToVertex = theLights[index].position.xyz - vertexWorldPos.xyz;
		float distanceToLight = length(vLightToVertex);	

		// Distance cut off (for performance)
		if (distanceToLight > theLights[index].atten.w)
		{
			// Light is too far away, skip this light
			// i.e. light is "black" at this distance
			continue;
		}


		vec3 lightVector = normalize(vLightToVertex);
		float dotProduct = dot(lightVector, vertexNormal.xyz);	 
		
		dotProduct = max( 0.0f, dotProduct );	
		
		vec3 lightDiffuseContrib = dotProduct * theLights[index].diffuse.rgb;
			

		// Specular 
		vec3 lightSpecularContrib = vec3(0.0f);
			
		vec3 reflectVector = reflect( -lightVector, normalize(norm.xyz) );

		// Get eye or view vector
		// The location of the vertex in the world to your eye
		vec3 eyeVector = normalize(eyeLocation.xyz - vertexWorldPos.xyz);

		// To simplify, we are NOT using the light specular value, just the object’s.
		float objectSpecularPower = vertexSpecular.w; 
		
		lightSpecularContrib = pow( max(0.0f, dot( eyeVector, reflectVector) ), objectSpecularPower )
			                   * vertexSpecular.rgb;	//* theLights[lightIndex].Specular.rgb
					   
		// Attenuation
		float attenuation = 1.0f / 
				( theLights[index].atten.x + 										
				  theLights[index].atten.y * distanceToLight +						
				  theLights[index].atten.z * distanceToLight*distanceToLight );  	
				  
		// total light contribution is Diffuse + Specular
		lightDiffuseContrib *= attenuation;
		lightSpecularContrib *= attenuation;
		
		
		// But is it a spot light
		if ( intLightType == SPOT_LIGHT_TYPE )		// = 1
		{	
		

			// Yes, it's a spotlight
			// Calcualate light vector (light to vertex, in world)
			vec3 vertexToLight = vertexWorldPos.xyz - theLights[index].position.xyz;

			vertexToLight = normalize(vertexToLight);

			float currentLightRayAngle
					= dot( vertexToLight.xyz, theLights[index].direction.xyz );
					
			currentLightRayAngle = max(0.0f, currentLightRayAngle);

			//vec4 param1;	
			// x = lightType, y = inner angle, z = outer angle, w = TBD

			// Is this inside the cone? 
			float outerConeAngleCos = cos(radians(theLights[index].param1.z));
			float innerConeAngleCos = cos(radians(theLights[index].param1.y));
							
			// Is it completely outside of the spot?
			if ( currentLightRayAngle < outerConeAngleCos )
			{
				// Nope. so it's in the dark
				lightDiffuseContrib = vec3(0.0f, 0.0f, 0.0f);
				lightSpecularContrib = vec3(0.0f, 0.0f, 0.0f);
			}
			else if ( currentLightRayAngle < innerConeAngleCos )
			{
				// Angle is between the inner and outer cone
				// (this is called the penumbra of the spot light, by the way)
				// 
				// This blends the brightness from full brightness, near the inner cone
				//	to black, near the outter cone
				float penumbraRatio = (currentLightRayAngle - outerConeAngleCos) / 
									  (innerConeAngleCos - outerConeAngleCos);
									  
				lightDiffuseContrib *= penumbraRatio;
				lightSpecularContrib *= penumbraRatio;
			}
						
		}// if ( intLightType == 1 )
		
		
					
		finalObjectColour.rgb += (vertexMaterialColour.rgb * lightDiffuseContrib.rgb)
								  + (vertexSpecular.rgb * lightSpecularContrib.rgb );
	}//for(intindex=0...
	finalObjectColour.a = 1.0f;
	
	return finalObjectColour;
}