#pragma once 

#include <dragon/dg_backend.hpp>

namespace Dragon::Stream {
	typedef struct engine {
		static uint32_t layerCount;
		static std::vector<VkLayerProperties> availableLayers;
		static std::vector<const char*> availibleLayerNames;
		static VkDebugUtilsMessengerEXT debugMessenger;
		static VkDebugUtilsMessengerCreateInfoEXT debugMessengerCreateInfo;
	} engine;

	DGAPI DgBool32 isValidationLayerSupported(std::string layerName);
}


