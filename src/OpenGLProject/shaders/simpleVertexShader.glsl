/*
 *	File name:	"simpleFragmentShader.glsl"
 *	Date:		6/29/2020 3:45:54 PM
 *	Author:		Vo, Dinh Tue Minh
 *	Purpose:	Vertex shader - postion
 */

#version 420

// uniform mat4 MVP;    // uniform means they are common (the same) for every thread (shader)
uniform mat4 matModel;  // "model" or "world" matrix
uniform mat4 matView;   // "view" or "camera" or "eye" matrix
uniform mat4 matProj;    // "projection" matrix (ortographic or perspective)

// uniform vec4 objCol;


// vertices coming INTO the Vertex Shader
// In GPU, each block is vec4 of floats, so no need to save space 
in vec4 vCol;  // older version using 'varying' instead of 'in'
in vec4 vNorm; // added normal
in vec4 vPos;
in vec4 vUVx2; // will use later

// colors + normals coming OUT from the Vertex Shader to the Fragment Shader
out vec4 fCol;
out vec4 fNorm;
out vec4 fUVx2;
out vec4 fVertWorldPos; // vertex position in world space

void main()
{
    // note that they are applied in reverse order
    mat4 MVP = matProj * matView * matModel;    
    vec4 position = vec4(vPos.xyz, 1.0f);

    gl_Position = MVP * position; // MVP is mat4x4

    // copying to the fragment
    fCol = vCol;
    // remove translation and scaling from the normal, leaving ONLY rotation
    fNorm = inverse(transpose(matModel)) * vec4(vNorm.xyz, 1.0f);
    fUVx2 = vUVx2;
    fVertWorldPos = matModel * position;
}