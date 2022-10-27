#include <dragon/stream/dgStream.hpp>

uint32_t Dragon::Stream::Engine::layerCount;
VkDebugUtilsMessengerEXT Dragon::Stream::Engine::debugMessenger;
VkDebugUtilsMessengerCreateInfoEXT Dragon::Stream::Engine::debugMessengerCreateInfo;

DGAPI void Dragon::Stream::init() {
    vkEnumerateInstanceLayerProperties(&Dragon::Stream::Engine::layerCount, nullptr);

    Dragon::Stream::Engine::availableLayers.resize(Dragon::Stream::Engine::layerCount);
    vkEnumerateInstanceLayerProperties(&Dragon::Stream::Engine::layerCount, Dragon::Stream::Engine::availableLayers.data());

    Dragon::Stream::Engine::debugMessengerCreateInfo.flags = NULL;
    Dragon::Stream::Engine::debugMessengerCreateInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
    Dragon::Stream::Engine::debugMessengerCreateInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
    Dragon::Stream::Engine::debugMessengerCreateInfo.pfnUserCallback = dgVkValidationLayerDebugCalback;
    Dragon::Stream::Engine::debugMessengerCreateInfo.pNext = NULL;
    Dragon::Stream::Engine::debugMessengerCreateInfo.pUserData = NULL;
    Dragon::Stream::Engine::debugMessengerCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;

    VkResult result = dgCreateDebugUtilsMessengerEXT(&Dragon::Stream::Engine::debugMessengerCreateInfo, NULL, &Dragon::Stream::Engine::debugMessenger);
    if(result != VK_SUCCESS) {
        throw Dragon::VulkanDebugUtilsMessengerEXTCreationFailedException() << Dragon::ExceptionInfo(("Vulkan DebugUtilsMessengerEXT Creation Failed with " + dgConvertVkResultToString(result)).c_str());
    }
}

DGAPI void Dragon::Stream::setErrorCallback(void* callback) {
    Dragon::Stream::Engine::errorCallback = callback;
}

DGAPI void Dragon::Stream::terminate() {
    dgDestroyDebugUtilsMessengerEXT(Dragon::Stream::Engine::debugMessenger, NULL);
}