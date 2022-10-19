#pragma once 

#include <dragon/dg_backend.hpp>

namespace Dragon::Stream {
	typedef struct Engine {
		static uint32_t layerCount;
		static std::vector<VkLayerProperties> availableLayers;
		static std::vector<const char*> availibleLayerNames;
		static VkDebugUtilsMessengerEXT debugMessenger;
		static VkDebugUtilsMessengerCreateInfoEXT debugMessengerCreateInfo;
	} Engine;

	DGAPI DgBool32 isValidationLayerSupported(std::string layerName);
}


