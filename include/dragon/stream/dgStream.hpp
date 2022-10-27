#pragma once

#include "dgStreamEngine.hpp"
#include "init.hpp"
#include <dragon/backend.hpp>
#include <dragon/dgEngine.hpp>

/// @brief 
/// @param messageSeverity Contains the severity of the Vulkan Error
/// @param messageType Contains the type of the Vulkan Error
/// @param callbackData Contains information about the Vulkan error
/// @param userData A user specified callback
/// @return 
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