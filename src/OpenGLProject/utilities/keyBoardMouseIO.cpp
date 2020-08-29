/*	
 *	File name:	"keyBoardMouseIO.cpp"
 *	Date:		8/8/2020 10:48:28 AM
 *	Author:		Vo, Dinh Tue Minh
 *	Purpose:	Implements keyboard and mouse input/output
 */

#include "../headers/globalOpenGL.hpp"
#include "../headers/globalVariables.hpp"
#include "../headers/globalUtilities.hpp"

static bool g_MouseIsInsideWindow = false;
static bool g_MouseLeftButtonIsDown = false;

void cursor_enter_callback(GLFWwindow* window, int entered) {
	if (entered) {
		::g_MouseIsInsideWindow = true;
		//std::cout << "Mouse moved inside window" << std::endl;
	}
	else {
		::g_MouseIsInsideWindow = false;
		//std::cout << "Mouse moved outside window" << std::endl;
	}
}

bool isOnlyShiftKeyDown(int mods) {
	if (mods == GLFW_MOD_SHIFT) {
		// Shift key is down all by itself
		return true;
	}
	return false;
}

bool isOnlyCtrlKeyDown(int mods) {
	if (mods == GLFW_MOD_CONTROL) {
		return true;
	}
	return false;
}

bool isOnlyAltKeyDown(int mods) {
	if (mods == GLFW_MOD_ALT) {
		return true;
	}
	return false;
}

bool isShiftDown(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT)) { return true; }
	if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT)) { return true; }
	// both are up
	return false;
}

bool isCtrlDown(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL)) { return true; }
	if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL)) { return true; }
	// both are up
	return false;
}

bool isAltDown(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_LEFT_ALT)) { return true; }
	if (glfwGetKey(window, GLFW_KEY_RIGHT_ALT)) { return true; }
	// both are up
	return false;
}

bool areAllModifiersUp(GLFWwindow* window) {
	if (isShiftDown(window)) { return false; }
	if (isCtrlDown(window)) { return false; }
	if (isAltDown(window)) { return false; }
	// Yup, they are all UP
	return true;
}

// Callback when you use the mouse scroll wheel
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	// A regular mouse wheel returns the y value
	::g_pFlyCamera->setMouseWheelDelta(yoffset * 0.1f);
	//g_pCameraManager->getCurrentCamera()->Update("setMouseWheelDelta", (float)yoffset);

	//	std::cout << "Mouse wheel: " << yoffset << std::endl;

	return;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
		::g_MouseLeftButtonIsDown = true;
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
		::g_MouseLeftButtonIsDown = false;
	}

	return;
}

void ProcessAsyncMouse(GLFWwindow* window) {
	double x, y;
	glfwGetCursorPos(window, &x, &y);

	::g_pFlyCamera->setMouseXY(x, y);
	//::g_pCameraManager->getCurrentCamera()->Update("setMouseXY", glm::vec2(x, y));

	static const float MOUSE_SENSITIVITY = 0.1f;

	//	std::cout << ::g_pFlyCamera->getMouseX() << ", " << ::g_pFlyCamera->getMouseY() << std::endl;

		// Mouse left (primary?) button pressed? 
		// AND the mouse is inside the window...
	if ((glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
		&& ::g_MouseIsInsideWindow) {
		// Mouse button is down so turn the camera
		::g_pFlyCamera->Yaw_LeftRight(-::g_pFlyCamera->getDeltaMouseX() * MOUSE_SENSITIVITY);
		//glm::vec3 deltaMouseX = ::g_pCameraManager->getCurrentCamera()->getData("getDeltaMouseX");
		//::g_pCameraManager->getCurrentCamera()->Update("Yaw_LeftRight", -deltaMouseX.x * MOUSE_SENSITIVITY);


		::g_pFlyCamera->Pitch_UpDown(::g_pFlyCamera->getDeltaMouseY() * MOUSE_SENSITIVITY);
		//glm::vec3 deltaMouseY = ::g_pCameraManager->getCurrentCamera()->getData("getDeltaMouseY");
		//::g_pCameraManager->getCurrentCamera()->Update("Pitch_UpDown", deltaMouseY.x * MOUSE_SENSITIVITY);
		print_camera_position();
	}

	// Adjust the mouse speed
	if (::g_MouseIsInsideWindow) {
		static const float MOUSE_WHEEL_SENSITIVITY = 0.1f;

		// Adjust the movement speed based on the wheel position
		::g_pFlyCamera->movementSpeed += (::g_pFlyCamera->getMouseWheel() * MOUSE_WHEEL_SENSITIVITY);

		//glm::vec3 movementSpeed = ::g_pCameraManager->getCurrentCamera()->getData("getMovementSpeed");

		//glm::vec3 mouseWheel = ::g_pCameraManager->getCurrentCamera()->getData("getMouseWheel");
		//movementSpeed.x += mouseWheel.x * MOUSE_WHEEL_SENSITIVITY;
		//::g_pCameraManager->getCurrentCamera()->Update("setMovementSpeed", mouseWheel.x * MOUSE_WHEEL_SENSITIVITY );



		if (::g_pFlyCamera->movementSpeed <= 0.0f) {
			::g_pFlyCamera->movementSpeed = 0.0f;
		}
		//if (movementSpeed.x <= 0.0f)
		//{
		//	movementSpeed.x = 0.0f;
		//}
		//
	}


	// HACK 
	//::g_pFlyCamera->movementSpeed = 2.0f;
	//::g_pCameraManager->getCurrentCamera()->Update("setMovementSpeed", 2.0f);

	return;
}


void ProcessAsyncKeys(GLFWwindow* window) {
	static const float CAMERA_MOVE_SPEED_SLOW = 0.1f;
	static const float CAMERA_MOVE_SPEED_FAST = 1.0f;

	static const float CAMERA_TURN_SPEED = 0.1f;

	// WASD + q = "up", e = down		y axis = up and down
	//									x axis = left and right
	//									z axis = forward and backward
	// 

	//float cameraSpeed = CAMERA_MOVE_SPEED_SLOW;
	//if ( glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS  )
	//{
	//	cameraSpeed = CAMERA_MOVE_SPEED_FAST;
	//}

	float cameraMoveSpeed = ::g_pFlyCamera->movementSpeed;
	//float cameraMoveSpeed = ::g_pCameraManager->getCurrentCamera()->getData("getMovementSpeed").x;



	// If no keys are down, move the camera
	if (areAllModifiersUp(window)) {
		// Note: The "== GLFW_PRESS" isn't really needed as it's actually "1" 
		// (so the if() treats the "1" as true...)


		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
			//			g_CameraEye.z += cameraSpeed;
			::g_pFlyCamera->MoveForward_Z(+cameraMoveSpeed);
			print_camera_position();
			sort_transparent_objects();
			//::g_pCameraManager->getCurrentCamera()->Update("MoveForward_Z", +cameraMoveSpeed);
		}
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)	// "backwards"
		{
			//			g_CameraEye.z -= cameraSpeed;
			::g_pFlyCamera->MoveForward_Z(-cameraMoveSpeed);
			print_camera_position();
			sort_transparent_objects();
			//::g_pCameraManager->getCurrentCamera()->Update("MoveForward_Z", -cameraMoveSpeed);
		}
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)	// "left"
		{
			//			g_CameraEye.x -= cameraSpeed;
			::g_pFlyCamera->MoveLeftRight_X(-cameraMoveSpeed);
			print_camera_position();
			sort_transparent_objects();
			//::g_pCameraManager->getCurrentCamera()->Update("MoveLeftRight_X", -cameraMoveSpeed);
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)	// "right"
		{
			//			g_CameraEye.x += cameraSpeed;
			::g_pFlyCamera->MoveLeftRight_X(+cameraMoveSpeed);
			print_camera_position();
			sort_transparent_objects();
			//::g_pCameraManager->getCurrentCamera()->Update("MoveLeftRight_X", +cameraMoveSpeed);
		}
		if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)	// "up"
		{
			//			::g_pFlyCamera->Roll_CW_CCW( +cameraSpeed );
			::g_pFlyCamera->MoveUpDown_Y(-cameraMoveSpeed);
			print_camera_position();
			sort_transparent_objects();
			//::g_pCameraManager->getCurrentCamera()->Update("MoveUpDown_Y", -cameraMoveSpeed);
		}
		if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)	// "down"
		{
			//			g_CameraEye.y -= cameraSpeed;
			//			::g_pFlyCamera->Roll_CW_CCW( -cameraSpeed );
			::g_pFlyCamera->MoveUpDown_Y(+cameraMoveSpeed);
			print_camera_position();
			sort_transparent_objects();
			//::g_pCameraManager->getCurrentCamera()->Update("MoveUpDown_Y", +cameraMoveSpeed);
		}
	}


	// Note: if the fly camera has bKeepCameraFacingUp = true, then this is ignored
	//if (isAltDown(window)) {
	if(isShiftDown(window)){
		if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)	// "up"
		{
			//			::g_pFlyCamera->MoveUpDown_Y( +cameraSpeed );
			::g_pFlyCamera->Roll_CW_CCW(-CAMERA_TURN_SPEED);
			//::g_pCameraManager->getCurrentCamera()->Update("Roll_CW_CCW", -CAMERA_TURN_SPEED);
		}
		if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)	// "down"
		{
			//			::g_pFlyCamera->MoveUpDown_Y( -cameraSpeed );
			::g_pFlyCamera->Roll_CW_CCW(+CAMERA_TURN_SPEED);
			//::g_pCameraManager->getCurrentCamera()->Update("Roll_CW_CCW", +CAMERA_TURN_SPEED);
		}
	}
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	//static constexpr float CAMERA_SPEED = 1.0f;
	static constexpr float MOVEMENT_SPEED = 0.05f;
	static constexpr float SCALE_FACTOR = 0.05f;
	static constexpr float ROTATION_DEGREE = 1.0f; // degree
	static constexpr float LIGHT_SPEED = 0.05f;
	static constexpr float LIGHT_ATTEN_CHANGE_RATE = 0.01f;
	static constexpr float LIGHT_COLOR_CHANGE_RATE = 0.01f;
	static constexpr float SKYBOX_BLENDING_RATE = 0.01f;
	//static constexpr int NO_MOD = 0;
	//// Camera keys: ADWSQE + Ctrl
	////	- AD are "right and left"
	////	- WS are "forward and back"
	////	- QE are "up and down"
	//if (key == GLFW_KEY_A && mods == GLFW_MOD_CONTROL) { // left
	//	::g_cameraEye.x -= CAMERA_SPEED;
	//	print_camera_position();
	//	sort_transparent_objects();
	//}
	//if (key == GLFW_KEY_D && mods == GLFW_MOD_CONTROL) { // right
	//	::g_cameraEye.x += CAMERA_SPEED;
	//	print_camera_position();
	//	sort_transparent_objects();
	//}
	//if (key == GLFW_KEY_W && mods == GLFW_MOD_CONTROL) { // forward
	//	::g_cameraEye.z += CAMERA_SPEED;
	//	print_camera_position();
	//	sort_transparent_objects();
	//}
	//if (key == GLFW_KEY_S && mods == GLFW_MOD_CONTROL) { // back
	//	::g_cameraEye.z -= CAMERA_SPEED;
	//	print_camera_position();
	//	sort_transparent_objects();
	//}
	//if (key == GLFW_KEY_Q && mods == GLFW_MOD_CONTROL) { // up
	//	::g_cameraEye.y += CAMERA_SPEED;
	//	print_camera_position();
	//	sort_transparent_objects();
	//}
	//if (key == GLFW_KEY_E && mods == GLFW_MOD_CONTROL) { // down
	//	::g_cameraEye.y -= CAMERA_SPEED;
	//	print_camera_position();
	//	sort_transparent_objects();
	//}

	// Change selected object: ',' and '.' keys
	if (key == GLFW_KEY_COMMA && mods == GLFW_MOD_CONTROL && action == GLFW_PRESS) {
		if (g_meshObjectIndex > 0) {
			--g_meshObjectIndex;
		}
		print_selected_mesh_object_information();
	}
	if (key == GLFW_KEY_PERIOD && mods == GLFW_MOD_CONTROL && action == GLFW_PRESS) {
		if (g_meshObjectIndex < g_vecPointerMeshObjects.size() - 1) {
			++g_meshObjectIndex;
		}
		print_selected_mesh_object_information();
	}

	// Moving object keys: ADWSQE + Ctrl
	//	- AD are "right and left"
	//	- WS are "forward and back"
	//	- RY are "up and down"
	if (key == GLFW_KEY_A && mods == GLFW_MOD_CONTROL) { // left
		g_vecPointerMeshObjects[g_meshObjectIndex]->pos.x -= MOVEMENT_SPEED;
		print_selected_mesh_object_information();
	}
	if (key == GLFW_KEY_D && mods == GLFW_MOD_CONTROL) { // right
		g_vecPointerMeshObjects[g_meshObjectIndex]->pos.x += MOVEMENT_SPEED;
		print_selected_mesh_object_information();
	}
	if (key == GLFW_KEY_W && mods == GLFW_MOD_CONTROL) { // forward
		g_vecPointerMeshObjects[g_meshObjectIndex]->pos.z += MOVEMENT_SPEED;
		print_selected_mesh_object_information();
	}
	if (key == GLFW_KEY_S && mods == GLFW_MOD_CONTROL) { // back
		g_vecPointerMeshObjects[g_meshObjectIndex]->pos.z -= MOVEMENT_SPEED;
		print_selected_mesh_object_information();
	}
	if (key == GLFW_KEY_Q && mods == GLFW_MOD_CONTROL) { // up
		g_vecPointerMeshObjects[g_meshObjectIndex]->pos.y += MOVEMENT_SPEED;
		print_selected_mesh_object_information();
	}
	if (key == GLFW_KEY_E && mods == GLFW_MOD_CONTROL) { // down
		g_vecPointerMeshObjects[g_meshObjectIndex]->pos.y -= MOVEMENT_SPEED;
		print_selected_mesh_object_information();
	}

	// '{' and '}' to scale object 
	if (key == GLFW_KEY_RIGHT_BRACKET && mods == GLFW_MOD_CONTROL) { // scale up (bigger)
		g_vecPointerMeshObjects[g_meshObjectIndex]->scale += SCALE_FACTOR;
		print_selected_mesh_object_information();
	}
	if (key == GLFW_KEY_LEFT_BRACKET && mods == GLFW_MOD_CONTROL) { // scale down (smaller)
		g_vecPointerMeshObjects[g_meshObjectIndex]->scale -= SCALE_FACTOR;
		print_selected_mesh_object_information();
	}

	// 'R' and 'T' to rotate object around x-axis
	if (key == GLFW_KEY_R && mods == GLFW_MOD_CONTROL) { // counter clockwise
		g_vecPointerMeshObjects[g_meshObjectIndex]->orientation.x += glm::radians(ROTATION_DEGREE);
		print_selected_mesh_object_information();
	}
	if (key == GLFW_KEY_T && mods == GLFW_MOD_CONTROL) { // clockwise
		g_vecPointerMeshObjects[g_meshObjectIndex]->orientation.x -= glm::radians(ROTATION_DEGREE);
		print_selected_mesh_object_information();
	}
	// 'F' and 'G' to rotate object around y-axis
	if (key == GLFW_KEY_F && mods == GLFW_MOD_CONTROL) { // counter clockwise
		g_vecPointerMeshObjects[g_meshObjectIndex]->orientation.y += glm::radians(ROTATION_DEGREE);
		print_selected_mesh_object_information();
	}
	if (key == GLFW_KEY_G && mods == GLFW_MOD_CONTROL) { // clockwise
		g_vecPointerMeshObjects[g_meshObjectIndex]->orientation.y -= glm::radians(ROTATION_DEGREE);
		print_selected_mesh_object_information();
	}
	// 'V' and 'B' to rotate object around z-axis
	if (key == GLFW_KEY_V && mods == GLFW_MOD_CONTROL) { // counter clockwise
		g_vecPointerMeshObjects[g_meshObjectIndex]->orientation.z += glm::radians(ROTATION_DEGREE);
		print_selected_mesh_object_information();
	}
	if (key == GLFW_KEY_B && mods == GLFW_MOD_CONTROL) { // clockwise
		g_vecPointerMeshObjects[g_meshObjectIndex]->orientation.z -= glm::radians(ROTATION_DEGREE);
		print_selected_mesh_object_information();
	}


	// Change drawing mode:
	//	- '9' key: wire frame mode
	//	- '0' key: solid frame mode
	if (key == GLFW_KEY_9 && action == GLFW_PRESS) {
		std::cout << "Switch to frame mode.\n";
		//::g_isWireFrame = true;
		g_vecPointerMeshObjects[g_meshObjectIndex]->isWireframe = true;
	}
	if (key == GLFW_KEY_0 && action == GLFW_PRESS) {
		std::cout << "Switch to solid mode.\n";
		//::g_isWireFrame = false;
		g_vecPointerMeshObjects[g_meshObjectIndex]->isWireframe = false;
	}

	// Move light keys: ADWSQE + Alt
	//	- AD are "right and left"
	//	- WS are "forward and back"
	//	- QE are "up and down"
	if (key == GLFW_KEY_A && mods == GLFW_MOD_ALT) { // left
		::g_pLightManager->vecLights[g_lightIndex].position.x -= LIGHT_SPEED;
		print_selected_light_information();
	}
	if (key == GLFW_KEY_D && mods == GLFW_MOD_ALT) { // right
		::g_pLightManager->vecLights[g_lightIndex].position.x += LIGHT_SPEED;
		print_selected_light_information();
	}
	if (key == GLFW_KEY_W && mods == GLFW_MOD_ALT) { // forward
		::g_pLightManager->vecLights[g_lightIndex].position.z += LIGHT_SPEED;
		print_selected_light_information();
	}
	if (key == GLFW_KEY_S && mods == GLFW_MOD_ALT) { // back
		::g_pLightManager->vecLights[g_lightIndex].position.z -= LIGHT_SPEED;
		print_selected_light_information();
	}
	if (key == GLFW_KEY_Q && mods == GLFW_MOD_ALT) { // up
		::g_pLightManager->vecLights[g_lightIndex].position.y += LIGHT_SPEED;
		print_selected_light_information();
	}
	if (key == GLFW_KEY_E && mods == GLFW_MOD_ALT) { // down
		::g_pLightManager->vecLights[g_lightIndex].position.y -= LIGHT_SPEED;
		print_selected_light_information();
	}

	// Change light color: ZXC + Alt
	//	- Z for red
	//	- X for green
	//	- C for blue
	if (key == GLFW_KEY_Z && mods == GLFW_MOD_ALT && action == GLFW_PRESS) { // red
		float &c = ::g_pLightManager->vecLights[g_lightIndex].diffuse.r;
		if (c == 1.0f) {
			c = 0.0f;
		}
		else {
			c += LIGHT_COLOR_CHANGE_RATE;
			if (c > 1.0f) {
				c = 1.0f;
			}
		}
		print_selected_light_information();
	}
	if (key == GLFW_KEY_X && mods == GLFW_MOD_ALT && action == GLFW_PRESS) { // green
		float &c = ::g_pLightManager->vecLights[g_lightIndex].diffuse.g;
		if (c == 1.0f) {
			c = 0.0f;
		}
		else {
			c += LIGHT_COLOR_CHANGE_RATE;
			if (c > 1.0f) {
				c = 1.0f;
			}
		}
		print_selected_light_information();
	}
	if (key == GLFW_KEY_C && mods == GLFW_MOD_ALT && action == GLFW_PRESS) { // blue
		float &c = ::g_pLightManager->vecLights[g_lightIndex].diffuse.b;
		if (c == 1.0f) {
			c = 0.0f;
		}
		else {
			c += LIGHT_COLOR_CHANGE_RATE;
			if (c > 1.0f) {
				c = 1.0f;
			}
		}
		print_selected_light_information();
	}

	// Change light attenuation: 1 2 3 4 5 6 + Alt
	//	- 1 2 + Alt for constant
	//	- 3 4 + Alt for linear
	//	- 5 6 + Alt for 
	if (key == GLFW_KEY_1 && mods == GLFW_MOD_ALT) {
		float &v = ::g_pLightManager->vecLights[g_lightIndex].atten.x;
		v *= (1 + LIGHT_ATTEN_CHANGE_RATE);
		print_selected_light_information();
	}
	if (key == GLFW_KEY_2 && mods == GLFW_MOD_ALT) {
		float &v = ::g_pLightManager->vecLights[g_lightIndex].atten.x;
		v *= (1 - LIGHT_ATTEN_CHANGE_RATE);
		print_selected_light_information();
	}
	if (key == GLFW_KEY_3 && mods == GLFW_MOD_ALT) {
		float &v = ::g_pLightManager->vecLights[g_lightIndex].atten.y;
		v *= (1 + LIGHT_ATTEN_CHANGE_RATE);
		print_selected_light_information();
	}
	if (key == GLFW_KEY_4 && mods == GLFW_MOD_ALT) {
		float &v = ::g_pLightManager->vecLights[g_lightIndex].atten.y;
		v *= (1 - LIGHT_ATTEN_CHANGE_RATE);
		print_selected_light_information();
	}
	if (key == GLFW_KEY_5 && mods == GLFW_MOD_ALT) {
		float &v = ::g_pLightManager->vecLights[g_lightIndex].atten.z;
		v *= (1 + LIGHT_ATTEN_CHANGE_RATE);
		print_selected_light_information();
	}
	if (key == GLFW_KEY_6 && mods == GLFW_MOD_ALT) {
		float &v = ::g_pLightManager->vecLights[g_lightIndex].atten.z;
		v *= (1 - LIGHT_ATTEN_CHANGE_RATE);
		print_selected_light_information();
	}

	// Change selected light: ',' or '.' + Alt keys
	if (key == GLFW_KEY_COMMA && mods == GLFW_MOD_ALT && action == GLFW_PRESS) {
		if (g_lightIndex > 0) {
			--g_lightIndex;
		}
		print_selected_light_information();
	}
	if (key == GLFW_KEY_PERIOD && mods == GLFW_MOD_ALT && action == GLFW_PRESS) {
		if (g_lightIndex < g_pLightManager->NUMBEROFLIGHTS - 1) {
			++g_lightIndex;
		}
		print_selected_light_information();
	}
	if (key == GLFW_KEY_SLASH && mods == GLFW_MOD_ALT && action == GLFW_PRESS) {
		float &t = ::g_pLightManager->vecLights[g_lightIndex].param1.x;
		if (t == 2.0f) {
			t = 0.0f;
		}
		else {
			t += 1.0f;
		}
		print_selected_light_information();
	}

	//// 'F1' and 'F2' to save and load the transformation information of mesh objects
	//if (key == GLFW_KEY_F1 && action == GLFW_PRESS) {
	//	if (save_settings_to_file(g_settingsFilePath)) {
	//		std::cout << "Saved settings to " << g_settingsFilePath << " successfully.\n";
	//	}
	//	else {
	//		std::cout << "Cannot save settings to " << g_settingsFilePath << '\n';
	//	}
	//}
	//if (key == GLFW_KEY_F2 && action == GLFW_PRESS) {
	//	if (load_settings_from_file(g_settingsFilePath)) {
	//		std::cout << "Loaded settings from " << g_settingsFilePath << " successfully.\n";
	//	}
	//	else {
	//		std::cout << "Cannot load settings from " << g_settingsFilePath << '\n';
	//	}
	//}

	// 'F3' to turn on/off the debug light
	if (key == GLFW_KEY_F3 && action == GLFW_PRESS) {
		::g_pDebugLightMeshObject->isVisible = !::g_pDebugLightMeshObject->isVisible;
		std::cout << "Turn " << (::g_pDebugLightMeshObject->isVisible ? "on" : "off") << " debug light balls\n";
	}

	//// 'F5' to turn on/off the transparancy mode
	//if (key == GLFW_KEY_F5 && action == GLFW_PRESS) {
	//	::g_bUseTransparenceMap = !::g_bUseTransparenceMap;
	//	std::cout << "Turn " << (::g_bUseTransparenceMap ? "on" : "off") << " transparence mapping\n";
	//}
	//// 'F6' to turn on/off the discard mode
	//if (key == GLFW_KEY_F6 && action == GLFW_PRESS) {
	//	::g_bUseDiscardMap = !::g_bUseDiscardMap;
	//	std::cout << "Turn " << (::g_bUseDiscardMap ? "on" : "off") << " discard mapping\n";
	//}


	//// 7, 8 for blending skybox 
	//if (key == GLFW_KEY_7) {
	//	cMeshObject *pObj = find_mesh_object_by_name("skybox");
	//	if (pObj != nullptr) {
	//		float &a = (pObj->textureRatios[0]);
	//		float &b = (pObj->textureRatios[1]);
	//		
	//		a += SKYBOX_BLENDING_RATE;
	//		b = (1.0f - a);
	//		if (a >= 1.0f) {
	//			a = 1.0f;
	//			b = 0.0f;
	//		}
	//		std::cout << "Skybox blending ratios:" << pObj->textureRatios[0] << ' ' << pObj->textureRatios[1] << '\n';
	//	}
	//}

	//if (key == GLFW_KEY_8) {
	//	cMeshObject *pObj = find_mesh_object_by_name("skybox");
	//	if (pObj != nullptr) {
	//		float &b = (pObj->textureRatios[0]);
	//		float &a = (pObj->textureRatios[1]);

	//		a += SKYBOX_BLENDING_RATE;
	//		b = (1.0f - a);
	//		if (a >= 1.0f) {
	//			a = 1.0f;
	//			b = 0.0f;
	//		}
	//		std::cout << "Skybox blending ratios:" << pObj->textureRatios[0] << ' ' << pObj->textureRatios[1] << '\n';
	//	}
	//}

	// Escape key: close the program
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

}