#include "VulkanRenderer.h"

#include "CoreUtils.h"
#include "SDL3/SDL_vulkan.h"

bool VulkanRenderer::Initialize()
{
    // Initialize SDL_vulkan stuff?
    SLoadVulkanLibHandle = CoreUtils::MakeShared<SVulkanLoadLibraryHandle>(nullptr);
    if (!SLoadVulkanLibHandle || !SLoadVulkanLibHandle->bInitialized)
    {
        String Error = SDL_GetError();
        LoggingLib::Log(ELogCategory::Rendering, ELogVerbosity::Error, Error);
        return false;
    }

    // CreateInstance
    // CreatePhysicalDevice - Represents the GPU
    // CreateLogicalDevice - VkDevice basically allow our application an interface to interact with the GPU
    // Create Queues - This is basically the double buffers that we draw to and swap to display
    // Create Surface - SDL handles this for us I believe
    // Create SwapChain

    return true;
}

void VulkanRenderer::Shutdown()
{

}

void VulkanRenderer::HandleSDLWindowEvents()
{

}

void VulkanRenderer::BeginFrame()
{

}

void VulkanRenderer::EndFrame()
{

}

void VulkanRenderer::RecordRenderingCommands()
{

}

void VulkanRenderer::Draw()
{

}

constexpr ERenderingAPI VulkanRenderer::GetType()
{
    return ERenderingAPI::Vulkan;
}
