#pragma once 

#include <dragon/dg_backend.hpp>

typedef struct dgStreamEngine {
	static uint32_t layerCount;
	static std::vector<VkLayerProperties> availableLayers;
	static std::vector<const char*> availibleLayerNames;
	static VkDebugUtilsMessengerEXT debugMessenger;
	static VkDebugUtilsMessengerCreateInfoEXT debugMessengerCreateInfo;
} DgStreamEngine;

DGAPI DG_BOOL dgIsValidationLayerSupported(std::string layerName);