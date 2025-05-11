#pragma once
#include "Core.h"
#include "Rendering/Types/Renderer.h"
#include "RAII/SDL/SDLRAIIs.h"

class SingletonContainer;

class RENDERING_API VulkanRenderer : IRenderer<VulkanRenderer>
{
    REGISTER_SINGLETON_CLASS(VulkanRenderer, class SingletonContainer)
public:
    bool Initialize();
    void Shutdown();
    void HandleSDLWindowEvents();
    void BeginFrame();
    void EndFrame();
    void RecordRenderingCommands();
    void Draw();
    static constexpr ERenderingAPI GetType();
private:
    TSharedPtr<SVulkanLoadLibraryHandle> SLoadVulkanLibHandle;
};
