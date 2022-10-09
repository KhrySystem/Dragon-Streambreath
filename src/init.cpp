#include <dragon/dragon.hpp>

DGAPI void dgStreamInit() {
    vkEnumerateInstanceLayerProperties(&dgStreamEngine::layerCount, nullptr);

    dgEngine::availableLayers.resize(dgStreamEngine::layerCount);
    vkEnumerateInstanceLayerProperties(&dgStreamEngine::layerCount, dgStreamEngine::availableLayers.data());

    dgStreamEngine::debugMessengerCreateInfo.flags = NULL;
    dgStreamEngine::debugMessengerCreateInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
    dgStreamEngine::debugMessengerCreateInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
    dgStreamEngine::debugMessengerCreateInfo.pfnUserCallback = dgVkValidationLayerDebugCalback;
    dgStreamEngine::debugMessengerCreateInfo.pNext = NULL;
    dgStreamEngine::debugMessengerCreateInfo.pUserData = NULL;
    dgStreamEngine::debugMessengerCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;

    VkResult result = dgCreateDebugUtilsMessengerEXT(dgEngine::vkInstance, &dgStreamEngine::debugMessengerCreateInfo, NULL, &dgStreamEngine::debugMessenger);
    if(result != VK_SUCCESS) {
        throw dgVulkanDebugUtilsMessengerEXTCreationFailedException() << DgExceptionInfo(("Vulkan DebugUtilsMessengerEXT Creation Failed with " + dgConvertVkResultToString(result)).c_str());
    }
}