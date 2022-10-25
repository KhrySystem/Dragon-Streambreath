#pragma once

#include "dgStreamEngine.hpp"
#include "init.hpp"
#include <dragon/dg_backend.hpp>
#include <dragon/dgEngine.hpp>

DGAPI VKAPI_ATTR VkBool32 VKAPI_CALL dgVkValidationLayerDebugCalback(
	VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
	VkDebugUtilsMessageTypeFlagsEXT messageType,
	const VkDebugUtilsMessengerCallbackDataEXT* callbackData,
	void* userData
);

DGAPI VkResult dgCreateDebugUtilsMessengerEXT(
	const VkDebugUtilsMessengerCreateInfoEXT* createInfo,
	const VkAllocationCallbacks* allocator,
	VkDebugUtilsMessengerEXT* debugMessenger
);

DGAPI void dgDestroyDebugUtilsMessengerEXT(
	VkDebugUtilsMessengerEXT debugMessenger, 
	const VkAllocationCallbacks* allocator
);

DGAPI std::string dgConvertVkResultToString(VkResult result);
DGAPI std::string dgConvertALErrorToString(ALenum error);