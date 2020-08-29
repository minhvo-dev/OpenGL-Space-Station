/*
 *	File name:	"drawObjects.cpp"
 *	Date:		7/22/2020 11:23:38 AM
 *	Author:		Vo, Dinh Tue Minh
 *	Purpose:	Implements drawing Mesh objects
 *	Note:		Mathematical calculations were taken from INFO3111
 */


#include "../headers/globalVariables.hpp"
#include "../headers/globalOpenGL.hpp"
#include "../vao_model_manager/cVAOManager.hpp"
#include "../headers/globalUtilities.hpp"

#include <glm/vec3.hpp>						// glm::vec3
#include <glm/mat4x4.hpp>					// glm::mat4
#include <glm/gtc/matrix_transform.hpp>		// glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp>				// glm::value_ptr

static float textureRotationAngle = 0.0f; // skybox rotating angle
static float step = glm::radians(0.02f);  

void draw_mesh_object(GLuint const program, cMeshObject * const pObj, glm::mat4 const &matView, glm::mat4 const &matProjection) {
	// Do not draw invisible object
	if (pObj->isVisible == false) {
		return;
	}

	
	
	if (GLint bIsSkybox_LocID = glGetUniformLocation(program, "bIsSkybox"); pObj->friendlyName == "skybox") {
		glUniform1f(bIsSkybox_LocID, (float)GL_TRUE);
		// ************************************
		// STARTOF: Skybox set-up
		// ************************************
		{
			GLint skyboxTexture0A_LocID = glGetUniformLocation(program, "skyboxTexture0A");
			GLuint currentTextureID = ::g_pTextureManager->getTextureIDFromName(pObj->textureNames[0]);
			glActiveTexture(GL_TEXTURE17); // unit #17
			// bind texture with GL_TEXTURE_CUBE_MAP flag
			glBindTexture(GL_TEXTURE_CUBE_MAP, currentTextureID);
			glUniform1i(skyboxTexture0A_LocID, 17);
		}

		// rotate skybox
		{
			if (textureRotationAngle > glm::radians(360.0f) || textureRotationAngle < 0) {
				step = -step;
			}
			textureRotationAngle += step;

			glm::mat4 matRotTexture = glm::rotate(glm::mat4(1.0f),
												  textureRotationAngle, 
												  glm::vec3(0.0f, 0.0f, 1.0f));
			GLint matTextRotation_UniLoc = glGetUniformLocation(program, "matTextRotation");
			glUniformMatrix4fv(matTextRotation_UniLoc, 1, GL_FALSE, glm::value_ptr(matRotTexture));
		}
		// ************************************
		// ENDOF: Skybox set-up
		// ************************************
	}
	else {
		glUniform1f(bIsSkybox_LocID, (float)GL_FALSE);
		// ************************************
		// STARTOF: Normal Texture set-up
		// ************************************

		// Normal textures
		GLint texture0A_LocID = glGetUniformLocation(program, "texture0A");
		GLint texture0B_LocID = glGetUniformLocation(program, "texture0B");
		GLint texture0C_LocID = glGetUniformLocation(program, "texture0C");
		GLint texture0D_LocID = glGetUniformLocation(program, "texture0D");
		{
			// Choose texture units for the textures
			glActiveTexture(GL_TEXTURE0); // unit #0
			GLuint currentTextureID = ::g_pTextureManager->getTextureIDFromName(pObj->textureNames[0]);
			// Make the texture current texture
			glBindTexture(GL_TEXTURE_2D, currentTextureID);    // This is the "current" texture
			// Connect the sampler to the "Texture Unit"
			glUniform1i(texture0A_LocID, 0);     // Note: we pass a NUMBER, not an enum (GL_TEXTURE0)
		}
		{
			// Choose texture units for the textures
			glActiveTexture(GL_TEXTURE1); // unit #1
			GLuint currentTextureID = ::g_pTextureManager->getTextureIDFromName(pObj->textureNames[1]);
			// Make the texture current texture
			glBindTexture(GL_TEXTURE_2D, currentTextureID);    // This is the "current" texture
			// Connect the sampler to the "Texture Unit"
			glUniform1i(texture0B_LocID, 1);     // Note: we pass a NUMBER, not an enum (GL_TEXTURE1)
		}
		{
			// Choose texture units for the textures
			glActiveTexture(GL_TEXTURE2); // unit #2
			GLuint currentTextureID = ::g_pTextureManager->getTextureIDFromName(pObj->textureNames[2]);
			// Make the texture current texture
			glBindTexture(GL_TEXTURE_2D, currentTextureID);    // This is the "current" texture
			// Connect the sampler to the "Texture Unit"
			glUniform1i(texture0C_LocID, 2);     // Note: we pass a NUMBER, not an enum (GL_TEXTURE2)
		}
		{
			// Choose texture units for the textures
			glActiveTexture(GL_TEXTURE3); // unit #3
			GLuint currentTextureID = ::g_pTextureManager->getTextureIDFromName(pObj->textureNames[3]);
			// Make the texture current texture
			glBindTexture(GL_TEXTURE_2D, currentTextureID);    // This is the "current" texture
			// Connect the sampler to the "Texture Unit"
			glUniform1i(texture0D_LocID, 3);     // Note: we pass a NUMBER, not an enum (GL_TEXTURE3)
		}

		// copy the texture ratios
		GLint textureRatio_LocID = glGetUniformLocation(program, "textureRatios");
		glUniform4f(textureRatio_LocID,
					pObj->textureRatios[0],
					pObj->textureRatios[1],
					pObj->textureRatios[2],
					pObj->textureRatios[3]);

		// ************************************
		// ENDOF: Texture set-up
		// ************************************
	}

	// Get the uniform variables location in the shader
	GLint matModel_LocID = glGetUniformLocation(program, "matModel");
	GLint matView_LocID = glGetUniformLocation(program, "matView");
	GLint matProj_LocID = glGetUniformLocation(program, "matProj");

	GLint diffuseColour_LocID = glGetUniformLocation(program, "diffuseColour");
	GLint specularColour_LocID = glGetUniformLocation(program, "specularColour");

	GLint hasNoLighting_LocID = glGetUniformLocation(program, "hasNoLighting");

	//         mat4x4_identity(m);
	glm::mat4 matModel = glm::mat4(1.0f);

	// ************************************
	// STARTOF: Model transformations 
	// ************************************

	// Place the object in the world at 'this' location
	glm::mat4 matTranslation
		= glm::translate(glm::mat4(1.0f),
						 glm::vec3(pObj->pos.x,
								   pObj->pos.y,
								   pObj->pos.z));
	matModel = matModel * matTranslation;


	//mat4x4_rotate_Z(m, m, );
	//*************************************
	// ROTATE around Z
	glm::mat4 matRotateZ = glm::rotate(glm::mat4(1.0f),
									   pObj->orientation.z, // (float) glfwGetTime(), 
									   glm::vec3(0.0f, 0.0f, 1.0f));
	matModel = matModel * matRotateZ;
	//*************************************

	//*************************************
	// ROTATE around Y
	glm::mat4 matRotateY = glm::rotate(glm::mat4(1.0f),
									   pObj->orientation.y, // (float) glfwGetTime(), 
									   glm::vec3(0.0f, 1.0f, 0.0f));
	matModel = matModel * matRotateY;
	//*************************************

	//*************************************
	// ROTATE around X
	glm::mat4 rotateX = glm::rotate(glm::mat4(1.0f),
									pObj->orientation.x, // (float) glfwGetTime(), 
									glm::vec3(1.0f, 0.0, 0.0f));
	matModel = matModel * rotateX;
	//*************************************


	// Set up a scaling matrix
	glm::mat4 matScale = glm::mat4(1.0f);

	float theScale = pObj->scale;		// 1.0f;		
	matScale = glm::scale(glm::mat4(1.0f),
						  glm::vec3(theScale, theScale, theScale));


	// Apply (multiply) the scaling matrix to 
	// the existing "model" (or "world") matrix
	matModel = matModel * matScale;

	// ************************************
	// ENDOF: Model transformations 
	// ************************************

	glUseProgram(program);

	// copy the value from the program to the shader
	glUniformMatrix4fv(matModel_LocID, 1, GL_FALSE, glm::value_ptr(matModel));
	glUniformMatrix4fv(matView_LocID, 1, GL_FALSE, glm::value_ptr(matView));
	glUniformMatrix4fv(matProj_LocID, 1, GL_FALSE, glm::value_ptr(matProjection));

	/* Switch between wireframe and solid */
	if (pObj->isWireframe) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // GL_LINE for wire frame
		// Turn OFF the lighting of this object
		glUniform1f(hasNoLighting_LocID, (float)GL_TRUE);
	}
	else {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // GL_FILL for solid frame
		// Turn ON the lighting of this object
		glUniform1f(hasNoLighting_LocID, (float)GL_FALSE);
	}

	// Alpha transparency using the "blend" function
	// it's a "2 pass" effect, reading then writing to the "back buffer" (the screen)
	// If we DON'T need it, then disable it
	// The "alpha" value can be from 0.0 to 1.0f
	// If it's 1.0, then there's NO transparency, so there's no reason to enable this
	if (pObj->diffuseRGBA.a < 1.0f) {
		// Enable transparency 
		glEnable(GL_BLEND);
	}
	else {
		// Disable 
		glDisable(GL_BLEND);
	}
	// sets the state of the blend function
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	// copy the diffuse color info to the shader
	glUniform4f(diffuseColour_LocID,
				pObj->diffuseRGBA.r,
				pObj->diffuseRGBA.g,
				pObj->diffuseRGBA.b,
				pObj->diffuseRGBA.a);
	// copy the specular color into the shader
	glUniform4f(specularColour_LocID,
				pObj->specularRGB_Power.r,
				pObj->specularRGB_Power.g,
				pObj->specularRGB_Power.b,
				pObj->specularRGB_Power.w);


	if (sModelDrawInfo *pModelToDrawMDI = ::g_pVAOManager->find_MDI_by_model_name(pObj->meshName)) {
		glBindVertexArray(pModelToDrawMDI->VAO_ID);
		glDrawElements(GL_TRIANGLES,
					   pModelToDrawMDI->numberOfIndices,
					   GL_UNSIGNED_INT, // how big the index values are
					   0 // starting index for this model
		);
		glBindVertexArray(0);
	}

}