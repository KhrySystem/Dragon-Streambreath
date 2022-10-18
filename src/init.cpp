#include <dragon/stream/dgStream.hpp>

DGAPI void Dragon::Stream::init() {
    vkEnumerateInstanceLayerProperties(&Dragon::Stream::engine::layerCount, nullptr);

    Dragon::Stream::engine::availableLayers.resize(Dragon::Stream::engine::layerCount);
    vkEnumerateInstanceLayerProperties(&Dragon::Stream::engine::layerCount, Dragon::Stream::engine::availableLayers.data());

    Dragon::Stream::engine::debugMessengerCreateInfo.flags = NULL;
    Dragon::Stream::engine::debugMessengerCreateInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
    Dragon::Stream::engine::debugMessengerCreateInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
    Dragon::Stream::engine::debugMessengerCreateInfo.pfnUserCallback = dgVkValidationLayerDebugCalback;
    Dragon::Stream::engine::debugMessengerCreateInfo.pNext = NULL;
    Dragon::Stream::engine::debugMessengerCreateInfo.pUserData = NULL;
    Dragon::Stream::engine::debugMessengerCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;

    VkResult result = dgCreateDebugUtilsMessengerEXT(Dragon::engine::vkInstance, &Dragon::Stream::engine::debugMessengerCreateInfo, NULL, &Dragon::Stream::engine::debugMessenger);
    if(result != VK_SUCCESS) {
        throw Dragon::VulkanDebugUtilsMessengerEXTCreationFailedException() << Dragon::ExceptionInfo(("Vulkan DebugUtilsMessengerEXT Creation Failed with " + dgConvertVkResultToString(result)).c_str());
    }
}