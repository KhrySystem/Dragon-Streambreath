#pragma once 

#include <dragon/dg_backend.hpp>

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
	/// @param eType Specifies the error type and first digit of the message code.
	/// @param eSeverity Specifies how bad the error is and the second digit of the message code.
	/// @param eMessage Contains a string of the error message, along with a 32 bit unsigned int containing a summary of the error. 
	/// @return 
	DGAPI void throwError(Dragon::Error::ErrorInfo eInfo);
}


