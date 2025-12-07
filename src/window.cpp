#include "window.hpp"

#include <stdexcept>

namespace nEngine::Engine {
	Window::Window(int w, int h, std::string name) : width{ w }, height{ h }, windowName{ name } {
		initWindow();
	}

	Window::~Window() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void Window::initWindow() {
		
		int result = glfwInit();
		if (result != GLFW_TRUE) {
			
		}
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
		
		if (glfwPlatformSupported(GLFW_PLATFORM_WAYLAND)) {
			glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_WAYLAND);	
		}

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}

	void Window::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface) {
		if (glfwCreateWindowSurface(instance, window, nullptr, surface)) {
			throw std::runtime_error("Failed to create runtime surface");
		}
	}

	void Window::framebufferResizedCallback(int new_width, int new_height) {
		framebufferResized = true;
		width = new_width;
		height = new_height;
	}
}
