#pragma once 

#include <dragon/backend.hpp>

#include "error.hpp"

namespace Dragon::Stream {
	typedef struct Engine {
		static uint32_t layerCount;
		static std::vector<VkLayerProperties> availableLayers;
		static std::vector<const char*> availibleLayerNames;
		static VkDebugUtilsMessengerEXT debugMessenger;
		static VkDebugUtilsMessengerCreateInfoEXT debugMessengerCreateInfo;

		static void* errorCallback;
	} Engine;

	/// @brief Checks if a validation layer is supported / enabled. All layers are by default enabled.
	/// @param layerName The string of the layer name
	/// @return DG_TRUE if layer was found, DG_FALSE otherwise
	DGAPI DgBool32 isValidationLayerSupported(std::string layerName);
	/// @brief Checks if a validation layer is supported / enabled. All layers are by default enabled.
	/// @param callback a pointer to the function that should be called as the output.
	/// @return
	DGAPI void setErrorCallback(void* callback);
	
	/// @brief Throws an error to the error callback set with setErrorCallback(void*)
	/// @param eMessage Contains a string of the error message, along with a string containing a tag to the error. 
	/// @return 
	DGAPI void throwError(Dragon::Error::ErrorInfo eInfo);
}


