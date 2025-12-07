#include "first_app.hpp"
#include "window.hpp"
#include <memory>

namespace nEngine {
	
	struct UserPointersGLFW {
		FirstApp* firstApp;
		Engine::Window* window;
	};

	static std::unique_ptr<UserPointersGLFW> userPointer{};
}
