#include <dragon/stream/dgStream.hpp>
#include <dragon/options.hpp>

using namespace Dragon;

uint32_t Stream::Engine::layerCount;
VkDebugUtilsMessengerEXT Stream::Engine::debugMessenger;
VkDebugUtilsMessengerCreateInfoEXT Stream::Engine::debugMessengerCreateInfo;

DGAPI DgBool32 Stream::init() {
    vkEnumerateInstanceLayerProperties(&Stream::Engine::layerCount, nullptr);

    Stream::Engine::availableLayers.resize(Stream::Engine::layerCount);
    vkEnumerateInstanceLayerProperties(&Stream::Engine::layerCount, Stream::Engine::availableLayers.data());

    Stream::Engine::debugMessengerCreateInfo.flags = NULL;
    Stream::Engine::debugMessengerCreateInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
    Stream::Engine::debugMessengerCreateInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
    Stream::Engine::debugMessengerCreateInfo.pfnUserCallback = dgVkValidationLayerDebugCalback;
    Stream::Engine::debugMessengerCreateInfo.pNext = NULL;
    Stream::Engine::debugMessengerCreateInfo.pUserData = NULL;
    Stream::Engine::debugMessengerCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;

    VkResult result = dgCreateDebugUtilsMessengerEXT(&Stream::Engine::debugMessengerCreateInfo, NULL, &Stream::Engine::debugMessenger);
    if(result != VK_SUCCESS) {
        if(getOption(DRAGON_STREAMBREATH_ENABLED)) {
            Error::ErrorInfo info{};
            info.code = "2.2.9.0";
            info.message = "The Vulkan debugger failed to be initialized!";
            Stream::throwError(info);
        }
        return DG_FALSE;
    }
    return DG_TRUE;
}

DGAPI void Stream::setErrorCallback(ErrorCallback callback) {
    
}

DGAPI void Stream::terminate() {
    dgDestroyDebugUtilsMessengerEXT(Stream::Engine::debugMessenger, NULL);
}