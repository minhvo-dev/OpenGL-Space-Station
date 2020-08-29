/*
 *	File name:	"load_models_into_VAO.cpp"
 *	Date:		8/27/2020 9:13:56 AM
 *	Author:		Vo, Dinh Tue Minh
 *	Purpose:
 */

#include "../headers/globalOpenGL.hpp"
#include "../headers/globalVariables.hpp"

#include "../vao_model_manager/cModelManager.hpp"

static const char *spaceInteriorTextureFileName = "SpaceInteriors_Texture.bmp";

static cModelManager* createLoadedModelManager() {
	cModelManager *p_manager = new cModelManager();
	//char const *g_debugLightModelFilePath = "assets/models/ISO_Shphere_flat_4div_xyz_n_rgba_uv.ply";
	p_manager->add_model("assets/models/ISO_Shphere_flat_4div_xyz_n_rgba_uv.ply", "debug_light");
	//char const *g_invertedSphereFilePath = "assets/models/ISO_Sphere_Smooth_inverted_normals_xyz_n_rgba_uv.ply";
	p_manager->add_model("assets/models/ISO_Sphere_Smooth_inverted_normals_xyz_n_rgba_uv.ply", "invert_sphere");
	//char const *g_tunnel_ceilingLightFileName = "assets/models/SM_Env_Ceiling_Light_02_xyz_n_rgba_uv.ply";
	p_manager->add_model("assets/models/SM_Env_Ceiling_Light_02_xyz_n_rgba_uv.ply", "env_ceiling_light_02");
	//char const *g_tunnel_doorFileName = "assets/models/SM_Env_Door_01_xyz_n_rgba_uv.ply";
	p_manager->add_model("assets/models/SM_Env_Door_01_xyz_n_rgba_uv.ply", "env_door_01");
	//char const *g_tunnel_floorFileName = "assets/models/SM_Env_Floor_04_xyz_n_rgba_uv.ply";
	p_manager->add_model("assets/models/SM_Env_Floor_04_xyz_n_rgba_uv.ply", "env_floor_04");
	//char const *g_tunnel_transitionDoorCurvedFileName = "assets/models/SM_Env_Transition_Door_Curved_01_xyz_n_rgba_uv.ply";
	p_manager->add_model("assets/models/SM_Env_Transition_Door_Curved_01_xyz_n_rgba_uv.ply", "env_transition_door_curved_01");
	//char const *g_tunnel_wallCurved[] = {
	//	"assets/models/SM_Env_Wall_Curved_01_xyz_n_rgba_uv.ply",
	//	"assets/models/SM_Env_Wall_Curved_02_xyz_n_rgba_uv.ply",
	//	"assets/models/SM_Env_Wall_Curved_03_xyz_n_rgba_uv.ply",
	//	"assets/models/SM_Env_Wall_Curved_04_xyz_n_rgba_uv.ply",
	//	"assets/models/SM_Env_Wall_Curved_05_xyz_n_rgba_uv.ply",
	//};
	p_manager->add_model("assets/models/SM_Env_Wall_Curved_01_xyz_n_rgba_uv.ply", "env_wall_curved_01");
	p_manager->add_model("assets/models/SM_Env_Wall_Curved_02_xyz_n_rgba_uv.ply", "env_wall_curved_02");
	p_manager->add_model("assets/models/SM_Env_Wall_Curved_03_xyz_n_rgba_uv.ply", "env_wall_curved_03");
	p_manager->add_model("assets/models/SM_Env_Wall_Curved_04_xyz_n_rgba_uv.ply", "env_wall_curved_04");
	p_manager->add_model("assets/models/SM_Env_Wall_Curved_05_xyz_n_rgba_uv.ply", "env_wall_curved_05");
	//char const *g_hangar_constructionWall_blank_FileName = "assets/models/SM_Env_Construction_Wall_01_xyz_n_rgba_uv.ply";
	p_manager->add_model("assets/models/SM_Env_Construction_Wall_01_xyz_n_rgba_uv.ply", "env_construction_wall_01");
	//char const *g_hangar_constructionWall_numbered_FileName = "assets/models/SM_Env_Construction_Wall_02_xyz_n_rgba_uv.ply";
	p_manager->add_model("assets/models/SM_Env_Construction_Wall_02_xyz_n_rgba_uv.ply", "env_construction_wall_02");
	//char const *g_hangar_floorFileName = "assets/models/SM_Env_Floor_01_xyz_n_rgba_uv.ply";
	p_manager->add_model("assets/models/SM_Env_Floor_01_xyz_n_rgba_uv.ply", "env_floor_01");
	//char const *g_prop_deskLab_01_FileName = "assets/models/SM_Prop_Desk_Lab_01_xyz_n_rgba_uv.ply";
	p_manager->add_model("assets/models/SM_Prop_Desk_Lab_01_xyz_n_rgba_uv.ply", "prop_desk_lab_01");
	//char const *g_prop_deskLab_02_FileName = "assets/models/SM_Prop_Desk_Lab_02_xyz_n_rgba_uv.ply";
	p_manager->add_model("assets/models/SM_Prop_Desk_Lab_02_xyz_n_rgba_uv.ply", "prop_desk_lab_02");
	//char const *g_prop_desk_01_FileName = "assets/models/SM_Prop_Desk_01_xyz_n_rgba_uv.ply";
	p_manager->add_model("assets/models/SM_Prop_Desk_01_xyz_n_rgba_uv.ply", "prop_desk_01");
	//char const *g_prop_desk_02_FileName = "assets/models/SM_Prop_Desk_02_xyz_n_rgba_uv.ply";
	p_manager->add_model("assets/models/SM_Prop_Desk_02_xyz_n_rgba_uv.ply", "prop_desk_02");
	//char const *g_prop_beaker_FileName = "assets/models/SM_Prop_Beaker_01_xyz_n_rgba_uv.ply";
	p_manager->add_model("assets/models/SM_Prop_Beaker_01_xyz_n_rgba_uv.ply", "prop_beaker_01");
	//char const *g_prop_cart_FileName = "assets/models/SM_Prop_Cart_01_xyz_n_rgba_uv.ply";
	p_manager->add_model("assets/models/SM_Prop_Cart_01_xyz_n_rgba_uv.ply", "prop_cart_01");
	//char const *g_prop_lockers_01_FileName = "assets/models/SM_Prop_Lockers_01_xyz_n_rgba_uv.ply";
	//char const *g_prop_lockers_04_FileName = "assets/models/SM_Prop_Lockers_04_xyz_n_rgba_uv.ply";
	//char const *g_prop_lockers_05_FileName = "assets/models/SM_Prop_Lockers_05_xyz_n_rgba_uv.ply";
	p_manager->add_model("assets/models/SM_Prop_Lockers_01_xyz_n_rgba_uv.ply", "prop_lockers_01");
	p_manager->add_model("assets/models/SM_Prop_Lockers_04_xyz_n_rgba_uv.ply", "prop_lockers_04");
	p_manager->add_model("assets/models/SM_Prop_Lockers_05_xyz_n_rgba_uv.ply", "prop_lockers_05");
	//char const *g_prop_plans_02_FileName = "assets/models/SM_Prop_Plants_02_xyz_n_rgba_uv.ply";
	p_manager->add_model("assets/models/SM_Prop_Plants_05_xyz_n_rgba_uv.ply", "prop_plants_05");
	p_manager->add_model("assets/models/SM_Prop_Plants_06_xyz_n_rgba_uv.ply", "prop_plants_06");
	//char const *g_prop_phone_FileName = "assets/models/SM_Prop_Phone_01_xyz_n_rgba_uv.ply";
	p_manager->add_model("assets/models/SM_Prop_Phone_01_xyz_n_rgba_uv.ply", "prop_phone_01");
	//char const *g_prop_scales_FileName = "assets/models/SM_Prop_Scales_01_xyz_n_rgba_uv.ply";
	p_manager->add_model("assets/models/SM_Prop_Scales_01_xyz_n_rgba_uv.ply", "prop_scales_01");
	//char const *g_prop_sign_FileName = "assets/models/SM_Prop_Sign_01_xyz_n_rgba_uv.ply";
	p_manager->add_model("assets/models/SM_Prop_Sign_01_xyz_n_rgba_uv.ply", "prop_sign_01");


	// SM_Env_Window_End_xyz_n_rgba_uv.ply
	p_manager->add_model("assets/models/SM_Env_Window_End_xyz_n_rgba_uv.ply", "env_window_end");
	// SM_Env_ControlRoom_Window_01_xyz_n_rgba_uv.ply
	p_manager->add_model("assets/models/SM_Env_ControlRoom_Window_01_xyz_n_rgba_uv_x2x.ply", "env_control_room_window_01");
	// SM_Prop_StepLadder_01_xyz_n_rgba_uv.ply
	p_manager->add_model("assets/models/SM_Prop_StepLadder_01_xyz_n_rgba_uv.ply", "prop_step_ladder_01");
	// SM_Prop_ControlDesk_01_xyz_n_rgba_uv.ply
	p_manager->add_model("assets/models/SM_Prop_ControlDesk_01_xyz_n_rgba_uv.ply", "prop_control_desk_01");
	// SM_Prop_ControlDesk_Vintage_01_xyz_n_rgba_uv.ply
	p_manager->add_model("assets/models/SM_Prop_ControlDesk_Vintage_01_xyz_n_rgba_uv.ply", "prop_control_desk_vintage_01");
	// X-Wing_Attack_xyz_n_rgba_uv.ply
	p_manager->add_model("assets/models/X-Wing_Attack_xyz_n_rgba_uv.ply", "x-wing");

	return p_manager;
}

void load_models_into_VAO(GLuint program) {
	// ***************************************************
	// STARTOF: Loading the models/lightball/skybox
	// ***************************************************
	::g_pModelManager = createLoadedModelManager();
	::g_pVAOManager = new cVAOManager();
	for (auto it = ::g_pModelManager->get_manager().begin(); it != ::g_pModelManager->get_manager().end(); ++it) {
		std::string const &name = it->first;
		std::string const &path = it->second;
		if (::g_pVAOManager->load_model_into_VAO(path, program)) {
			std::cout << "Loaded model: " << path << " as '" << name << "'\n";
		}
	}
	// ***************************************************
	// ENDOF: Loading the models
	// ***************************************************
}

static void set_up_entrance() {
	// tunnel
	{
		constexpr unsigned NUM_OF_SECTIONS = 4;
		glm::vec3 start = glm::vec3(-5.0f, 0.0f, 2.5f);

		for (unsigned int i = 0; i < NUM_OF_SECTIONS; ++i) {
			{
				// floor
				cMeshObject *pMeshObj = new cMeshObject();
				pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_floor_04");
				pMeshObj->pos = glm::vec3(start.x, start.y, start.z + i * 5.0f); // 5.0f is the size of the floor
				pMeshObj->scale = 1.0f;
				pMeshObj->orientation.y = glm::radians(90.0f);
				//pMeshObj->isWireframe = true;
				pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
				pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);

				pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
				pMeshObj->textureRatios[0] = 1.0f;

				::g_vecPointerMeshObjects.push_back(pMeshObj);
			}
			{
				// ceiling
				cMeshObject *pMeshObj = new cMeshObject();
				pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_floor_04");
				pMeshObj->pos = glm::vec3(start.x, start.y + 5.0f, start.z + i * 5.0f); // 5.0f is the size of the floor
				pMeshObj->scale = 1.0f;
				pMeshObj->orientation.y = glm::radians(90.0f);
				//pMeshObj->isWireframe = true;
				pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
				pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);

				pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
				pMeshObj->textureRatios[0] = 1.0f;

				::g_vecPointerMeshObjects.push_back(pMeshObj);
			}
			{
				// ceiling light
				cMeshObject *pMeshObj = new cMeshObject();
				//pMeshObj->meshName = ::g_tunnel_ceilingLightFileName;
				pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_ceiling_light_02");
				pMeshObj->pos = glm::vec3(start.x / 2.0f, start.y + 5.0f, start.z + 2.5f + i * 5.0f); // 5.0f is the size of the floor
				pMeshObj->scale = 1.0f;
				pMeshObj->orientation.y = glm::radians(90.0f);
				//pMeshObj->isWireframe = true;
				pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
				pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);

				pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
				pMeshObj->textureRatios[0] = 1.0f;

				::g_vecPointerMeshObjects.push_back(pMeshObj);
			}
		}
		// customized left and right walls
		{
			// section 0
			{
				// right wall
				cMeshObject *pMeshObj = new cMeshObject();
				//pMeshObj->meshName = ::g_tunnel_wallCurved[0];
				pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_wall_curved_01");
				pMeshObj->pos = start;
				pMeshObj->scale = 1.0f;
				pMeshObj->orientation.y = glm::radians(90.0f);
				//pMeshObj->isWireframe = true;
				pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
				pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);

				pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
				pMeshObj->textureRatios[0] = 1.0f;

				::g_vecPointerMeshObjects.push_back(pMeshObj);
			}
			{
				// left wall
				cMeshObject *pMeshObj = new cMeshObject();
				//pMeshObj->meshName = ::g_tunnel_wallCurved[4];
				pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_wall_curved_05");
				//pMeshObj->pos = glm::vec3(0.0f, 0.0f, 5.0f);
				// glm::vec3(-5.0f, 0.0f, 0.0f)
				pMeshObj->pos = glm::vec3(start.x + 5.0f, start.y, start.z + 5.0f);
				pMeshObj->scale = 1.0f;
				pMeshObj->orientation.y = glm::radians(-90.0f);
				//pMeshObj->isWireframe = true;
				pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
				pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);

				pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
				pMeshObj->textureRatios[0] = 1.0f;

				::g_vecPointerMeshObjects.push_back(pMeshObj);
			}
		}
		{
			// section 1
			{
				// right wall
				cMeshObject *pMeshObj = new cMeshObject();
				//pMeshObj->meshName = ::g_tunnel_wallCurved[1];
				pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_wall_curved_02");
				//pMeshObj->pos = glm::vec3(-5.0f, 0.0f, 5.0f);
				// glm::vec3(-5.0f, 0.0f, 0.0f)
				pMeshObj->pos = glm::vec3(start.x, start.y, start.z + 5.0f);
				pMeshObj->scale = 1.0f;
				pMeshObj->orientation.y = glm::radians(90.0f);
				//pMeshObj->isWireframe = true;
				pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
				pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);

				pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
				pMeshObj->textureRatios[0] = 1.0f;

				::g_vecPointerMeshObjects.push_back(pMeshObj);
			}
			{
				// left wall
				cMeshObject *pMeshObj = new cMeshObject();
				//pMeshObj->meshName = ::g_tunnel_wallCurved[2];
				pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_wall_curved_03");
				//pMeshObj->pos = glm::vec3(0.0f, 0.0f, 10.0f);
				// glm::vec3(-5.0f, 0.0f, 0.0f)
				//pMeshObj->pos = glm::vec3(0.0f, 0.0f, 10.0f);
				pMeshObj->pos = glm::vec3(start.x + 5.0f, start.y, start.z + 10.0f);
				pMeshObj->scale = 1.0f;
				pMeshObj->orientation.y = glm::radians(-90.0f);
				//pMeshObj->isWireframe = true;
				pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
				pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);

				pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
				pMeshObj->textureRatios[0] = 1.0f;

				::g_vecPointerMeshObjects.push_back(pMeshObj);
			}
		}
		{
			// section 2
			{
				// right wall
				cMeshObject *pMeshObj = new cMeshObject();
				//pMeshObj->meshName = ::g_tunnel_wallCurved[3];
				pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_wall_curved_04");
				//pMeshObj->pos = glm::vec3(-5.0f, 0.0f, 10.0f);
				// glm::vec3(-5.0f, 0.0f, 0.0f)
				pMeshObj->pos = glm::vec3(start.x, start.y, start.z + 10.0f);
				pMeshObj->scale = 1.0f;
				pMeshObj->orientation.y = glm::radians(90.0f);
				//pMeshObj->isWireframe = true;
				pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
				pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);

				pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
				pMeshObj->textureRatios[0] = 1.0f;

				::g_vecPointerMeshObjects.push_back(pMeshObj);
			}
			{
				// left wall
				cMeshObject *pMeshObj = new cMeshObject();
				//pMeshObj->meshName = ::g_tunnel_wallCurved[0];
				pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_wall_curved_01");
				//pMeshObj->pos = glm::vec3(0.0f, 0.0f, 15.0f);
				// glm::vec3(-5.0f, 0.0f, 0.0f)
				pMeshObj->pos = glm::vec3(start.x + 5.0f, start.y, start.z + 15.0f);
				pMeshObj->scale = 1.0f;
				pMeshObj->orientation.y = glm::radians(-90.0f);
				//pMeshObj->isWireframe = true;
				pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
				pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);

				pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
				pMeshObj->textureRatios[0] = 1.0f;

				::g_vecPointerMeshObjects.push_back(pMeshObj);
			}
		}
		{
			// section 3
			{
				// right wall
				cMeshObject *pMeshObj = new cMeshObject();
				//pMeshObj->meshName = ::g_tunnel_wallCurved[1];
				pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_wall_curved_02");
				//pMeshObj->pos = glm::vec3(-5.0f, 0.0f, 15.0f);
				// glm::vec3(-5.0f, 0.0f, 0.0f)
				pMeshObj->pos = glm::vec3(start.x, start.y, start.z + 15.0f);
				pMeshObj->scale = 1.0f;
				pMeshObj->orientation.y = glm::radians(90.0f);
				//pMeshObj->isWireframe = true;
				pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
				pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);

				pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
				pMeshObj->textureRatios[0] = 1.0f;

				::g_vecPointerMeshObjects.push_back(pMeshObj);
			}
			{
				// left wall
				cMeshObject *pMeshObj = new cMeshObject();
				//pMeshObj->meshName = ::g_tunnel_wallCurved[2];
				pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_wall_curved_03");
				//pMeshObj->pos = glm::vec3(0.0f, 0.0f, 20.0f);
				// glm::vec3(-5.0f, 0.0f, 0.0f)
				pMeshObj->pos = glm::vec3(start.x + 5.0f, start.y, start.z + 20.0f);
				pMeshObj->scale = 1.0f;
				pMeshObj->orientation.y = glm::radians(-90.0f);
				//pMeshObj->isWireframe = true;
				pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
				pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);

				pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
				pMeshObj->textureRatios[0] = 1.0f;

				::g_vecPointerMeshObjects.push_back(pMeshObj);
			}
		}
		{
			// entrance window
			{
				cMeshObject *pMeshObj = new cMeshObject();
				pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_window_end");
				pMeshObj->pos = glm::vec3(start.x + 5.0f, start.y, start.z);
				pMeshObj->scale = 1.0f;
				//pMeshObj->isWireframe = true;
				pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
				pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
				::g_vecPointerMeshObjects.push_back(pMeshObj);

				pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
				pMeshObj->textureRatios[0] = 1.0f;
			}
		}
		{
			// transition door curved
			cMeshObject *pMeshObj = new cMeshObject();
			//pMeshObj->meshName = ::g_tunnel_transitionDoorCurvedFileName;
			pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_transition_door_curved_01");
			pMeshObj->pos = glm::vec3(0.0f, 0.0f, 25.0f);
			pMeshObj->scale = 1.0f;
			pMeshObj->orientation.y = glm::radians(180.0f);
			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;

			::g_vecPointerMeshObjects.push_back(pMeshObj);
		}
	}
}

static void set_up_hangar() {
	// hangar
	{
		// floor 8x12
		{
			glm::vec3 seed = glm::vec3(20.0f, 0.0f, 22.5f);
			for (int i = 0; i < 8; ++i) {
				glm::vec3 start = glm::vec3(seed.x, seed.y, seed.z + 5.0f * i);
				for (int j = 0; j < 12; ++j) {
					cMeshObject *pMeshObj = new cMeshObject();
					//pMeshObj->meshName = ::g_hangar_floorFileName;
					pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_floor_01");
					pMeshObj->pos = glm::vec3(start.x - 5.0 * j, start.y, start.z);
					pMeshObj->scale = 1.0f;

					//pMeshObj->isWireframe = true;
					pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
					pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
					pMeshObj->friendlyName = "";
					::g_vecPointerMeshObjects.push_back(pMeshObj);

					pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
					pMeshObj->textureRatios[0] = 1.0f;
				}
			}
		}
		// ceiling 8x12
		{
			glm::vec3 seed = glm::vec3(20.0f, 25.0f, 22.5f);
			for (int i = 0; i < 8; ++i) {
				glm::vec3 start = glm::vec3(seed.x, seed.y, seed.z + 5.0f * i);
				for (int j = 0; j < 12; ++j) {
					cMeshObject *pMeshObj = new cMeshObject();
					//pMeshObj->meshName = ::g_hangar_floorFileName;
					pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_floor_01");
					pMeshObj->pos = glm::vec3(start.x - 5.0 * j, start.y, start.z);
					pMeshObj->scale = 1.0f;

					//pMeshObj->isWireframe = true;
					pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
					pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
					pMeshObj->friendlyName = "";
					::g_vecPointerMeshObjects.push_back(pMeshObj);

					pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
					pMeshObj->textureRatios[0] = 1.0f;
				}
			}
		}
		// wall 
		{
			// front 5x6 (5 height)
			{
				glm::vec3 seed = glm::vec3(20.0f, 0.0f, 22.5f + 40.0f);
				for (int i = 0; i < 5; ++i) {
					glm::vec3 start = glm::vec3(seed.x, seed.y + 5.0f * i, seed.z);
					for (int j = 0; j < 6; ++j) {
						// front wall
						cMeshObject *pMeshObj = new cMeshObject();
						//pMeshObj->meshName = ::g_hangar_constructionWall_blank_FileName;
						pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_construction_wall_01");
						pMeshObj->pos = glm::vec3(start.x - 10.0 * j, start.y, start.z);
						pMeshObj->scale = 1.0f;
						pMeshObj->orientation.y = glm::radians(180.0f);
						//pMeshObj->isWireframe = true;
						pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
						pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);

						pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
						pMeshObj->textureRatios[0] = 1.0f;

						::g_vecPointerMeshObjects.push_back(pMeshObj);

						if (i == 2 && j == 3) {
							//pMeshObj->meshName = ::g_hangar_constructionWall_numbered_FileName;
							pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_construction_wall_02");
						}

						if (i % 2 == 1) {
							pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_control_room_window_01");
							pMeshObj->diffuseRGBA.a = 0.5f;
							pMeshObj->orientation.y = 0.0f;
						}
					}
				}
			}
			// back 5x6 (5 height)
			{
				glm::vec3 seed = glm::vec3(10.0f, 0.0f, 22.5f);
				for (int i = 0; i < 5; ++i) {
					glm::vec3 start = glm::vec3(seed.x, seed.y + 5.0f * i, seed.z);
					for (int j = 0; j < 6; ++j) {
						// front wall
						cMeshObject *pMeshObj = new cMeshObject();
						//pMeshObj->meshName = ::g_hangar_constructionWall_blank_FileName;
						pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_construction_wall_01");
						pMeshObj->pos = glm::vec3(start.x - 10.0 * j, start.y, start.z);
						pMeshObj->scale = 1.0f;

						//pMeshObj->isWireframe = true;
						pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
						pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
						pMeshObj->friendlyName = "";
						::g_vecPointerMeshObjects.push_back(pMeshObj);

						pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
						pMeshObj->textureRatios[0] = 1.0f;

						if (i == 2 && j == 3) {
							//pMeshObj->meshName = ::g_hangar_constructionWall_numbered_FileName;
							pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_construction_wall_02");
						}
						if (i == 0 && j == 2) {
							pMeshObj->pos.x -= 5.0f;
							
						}
						if (i % 2 == 1) {
							pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_control_room_window_01");
							pMeshObj->diffuseRGBA.a = 0.5f;
							pMeshObj->orientation.y = glm::radians(180.0f);
						}
					}
				}
			}
			// left 5x4 (5 height)
			{
				glm::vec3 seed = glm::vec3(20.0f, 0.0f, 22.5f);
				for (int i = 0; i < 5; ++i) {
					glm::vec3 start = glm::vec3(seed.x, seed.y + 5.0f * i, seed.z);
					for (int j = 0; j < 4; ++j) {
						// front wall
						cMeshObject *pMeshObj = new cMeshObject();
						//pMeshObj->meshName = ::g_hangar_constructionWall_blank_FileName;
						pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_construction_wall_01");

						pMeshObj->pos = glm::vec3(start.x, start.y, start.z + j * 10.0f);
						pMeshObj->scale = 1.0f;
						pMeshObj->orientation.y = glm::radians(-90.0f);
						//pMeshObj->isWireframe = true;
						pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
						pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
						pMeshObj->friendlyName = "";
						::g_vecPointerMeshObjects.push_back(pMeshObj);

						pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
						pMeshObj->textureRatios[0] = 1.0f;

						if (i == 2 && j == 2) {
							//pMeshObj->meshName = ::g_hangar_constructionWall_numbered_FileName;
							pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_construction_wall_02");
						}

						if (i % 2 == 1) {
							pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_control_room_window_01");
							pMeshObj->diffuseRGBA.a = 0.5f;
							pMeshObj->orientation.y = glm::radians(90.0f);
						}
					}
				}
			}
			// right 5x4 (5 height)
			{
				glm::vec3 seed = glm::vec3(-40.0f, 0.0f, 32.5f);
				for (int i = 0; i < 5; ++i) {
					glm::vec3 start = glm::vec3(seed.x, seed.y + 5.0f * i, seed.z);
					for (int j = 0; j < 4; ++j) {
						// front wall
						cMeshObject *pMeshObj = new cMeshObject();
						//pMeshObj->meshName = ::g_hangar_constructionWall_blank_FileName;
						pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_construction_wall_01");

						pMeshObj->pos = glm::vec3(start.x, start.y, start.z + j * 10.0f);
						pMeshObj->scale = 1.0f;
						pMeshObj->orientation.y = glm::radians(90.0f);
						//pMeshObj->isWireframe = true;
						pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
						pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
						pMeshObj->friendlyName = "";
						::g_vecPointerMeshObjects.push_back(pMeshObj);

						pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
						pMeshObj->textureRatios[0] = 1.0f;

						if (i == 2 && j == 2) {
							//pMeshObj->meshName = ::g_hangar_constructionWall_numbered_FileName;
							pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_construction_wall_02");
						}

						if (i % 2 == 1) {
							pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_control_room_window_01");
							pMeshObj->diffuseRGBA.a = 0.5f;
							pMeshObj->orientation.y = glm::radians(-90.0f);
						}
					}
				}
			}
		}
		// ceiling lights
		{
			{
				cMeshObject *pMeshObj = new cMeshObject();
				//pMeshObj->meshName = ::g_tunnel_ceilingLightFileName;
				pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_ceiling_light_02");
				pMeshObj->pos = glm::vec3(7.0f, 25.0f, 32.5f);
				pMeshObj->scale = 1.0f;
				pMeshObj->orientation.y = glm::radians(90.0f);
				//pMeshObj->isWireframe = true;
				pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
				pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
				pMeshObj->friendlyName = "";
				::g_vecPointerMeshObjects.push_back(pMeshObj);

				pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
				pMeshObj->textureRatios[0] = 1.0f;
			}
			{
				cMeshObject *pMeshObj = new cMeshObject();
				//pMeshObj->meshName = ::g_tunnel_ceilingLightFileName;
				pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_ceiling_light_02");
				pMeshObj->pos = glm::vec3(7.0f, 25.0f, 52.5f);
				pMeshObj->scale = 1.0f;
				pMeshObj->orientation.y = glm::radians(90.0f);
				//pMeshObj->isWireframe = true;
				pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
				pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
				pMeshObj->friendlyName = "";
				::g_vecPointerMeshObjects.push_back(pMeshObj);

				pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
				pMeshObj->textureRatios[0] = 1.0f;
			}
			{
				cMeshObject *pMeshObj = new cMeshObject();
				//pMeshObj->meshName = ::g_tunnel_ceilingLightFileName;
				pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_ceiling_light_02");
				pMeshObj->pos = glm::vec3(-10.0f, 25.0f, 32.5f);
				pMeshObj->scale = 1.0f;
				pMeshObj->orientation.y = glm::radians(90.0f);
				//pMeshObj->isWireframe = true;
				pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
				pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
				pMeshObj->friendlyName = "";
				::g_vecPointerMeshObjects.push_back(pMeshObj);

				pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
				pMeshObj->textureRatios[0] = 1.0f;
			}
			{
				cMeshObject *pMeshObj = new cMeshObject();
				//pMeshObj->meshName = ::g_tunnel_ceilingLightFileName;
				pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_ceiling_light_02");
				pMeshObj->pos = glm::vec3(-10.0f, 25.0f, 52.5f);
				pMeshObj->scale = 1.0f;
				pMeshObj->orientation.y = glm::radians(90.0f);
				//pMeshObj->isWireframe = true;
				pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
				pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
				pMeshObj->friendlyName = "";
				::g_vecPointerMeshObjects.push_back(pMeshObj);

				pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
				pMeshObj->textureRatios[0] = 1.0f;
			}
			{
				cMeshObject *pMeshObj = new cMeshObject();
				//pMeshObj->meshName = ::g_tunnel_ceilingLightFileName;
				pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_ceiling_light_02");
				pMeshObj->pos = glm::vec3(-27.0f, 25.0f, 32.5f);
				pMeshObj->scale = 1.0f;
				pMeshObj->orientation.y = glm::radians(90.0f);
				//pMeshObj->isWireframe = true;
				pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
				pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
				pMeshObj->friendlyName = "";
				::g_vecPointerMeshObjects.push_back(pMeshObj);

				pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
				pMeshObj->textureRatios[0] = 1.0f;
			}
			{
				cMeshObject *pMeshObj = new cMeshObject();
				//pMeshObj->meshName = ::g_tunnel_ceilingLightFileName;
				pMeshObj->meshName = ::g_pModelManager->find_model_by_name("env_ceiling_light_02");
				pMeshObj->pos = glm::vec3(-27.0f, 25.0f, 52.5f);
				pMeshObj->scale = 1.0f;
				pMeshObj->orientation.y = glm::radians(90.0f);
				//pMeshObj->isWireframe = true;
				pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
				pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
				pMeshObj->friendlyName = "";
				::g_vecPointerMeshObjects.push_back(pMeshObj);

				pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
				pMeshObj->textureRatios[0] = 1.0f;
			}
		}
	}
}

static void set_up_hangar_properties() {
	// properties
	{
		{
			// step ladder at the entrance
			cMeshObject *pMeshObj = new cMeshObject();
			pMeshObj->meshName = ::g_pModelManager->find_model_by_name("prop_step_ladder_01");
			pMeshObj->pos = glm::vec3(-1.85f, 0.0f, 25.6f);
			pMeshObj->scale = 1.0f;
			pMeshObj->orientation.y = glm::radians(0.0f);
			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
			pMeshObj->friendlyName = "step_ladder_01";
			::g_vecPointerMeshObjects.push_back(pMeshObj);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;
		}
		{
			// step ladder at the entrance
			cMeshObject *pMeshObj = new cMeshObject();
			pMeshObj->meshName = ::g_pModelManager->find_model_by_name("prop_step_ladder_01");
			pMeshObj->pos = glm::vec3(-3.15f, 0.0f, 25.6f);
			pMeshObj->scale = 1.0f;
			pMeshObj->orientation.y = glm::radians(0.0f);
			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
			pMeshObj->friendlyName = "step_ladder_02";
			::g_vecPointerMeshObjects.push_back(pMeshObj);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;
		}
		{
			cMeshObject *pMeshObj = new cMeshObject();
			//pMeshObj->meshName = ::g_prop_deskLab_01_FileName;
			pMeshObj->meshName = ::g_pModelManager->find_model_by_name("prop_desk_lab_01");
			pMeshObj->pos = glm::vec3(10.0f, 0.0f, 35.0f);
			pMeshObj->scale = 1.0f;
			pMeshObj->orientation.y = glm::radians(-90.0f);
			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
			pMeshObj->friendlyName = "desk_lab_1";
			::g_vecPointerMeshObjects.push_back(pMeshObj);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;
		}

		{
			cMeshObject *pMeshObj = new cMeshObject();
			//pMeshObj->meshName = ::g_prop_deskLab_02_FileName;
			pMeshObj->meshName = ::g_pModelManager->find_model_by_name("prop_desk_lab_02");
			pMeshObj->pos = glm::vec3(10.0f, 0.0f, 52.5f);
			pMeshObj->scale = 1.0f;
			pMeshObj->orientation.y = glm::radians(-90.0f);
			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
			pMeshObj->friendlyName = "desk_lab_2";
			::g_vecPointerMeshObjects.push_back(pMeshObj);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;
		}

		{
			cMeshObject *pMeshObj = new cMeshObject();
			//pMeshObj->meshName = ::g_prop_desk_01_FileName;
			pMeshObj->meshName = ::g_pModelManager->find_model_by_name("prop_desk_01");
			pMeshObj->pos = glm::vec3(8.0f, 0.0f, 31.5f);
			pMeshObj->scale = 1.0f;

			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
			pMeshObj->friendlyName = "desk_1";
			::g_vecPointerMeshObjects.push_back(pMeshObj);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;
		}

		{
			cMeshObject *pMeshObj = new cMeshObject();
			//pMeshObj->meshName = ::g_prop_desk_02_FileName;
			pMeshObj->meshName = ::g_pModelManager->find_model_by_name("prop_desk_02");
			pMeshObj->pos = glm::vec3(9.0f, 0.0f, 55.8f);
			pMeshObj->scale = 1.0f;

			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
			pMeshObj->friendlyName = "desk_2";
			::g_vecPointerMeshObjects.push_back(pMeshObj);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;
		}

		{
			cMeshObject *pMeshObj = new cMeshObject();
			//pMeshObj->meshName = ::g_prop_beaker_FileName;
			pMeshObj->meshName = ::g_pModelManager->find_model_by_name("prop_beaker_01");
			pMeshObj->pos = glm::vec3(9.0f, 1.56f, 32.0f);
			pMeshObj->scale = 1.0f;

			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 0.7f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
			pMeshObj->friendlyName = "beaker_1";
			::g_vecPointerMeshObjects.push_back(pMeshObj);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;
		}
		{
			cMeshObject *pMeshObj = new cMeshObject();
			//pMeshObj->meshName = ::g_prop_beaker_FileName;
			pMeshObj->meshName = ::g_pModelManager->find_model_by_name("prop_beaker_01");
			pMeshObj->pos = glm::vec3(8.5f, 1.56f, 31.5f);
			pMeshObj->scale = 1.0f;

			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 0.6f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
			pMeshObj->friendlyName = "beaker_2";
			::g_vecPointerMeshObjects.push_back(pMeshObj);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;
		}
		{
			cMeshObject *pMeshObj = new cMeshObject();
			//pMeshObj->meshName = ::g_prop_beaker_FileName;
			pMeshObj->meshName = ::g_pModelManager->find_model_by_name("prop_beaker_01");
			pMeshObj->pos = glm::vec3(6.8f, 1.76f, 31.5f);
			pMeshObj->scale = 1.0f;
			pMeshObj->orientation.x = glm::radians(100.0f);

			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 0.5f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
			pMeshObj->friendlyName = "beaker_3";
			::g_vecPointerMeshObjects.push_back(pMeshObj);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;
		}
		{
			cMeshObject *pMeshObj = new cMeshObject();
			//pMeshObj->meshName = ::g_prop_beaker_FileName;
			pMeshObj->meshName = ::g_pModelManager->find_model_by_name("prop_beaker_01");
			pMeshObj->pos = glm::vec3(8.5f, 1.56f, 32.3f);
			pMeshObj->scale = 1.0f;
			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 0.4f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
			pMeshObj->friendlyName = "beaker_4";
			::g_vecPointerMeshObjects.push_back(pMeshObj);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;
		}
	}
	// random properties
	{
		{
			cMeshObject *pMeshObj = new cMeshObject();
			//pMeshObj->meshName = ::g_prop_cart_FileName;
			pMeshObj->meshName = ::g_pModelManager->find_model_by_name("prop_cart_01");
			pMeshObj->pos = glm::vec3(4.2f, 0.0f, 55.4f);
			pMeshObj->scale = 1.0f;
			pMeshObj->orientation.y = glm::radians(120.0f);
			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
			pMeshObj->friendlyName = "cart";
			::g_vecPointerMeshObjects.push_back(pMeshObj);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;
		}
		{
			cMeshObject *pMeshObj = new cMeshObject();
			//pMeshObj->meshName = ::g_prop_lockers_01_FileName;
			pMeshObj->meshName = ::g_pModelManager->find_model_by_name("prop_lockers_01");
			pMeshObj->pos = glm::vec3(-39.0f, 0.0f, 55.4f);
			pMeshObj->scale = 1.0f;
			pMeshObj->orientation.y = glm::radians(90.0f);
			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
			pMeshObj->friendlyName = "lockers_1";
			::g_vecPointerMeshObjects.push_back(pMeshObj);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;
		}
		{
			cMeshObject *pMeshObj = new cMeshObject();
			//pMeshObj->meshName = ::g_prop_lockers_04_FileName;
			pMeshObj->meshName = ::g_pModelManager->find_model_by_name("prop_lockers_04");
			pMeshObj->pos = glm::vec3(-39.0f, 0.0f, 53.7f);
			pMeshObj->scale = 1.0f;
			pMeshObj->orientation.y = glm::radians(90.0f);
			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
			pMeshObj->friendlyName = "lockers_4";
			::g_vecPointerMeshObjects.push_back(pMeshObj);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;
		}
		{
			cMeshObject *pMeshObj = new cMeshObject();
			//pMeshObj->meshName = ::g_prop_lockers_05_FileName;
			pMeshObj->meshName = ::g_pModelManager->find_model_by_name("prop_lockers_05");
			pMeshObj->pos = glm::vec3(-39.0f, 0.0f, 52.0f);
			pMeshObj->scale = 1.0f;
			pMeshObj->orientation.y = glm::radians(90.0f);
			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
			pMeshObj->friendlyName = "lockers_5";
			::g_vecPointerMeshObjects.push_back(pMeshObj);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;
		}
		{
			cMeshObject *pMeshObj = new cMeshObject();
			//pMeshObj->meshName = ::g_prop_plans_02_FileName;
			pMeshObj->meshName = ::g_pModelManager->find_model_by_name("prop_plants_05");
			pMeshObj->pos = glm::vec3(-5.05f, 0.0f, 24.5f);
			pMeshObj->scale = 1.0f;
			pMeshObj->orientation.y = glm::radians(0.0f);
			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
			pMeshObj->friendlyName = "plans_5";
			::g_vecPointerMeshObjects.push_back(pMeshObj);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;
		}
		{
			cMeshObject *pMeshObj = new cMeshObject();
			//pMeshObj->meshName = ::g_prop_plans_02_FileName;
			pMeshObj->meshName = ::g_pModelManager->find_model_by_name("prop_plants_06");
			pMeshObj->pos = glm::vec3(4.95f, 0.0f, 24.5f);
			pMeshObj->scale = 1.0f;
			pMeshObj->orientation.y = glm::radians(0.0f);
			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
			pMeshObj->friendlyName = "plans_6";
			::g_vecPointerMeshObjects.push_back(pMeshObj);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;
		}
		{
			cMeshObject *pMeshObj = new cMeshObject();
			//pMeshObj->meshName = ::g_prop_phone_FileName;
			pMeshObj->meshName = ::g_pModelManager->find_model_by_name("prop_phone_01");
			pMeshObj->pos = glm::vec3(7.95f, 1.6f, 55.8f);
			pMeshObj->scale = 1.0f;
			pMeshObj->orientation.y = glm::radians(0.0f);
			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
			pMeshObj->friendlyName = "phone_1";
			::g_vecPointerMeshObjects.push_back(pMeshObj);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;
		}
		{
			cMeshObject *pMeshObj = new cMeshObject();
			pMeshObj->meshName = pMeshObj->meshName = ::g_pModelManager->find_model_by_name("prop_control_desk_01");
			pMeshObj->pos = glm::vec3(-30.35f, 0.0f, 24.5f);
			pMeshObj->scale = 1.0f;
			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
			pMeshObj->friendlyName = "control_desk_01";
			::g_vecPointerMeshObjects.push_back(pMeshObj);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;
		}
		{
			cMeshObject *pMeshObj = new cMeshObject();
			pMeshObj->meshName = pMeshObj->meshName = ::g_pModelManager->find_model_by_name("prop_control_desk_vintage_01");
			pMeshObj->pos = glm::vec3(-36.85f, 0.0f, 24.5f);
			pMeshObj->scale = 1.0f;
			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
			pMeshObj->friendlyName = "control_desk_vintage_01";
			::g_vecPointerMeshObjects.push_back(pMeshObj);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;
		}
		{
			cMeshObject *pMeshObj = new cMeshObject();
			//pMeshObj->meshName = ::g_prop_sign_FileName;
			pMeshObj->meshName = pMeshObj->meshName = ::g_pModelManager->find_model_by_name("prop_sign_01");
			pMeshObj->pos = glm::vec3(-14.5f, 0.0f, 37.4f);
			pMeshObj->scale = 1.0f;
			pMeshObj->orientation.y = glm::radians(45.0f);
			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
			pMeshObj->friendlyName = "sign_1";
			::g_vecPointerMeshObjects.push_back(pMeshObj);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;
		}
		{
			cMeshObject *pMeshObj = new cMeshObject();
			//pMeshObj->meshName = ::g_prop_sign_FileName;
			pMeshObj->meshName = pMeshObj->meshName = ::g_pModelManager->find_model_by_name("prop_sign_01");
			pMeshObj->pos = glm::vec3(-11.0f, 0.3f, 44.05f);
			pMeshObj->scale = 1.0f;
			pMeshObj->orientation = glm::vec3(-1.693f, 5.55f, 0.0f);
			//pMeshObj->isWireframe = true;
			pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 100.0f);
			pMeshObj->friendlyName = "sign_2";
			::g_vecPointerMeshObjects.push_back(pMeshObj);

			pMeshObj->textureNames[0] = spaceInteriorTextureFileName;
			pMeshObj->textureRatios[0] = 1.0f;
		}
		
		
	}
}

static void set_up_x_wing() {
	{
		//x wing
		cMeshObject *pMeshObj = new cMeshObject();
		//pMeshObj->meshName = g_invertedSphereFilePath;
		pMeshObj->meshName = ::g_pModelManager->find_model_by_name("x-wing");
		pMeshObj->pos = glm::vec3(-20.0f, 14.0f, -46.0f);
		pMeshObj->scale = 1.0f;
		pMeshObj->orientation.y = glm::radians(-90.0f);
		//pMeshObj->isWireframe = false;
		pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		pMeshObj->specularRGB_Power = glm::vec4(1.0f, 0.65f, 0.35f, 2.0f);
		pMeshObj->friendlyName = "x-wing";
		::g_vecPointerMeshObjects.push_back(pMeshObj);
	}
}

static std::string skyBoxTextureName = "skybox_texture";

static void set_up_sky_box() {
	{
		// sky box
		cMeshObject *pMeshObj = new cMeshObject();
		//pMeshObj->meshName = g_invertedSphereFilePath;
		pMeshObj->meshName = ::g_pModelManager->find_model_by_name("invert_sphere");
		pMeshObj->pos = glm::vec3(0.0f, 0.0f, 0.0f);
		pMeshObj->scale = 800.0f;
		pMeshObj->isWireframe = false;
		pMeshObj->diffuseRGBA = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		pMeshObj->specularRGB_Power = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		pMeshObj->friendlyName = "skybox";
		::g_vecPointerMeshObjects.push_back(pMeshObj);

		pMeshObj->textureNames[0] = skyBoxTextureName;
		pMeshObj->textureRatios[0] = 1.0f;
		//pMeshObj->textureNames[1] = g_sunnySkyBoxName;
		//pMeshObj->textureRatios[1] = 0.0f;
	}

	
}

void set_up_texture_manager() {
	::g_pTextureManager = new cBasicTextureManager();
	::g_pTextureManager->SetBasePath("assets/textures");
	// load the texture for the space station
	{
		if (::g_pTextureManager->Create2DTextureFromBMPFile(spaceInteriorTextureFileName, true)) {
			std::cout << "Loaded texture: " << spaceInteriorTextureFileName << '\n';
		}
		else {
			std::cout << "Error: cannot load texture " << spaceInteriorTextureFileName << '\n';
		}
	}
	// load the texture for the sky box
	{
		std::string error = "";
		if (!::g_pTextureManager->CreateCubeTextureFromBMPFiles(skyBoxTextureName,
																"space_sky_box/SpaceBox_right1_posX.bmp", /* right */
																"space_sky_box/SpaceBox_left2_negX.bmp", /* left */
																"space_sky_box/SpaceBox_top3_posY.bmp", /* up */
																"space_sky_box/SpaceBox_bottom4_negY.bmp", /* down */
																"space_sky_box/SpaceBox_back6_negZ.bmp", /* back */
																"space_sky_box/SpaceBox_front5_posZ.bmp", /* front */
																true,
																error)) {
			std::cout << "Error: cannot load cubemap " << error << '\n';
		}
		else {
			std::cout << "Loaded cubemap: " << skyBoxTextureName << '\n';
		}
	}
}

void set_up_mesh_objects() {
	{
		//{
		//	// engine_fire
		//	cMeshObject *pMeshObj = new cMeshObject();
		//	//pMeshObj->meshName = g_invertedSphereFilePath;
		//	pMeshObj->meshName = ::g_pModelManager->find_model_by_name("engine_fire");
		//	pMeshObj->pos = glm::vec3(24.65f, 17.05f, -43.0f);
		//	pMeshObj->scale = 1.0f;
		//	pMeshObj->orientation.y = glm::radians(-90.0f);
		//	//pMeshObj->isWireframe = true;
		//	pMeshObj->diffuseRGBA = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
		//	pMeshObj->specularRGB_Power = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
		//	::g_vecPointerMeshObjects.push_back(pMeshObj);

		//	pMeshObj->textureNames[0];
		//	pMeshObj->textureRatios[0] = 1.0f;

		//}

	}
	set_up_entrance();
	set_up_hangar();
	set_up_hangar_properties();
	set_up_x_wing();
	set_up_sky_box();
}

void set_up_light_manager(GLuint program) {
	::g_pLightManager = new cLightManager();
	::g_pLightManager->load_uniform_locations(program);
	::g_pDebugLightMeshObject = new cMeshObject();
	/* Set the debug light */
	::g_pDebugLightMeshObject->meshName = ::g_pModelManager->find_model_by_name("debug_light");
	::g_pDebugLightMeshObject->isVisible = false;
	::g_pDebugLightMeshObject->isWireframe = true;

	::g_pLightManager->vecLights[0].position = glm::vec4(-2.95f, 17.05f, -43.0f, 1.0f);
	::g_pLightManager->vecLights[0].param1.x = 0;			// Spot light
	::g_pLightManager->vecLights[0].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[0].atten.y = 0.001f;		// Linear
	::g_pLightManager->vecLights[0].atten.z = 0.3f;		// Quadratic
	::g_pLightManager->vecLights[0].atten.w = 4;	// Cut-off
	::g_pLightManager->vecLights[0].diffuse = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[0].direction = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	::g_pLightManager->vecLights[0].specular = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[0].param2.x = 1.0f;

	::g_pLightManager->vecLights[1].position = glm::vec4(-2.95f, 17.05f, -49.45f, 1.0f);
	::g_pLightManager->vecLights[1].param1.x = 0;			// Spot light
	::g_pLightManager->vecLights[1].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[1].atten.y = 0.01f;		// Linear
	::g_pLightManager->vecLights[1].atten.z = 3.0f;		// Quadratic
	::g_pLightManager->vecLights[1].atten.w = 4;	// Cut-off
	::g_pLightManager->vecLights[1].diffuse = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[1].direction = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	::g_pLightManager->vecLights[1].specular = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[1].param1.y = 30.0f;	// inner angle
	::g_pLightManager->vecLights[1].param1.z = 45.0f;	// outer angle
	::g_pLightManager->vecLights[1].param2.x = 1.0f;

	::g_pLightManager->vecLights[2].position = glm::vec4(-2.95f, 10.35f, -43.0f, 1.0f);
	::g_pLightManager->vecLights[2].param1.x = 0;			// Spot light
	::g_pLightManager->vecLights[2].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[2].atten.y = 0.01f;		// Linear
	::g_pLightManager->vecLights[2].atten.z = 0.3f;		// Quadratic
	::g_pLightManager->vecLights[2].atten.w = 4;	// Cut-off
	::g_pLightManager->vecLights[2].diffuse = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[2].direction = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	::g_pLightManager->vecLights[2].specular = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[2].param1.y = 30.0f;	// inner angle
	::g_pLightManager->vecLights[2].param1.z = 45.0f;	// outer angle
	::g_pLightManager->vecLights[2].param2.x = 1.0f;

	::g_pLightManager->vecLights[3].position = glm::vec4(-2.95f, 10.35f, -49.45f, 1.0f);
	::g_pLightManager->vecLights[3].param1.x = 0;			// Spot light
	::g_pLightManager->vecLights[3].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[3].atten.y = 0.01f;		// Linear
	::g_pLightManager->vecLights[3].atten.z = 3.0f;		// Quadratic
	::g_pLightManager->vecLights[3].atten.w = 4;	// Cut-off
	::g_pLightManager->vecLights[3].diffuse = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[3].direction = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	::g_pLightManager->vecLights[3].specular = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[3].param1.y = 30.0f;	// inner angle
	::g_pLightManager->vecLights[3].param1.z = 45.0f;	// outer angle
	::g_pLightManager->vecLights[3].param2.x = 1.0f;

	// tunnel lights
	::g_pLightManager->vecLights[4].position = glm::vec4(-2.5f, 4.5f, 5.0f, 1.0f);
	::g_pLightManager->vecLights[4].param1.x = 1;			// Spot light
	::g_pLightManager->vecLights[4].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[4].atten.y = 1.5f;		// Linear
	::g_pLightManager->vecLights[4].atten.z = 0.1f;		// Quadratic
	::g_pLightManager->vecLights[4].atten.w = 25;	// Cut-off
	::g_pLightManager->vecLights[4].diffuse = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[4].direction = glm::vec4(0.0f, -1.0f, 0.0f, 1.0f);
	::g_pLightManager->vecLights[4].specular = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[4].param1.y = 90.0f;	// inner angle
	::g_pLightManager->vecLights[4].param1.z = 180.0f;	// outer angle
	::g_pLightManager->vecLights[4].param2.x = 1.0f;    // 1.0 for on (0.0 for off)

	::g_pLightManager->vecLights[5].position = glm::vec4(-2.5f, 4.5f, 10.0f, 1.0f);
	::g_pLightManager->vecLights[5].param1.x = 1;			// Spot light
	::g_pLightManager->vecLights[5].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[5].atten.y = 1.5f;		// Linear
	::g_pLightManager->vecLights[5].atten.z = 0.1f;		// Quadratic
	::g_pLightManager->vecLights[5].atten.w = 25;	// Cut-off
	::g_pLightManager->vecLights[5].diffuse = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[5].direction = glm::vec4(0.0f, -1.0f, 0.0f, 1.0f);
	::g_pLightManager->vecLights[5].specular = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[5].param1.y = 90.0f;	// inner angle
	::g_pLightManager->vecLights[5].param1.z = 180.0f;	// outer angle
	::g_pLightManager->vecLights[5].param2.x = 1.0f;    // 1.0 for on (0.0 for off)

	::g_pLightManager->vecLights[6].position = glm::vec4(-2.5f, 4.5f, 15.0f, 1.0f);
	::g_pLightManager->vecLights[6].param1.x = 1;			// Spot light
	::g_pLightManager->vecLights[6].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[6].atten.y = 1.5f;		// Linear
	::g_pLightManager->vecLights[6].atten.z = 0.1f;		// Quadratic
	::g_pLightManager->vecLights[6].atten.w = 25;	// Cut-off
	::g_pLightManager->vecLights[6].diffuse = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[6].direction = glm::vec4(0.0f, -1.0f, 0.0f, 1.0f);
	::g_pLightManager->vecLights[6].specular = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[6].param1.y = 90.0f;	// inner angle
	::g_pLightManager->vecLights[6].param1.z = 180.0f;	// outer angle
	::g_pLightManager->vecLights[6].param2.x = 1.0f;    // 1.0 for on (0.0 for off)

	::g_pLightManager->vecLights[7].position = glm::vec4(-2.5f, 4.5f, 20.0f, 1.0f);
	::g_pLightManager->vecLights[7].param1.x = 1;			// Spot light
	::g_pLightManager->vecLights[7].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[7].atten.y = 1.5f;		// Linear
	::g_pLightManager->vecLights[7].atten.z = 0.1f;		// Quadratic
	::g_pLightManager->vecLights[7].atten.w = 25;	// Cut-off
	::g_pLightManager->vecLights[7].diffuse = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[7].direction = glm::vec4(0.0f, -1.0f, 0.0f, 1.0f);
	::g_pLightManager->vecLights[7].specular = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[7].param1.y = 90.0f;	// inner angle
	::g_pLightManager->vecLights[7].param1.z = 180.0f;	// outer angle
	::g_pLightManager->vecLights[7].param2.x = 1.0f;    // 1.0 for on (0.0 for off)


	// hangar lights

	::g_pLightManager->vecLights[8].position = glm::vec4(7.0f, 24.5f, 32.5f, 1.0f);
	::g_pLightManager->vecLights[8].param1.x = 1;			// Spot light
	::g_pLightManager->vecLights[8].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[8].atten.y = 0.05f;		// Linear
	::g_pLightManager->vecLights[8].atten.z = 0.001f;		// Quadratic
	::g_pLightManager->vecLights[8].atten.w = 100;	// Cut-off
	::g_pLightManager->vecLights[8].diffuse = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[8].direction = glm::vec4(0.0f, -1.0f, 0.0f, 1.0f);
	::g_pLightManager->vecLights[8].specular = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[8].param1.y = 5.0f;	// inner angle
	::g_pLightManager->vecLights[8].param1.z = 15.0f;	// outer angle
	::g_pLightManager->vecLights[8].param2.x = 1.0f;    // 1.0 for on (0.0 for off)

	::g_pLightManager->vecLights[9].position = glm::vec4(7.0f, 24.5f, 52.5f, 1.0f);
	::g_pLightManager->vecLights[9].param1.x = 1;			// Spot light
	::g_pLightManager->vecLights[9].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[9].atten.y = 0.05f;		// Linear
	::g_pLightManager->vecLights[9].atten.z = 0.001f;		// Quadratic
	::g_pLightManager->vecLights[9].atten.w = 100;	// Cut-off
	::g_pLightManager->vecLights[9].diffuse = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[9].direction = glm::vec4(0.0f, -1.0f, 0.0f, 1.0f);
	::g_pLightManager->vecLights[9].specular = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[9].param1.y = 5.0f;	// inner angle
	::g_pLightManager->vecLights[9].param1.z = 15.0f;	// outer angle
	::g_pLightManager->vecLights[9].param2.x = 1.0f;    // 1.0 for on (0.0 for off)

	::g_pLightManager->vecLights[10].position = glm::vec4(-10.0f, 25.0f, 32.5f, 1.0f);
	::g_pLightManager->vecLights[10].param1.x = 1;			// Spot light
	::g_pLightManager->vecLights[10].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[10].atten.y = 0.05f;		// Linear
	::g_pLightManager->vecLights[10].atten.z = 0.001f;		// Quadratic
	::g_pLightManager->vecLights[10].atten.w = 100;	// Cut-off
	::g_pLightManager->vecLights[10].diffuse = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[10].direction = glm::vec4(0.0f, -1.0f, 0.0f, 1.0f);
	::g_pLightManager->vecLights[10].specular = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[10].param1.y = 5.0f;	// inner angle
	::g_pLightManager->vecLights[10].param1.z = 15.0f;	// outer angle
	::g_pLightManager->vecLights[10].param2.x = 1.0f;    // 1.0 for on (0.0 for off)

	::g_pLightManager->vecLights[11].position = glm::vec4(-10.0f, 25.0f, 52.5f, 1.0f);
	::g_pLightManager->vecLights[11].param1.x = 1;			// Spot light
	::g_pLightManager->vecLights[11].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[11].atten.y = 0.05f;		// Linear
	::g_pLightManager->vecLights[11].atten.z = 0.001f;		// Quadratic
	::g_pLightManager->vecLights[11].atten.w = 100;	// Cut-off
	::g_pLightManager->vecLights[11].diffuse = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[11].direction = glm::vec4(0.0f, -1.0f, 0.0f, 1.0f);
	::g_pLightManager->vecLights[11].specular = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[11].param1.y = 5.0f;	// inner angle
	::g_pLightManager->vecLights[11].param1.z = 15.0f;	// outer angle
	::g_pLightManager->vecLights[11].param2.x = 1.0f;    // 1.0 for on (0.0 for off)

	::g_pLightManager->vecLights[12].position = glm::vec4(-27.0f, 25.0f, 32.5f, 1.0f);
	::g_pLightManager->vecLights[12].param1.x = 1;			// Spot light
	::g_pLightManager->vecLights[12].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[12].atten.y = 0.05f;		// Linear
	::g_pLightManager->vecLights[12].atten.z = 0.001f;		// Quadratic
	::g_pLightManager->vecLights[12].atten.w = 100;	// Cut-off
	::g_pLightManager->vecLights[12].diffuse = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[12].direction = glm::vec4(0.0f, -1.0f, 0.0f, 1.0f);
	::g_pLightManager->vecLights[12].specular = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[12].param1.y = 5.0f;	// inner angle
	::g_pLightManager->vecLights[12].param1.z = 15.0f;	// outer angle
	::g_pLightManager->vecLights[12].param2.x = 1.0f;    // 1.0 for on (0.0 for off)

	::g_pLightManager->vecLights[13].position = glm::vec4(-27.0f, 25.0f, 52.5f, 1.0f);
	::g_pLightManager->vecLights[13].param1.x = 1;			// Spot light
	::g_pLightManager->vecLights[13].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[13].atten.y = 0.05f;		// Linear
	::g_pLightManager->vecLights[13].atten.z = 0.001f;		// Quadratic
	::g_pLightManager->vecLights[13].atten.w = 100;	// Cut-off
	::g_pLightManager->vecLights[13].diffuse = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[13].direction = glm::vec4(0.0f, -1.0f, 0.0f, 1.0f);
	::g_pLightManager->vecLights[13].specular = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[13].param1.y = 5.0f;	// inner angle
	::g_pLightManager->vecLights[13].param1.z = 15.0f;	// outer angle
	::g_pLightManager->vecLights[13].param2.x = 1.0f;    // 1.0 for on (0.0 for off)

	::g_pLightManager->vecLights[14].position = glm::vec4(-10.0f, 12.5f, 42.5f, 1.0f);
	::g_pLightManager->vecLights[14].param1.x = 0;			// Spot light
	::g_pLightManager->vecLights[14].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[14].atten.y = 0.35f;		// Linear
	::g_pLightManager->vecLights[14].atten.z = 0.00001f;		// Quadratic
	::g_pLightManager->vecLights[14].atten.w = 150;	// Cut-off
	::g_pLightManager->vecLights[14].diffuse = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[14].specular = glm::vec4(1.0f, 0.65f, 0.35f, 1.0f);
	::g_pLightManager->vecLights[14].param2.x = 1.0f;    // 1.0 for on (0.0 for off)

	// plant lights
	for (unsigned i = 15, r = 0; r < 3; ++r) {
		::g_pLightManager->vecLights[i].position = glm::vec4(3.65f, r * 1.8f + 1.6f, 24.5f, 1.0f);
		::g_pLightManager->vecLights[i].param1.x = 1;			// Spot light
		::g_pLightManager->vecLights[i].atten.x = 0.0f;			// Constant
		::g_pLightManager->vecLights[i].atten.y = 2.55f;		// Linear
		::g_pLightManager->vecLights[i].atten.z = 0.076f;		// Quadratic
		::g_pLightManager->vecLights[i].atten.w = 2;	// Cut-off
		::g_pLightManager->vecLights[i].diffuse = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
		::g_pLightManager->vecLights[i].direction = glm::vec4(0.0f, -1.0f, 0.0f, 1.0f);
		::g_pLightManager->vecLights[i].specular = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
		::g_pLightManager->vecLights[i].param1.y = 30.0f;	// inner angle
		::g_pLightManager->vecLights[i].param1.z = 90.0f;	// outer angle
		::g_pLightManager->vecLights[i].param2.x = 1.0f;    // 1.0 for on (0.0 for off)
		++i;
		::g_pLightManager->vecLights[i].position = glm::vec4(1.2f, r * 1.8f + 1.6f, 24.5f, 1.0f);
		::g_pLightManager->vecLights[i].param1.x = 1;			// Spot light
		::g_pLightManager->vecLights[i].atten.x = 0.0f;			// Constant
		::g_pLightManager->vecLights[i].atten.y = 2.55f;		// Linear
		::g_pLightManager->vecLights[i].atten.z = 0.076f;		// Quadratic
		::g_pLightManager->vecLights[i].atten.w = 2;	// Cut-off
		::g_pLightManager->vecLights[i].diffuse = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
		::g_pLightManager->vecLights[i].direction = glm::vec4(0.0f, -1.0f, 0.0f, 1.0f);
		::g_pLightManager->vecLights[i].specular = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
		::g_pLightManager->vecLights[i].param1.y = 30.0f;	// inner angle
		::g_pLightManager->vecLights[i].param1.z = 90.0f;	// outer angle
		::g_pLightManager->vecLights[i].param2.x = 1.0f;    // 1.0 for on (0.0 for off)
		++i;
		::g_pLightManager->vecLights[i].position = glm::vec4(-6.4f, r * 1.8f + 1.6f, 24.5f, 1.0f);
		::g_pLightManager->vecLights[i].param1.x = 1;			// Spot light
		::g_pLightManager->vecLights[i].atten.x = 0.0f;			// Constant
		::g_pLightManager->vecLights[i].atten.y = 2.55f;		// Linear
		::g_pLightManager->vecLights[i].atten.z = 0.076f;		// Quadratic
		::g_pLightManager->vecLights[i].atten.w = 2.0f;	// Cut-off
		::g_pLightManager->vecLights[i].diffuse = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
		::g_pLightManager->vecLights[i].direction = glm::vec4(0.0f, -1.0f, 0.0f, 1.0f);
		::g_pLightManager->vecLights[i].specular = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
		::g_pLightManager->vecLights[i].param1.y = 30.0f;	// inner angle
		::g_pLightManager->vecLights[i].param1.z = 90.0f;	// outer angle
		::g_pLightManager->vecLights[i].param2.x = 1.0f;    // 1.0 for on (0.0 for off)
		++i;
		::g_pLightManager->vecLights[i].position = glm::vec4(-8.7f, r * 1.8f + 1.6f, 24.5f, 1.0f);
		::g_pLightManager->vecLights[i].param1.x = 1;			// Spot light
		::g_pLightManager->vecLights[i].atten.x = 0.0f;			// Constant
		::g_pLightManager->vecLights[i].atten.y = 2.55f;		// Linear
		::g_pLightManager->vecLights[i].atten.z = 0.076f;		// Quadratic
		::g_pLightManager->vecLights[i].atten.w = 2.0f;	// Cut-off
		::g_pLightManager->vecLights[i].diffuse = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
		::g_pLightManager->vecLights[i].direction = glm::vec4(0.0f, -1.0f, 0.0f, 1.0f);
		::g_pLightManager->vecLights[i].specular = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
		::g_pLightManager->vecLights[i].param1.y = 30.0f;	// inner angle
		::g_pLightManager->vecLights[i].param1.z = 90.0f;	// outer angle
		::g_pLightManager->vecLights[i].param2.x = 1.0f;    // 1.0 for on (0.0 for off)
		++i;
	}

	// control desk lights
	// 2 computer screens
	::g_pLightManager->vecLights[27].position = glm::vec4(-31.2f, 1.9f, 27.0f, 1.0f);
	::g_pLightManager->vecLights[27].param1.x = 1;			// Spot light
	::g_pLightManager->vecLights[27].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[27].atten.y = 2.55f;		// Linear
	::g_pLightManager->vecLights[27].atten.z = 0.076f;		// Quadratic
	::g_pLightManager->vecLights[27].atten.w = 2.5f;	// Cut-off
	::g_pLightManager->vecLights[27].diffuse = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	::g_pLightManager->vecLights[27].direction = glm::vec4(0.0f, 0.0f, -1.0f, 1.0f);
	::g_pLightManager->vecLights[27].specular = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	::g_pLightManager->vecLights[27].param1.y = 5.0f;	// inner angle
	::g_pLightManager->vecLights[27].param1.z = 180.0f;	// outer angle
	::g_pLightManager->vecLights[27].param2.x = 1.0f;

	::g_pLightManager->vecLights[28].position = glm::vec4(-28.2f, 2.1f, 25.85f, 1.0f);
	::g_pLightManager->vecLights[28].param1.x = 1;			// Spot light
	::g_pLightManager->vecLights[28].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[28].atten.y = 2.55f;		// Linear
	::g_pLightManager->vecLights[28].atten.z = 0.076f;		// Quadratic
	::g_pLightManager->vecLights[28].atten.w = 1.8f;	// Cut-off
	::g_pLightManager->vecLights[28].diffuse = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	::g_pLightManager->vecLights[28].direction = glm::vec4(0.0f, 0.0f, -1.0f, 1.0f);
	::g_pLightManager->vecLights[28].specular = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	::g_pLightManager->vecLights[28].param1.y = 5.0f;	// inner angle
	::g_pLightManager->vecLights[28].param1.z = 180.0f;	// outer angle
	::g_pLightManager->vecLights[28].param2.x = 1.0f;

	// 3 computer screens
	::g_pLightManager->vecLights[29].position = glm::vec4(-34.7f, 2.10f, 24.5f, 1.0f);
	::g_pLightManager->vecLights[29].param1.x = 1;			// Spot light
	::g_pLightManager->vecLights[29].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[29].atten.y = 2.55f;		// Linear
	::g_pLightManager->vecLights[29].atten.z = 0.076f;		// Quadratic
	::g_pLightManager->vecLights[29].atten.w = 1.8f;	// Cut-off
	::g_pLightManager->vecLights[29].diffuse = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	::g_pLightManager->vecLights[29].direction = glm::vec4(0.0f, 0.0f, -1.0f, 1.0f);
	::g_pLightManager->vecLights[29].specular = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	::g_pLightManager->vecLights[29].param1.y = 30.0f;	// inner angle
	::g_pLightManager->vecLights[29].param1.z = 55.0f;	// outer angle
	::g_pLightManager->vecLights[29].param2.x = 1.0f;

	::g_pLightManager->vecLights[30].position = glm::vec4(-36.2f, 2.1f, 24.45f, 1.0f);
	::g_pLightManager->vecLights[30].param1.x = 1;			// Spot light
	::g_pLightManager->vecLights[30].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[30].atten.y = 3.87f;		// Linear
	::g_pLightManager->vecLights[30].atten.z = 0.076f;		// Quadratic
	::g_pLightManager->vecLights[30].atten.w = 1.8f;	// Cut-off
	::g_pLightManager->vecLights[30].diffuse = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	::g_pLightManager->vecLights[30].direction = glm::vec4(0.0f, 0.0f, -1.0f, 1.0f);
	::g_pLightManager->vecLights[30].specular = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	::g_pLightManager->vecLights[30].param1.y = 30.0f;	// inner angle
	::g_pLightManager->vecLights[30].param1.z = 55.0f;	// outer angle
	::g_pLightManager->vecLights[30].param2.x = 1.0f;

	::g_pLightManager->vecLights[31].position = glm::vec4(-38.95f, 2.2f, 24.45f, 1.0f);
	::g_pLightManager->vecLights[31].param1.x = 1;			// Spot light
	::g_pLightManager->vecLights[31].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[31].atten.y = 3.87f;		// Linear
	::g_pLightManager->vecLights[31].atten.z = 0.076f;		// Quadratic
	::g_pLightManager->vecLights[31].atten.w = 1.8f;	// Cut-off
	::g_pLightManager->vecLights[31].diffuse = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	::g_pLightManager->vecLights[31].direction = glm::vec4(0.0f, 0.0f, -1.0f, 1.0f);
	::g_pLightManager->vecLights[31].specular = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	::g_pLightManager->vecLights[31].param1.y = 30.0f;	// inner angle
	::g_pLightManager->vecLights[31].param1.z = 55.0f;	// outer angle
	::g_pLightManager->vecLights[31].param2.x = 1.0f;

	::g_pLightManager->vecLights[32].position = glm::vec4(-80.0f, 14.0f, -46.0f, 1.0f);
	::g_pLightManager->vecLights[32].param1.x = 1;			// Spot light
	::g_pLightManager->vecLights[32].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[32].atten.y = 0.05f;		// Linear
	::g_pLightManager->vecLights[32].atten.z = 0.0001f;		// Quadratic
	::g_pLightManager->vecLights[32].atten.w = 80.0f;	// Cut-off
	::g_pLightManager->vecLights[32].diffuse = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	::g_pLightManager->vecLights[32].direction = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	::g_pLightManager->vecLights[32].specular = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	::g_pLightManager->vecLights[32].param1.y = 30.0f;	// inner angle
	::g_pLightManager->vecLights[32].param1.z = 55.0f;	// outer angle
	::g_pLightManager->vecLights[32].param2.x = 1.0f;


	::g_pLightManager->vecLights[33].position = glm::vec4(-9.0f, 17.45f, -32.65f, 1.0f);
	::g_pLightManager->vecLights[33].param1.x = 0;			// Spot light
	::g_pLightManager->vecLights[33].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[33].atten.y = 0.001f;		// Linear
	::g_pLightManager->vecLights[33].atten.z = 3.0f;		// Quadratic
	::g_pLightManager->vecLights[33].atten.w = 2.0f;	// Cut-off
	::g_pLightManager->vecLights[33].diffuse = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	::g_pLightManager->vecLights[33].direction = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	::g_pLightManager->vecLights[33].specular = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	::g_pLightManager->vecLights[33].param2.x = 1.0f;

	::g_pLightManager->vecLights[34].position = glm::vec4(-9.0f, 9.8f, -32.65f, 1.0f);
	::g_pLightManager->vecLights[34].param1.x = 0;			// Spot light
	::g_pLightManager->vecLights[34].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[34].atten.y = 0.001f;		// Linear
	::g_pLightManager->vecLights[34].atten.z = 3.0f;		// Quadratic
	::g_pLightManager->vecLights[34].atten.w = 2.0f;	// Cut-off
	::g_pLightManager->vecLights[34].diffuse = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	::g_pLightManager->vecLights[34].direction = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	::g_pLightManager->vecLights[34].specular = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	::g_pLightManager->vecLights[34].param2.x = 1.0f;

	::g_pLightManager->vecLights[35].position = glm::vec4(-9.0f, 9.8f, -59.65f, 1.0f);
	::g_pLightManager->vecLights[35].param1.x = 0;			// Spot light
	::g_pLightManager->vecLights[35].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[35].atten.y = 0.001f;		// Linear
	::g_pLightManager->vecLights[35].atten.z = 3.0f;		// Quadratic
	::g_pLightManager->vecLights[35].atten.w = 2.0f;	// Cut-off
	::g_pLightManager->vecLights[35].diffuse = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	::g_pLightManager->vecLights[35].direction = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	::g_pLightManager->vecLights[35].specular = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	::g_pLightManager->vecLights[35].param2.x = 1.0f;

	::g_pLightManager->vecLights[36].position = glm::vec4(-9.0f, 17.45f, -59.65f, 1.0f);
	::g_pLightManager->vecLights[36].param1.x = 0;			// Spot light
	::g_pLightManager->vecLights[36].atten.x = 0.0f;			// Constant
	::g_pLightManager->vecLights[36].atten.y = 0.001f;		// Linear
	::g_pLightManager->vecLights[36].atten.z = 3.0f;		// Quadratic
	::g_pLightManager->vecLights[36].atten.w = 2.0f;	// Cut-off
	::g_pLightManager->vecLights[36].diffuse = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	::g_pLightManager->vecLights[36].direction = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	::g_pLightManager->vecLights[36].specular = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	::g_pLightManager->vecLights[36].param2.x = 1.0f;

}