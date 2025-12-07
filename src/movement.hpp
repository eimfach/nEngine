#pragma once

#include "game_object.hpp"
#include "window.hpp"
#include "entity_manager.hpp"
#include "settings.hpp"

//lib
#include "GLFW/glfw3.h"

namespace nEngine::Engine {
	class MovementControl {
	public:

        void moveInPlaneXZ(GLFWwindow* window, float delta, ECS::Transform& transform);

        Settings::KeyMappings keys{};
        float moveSpeed{ 3.f };
        float lookSpeed{ 1.5f };
	};
}
