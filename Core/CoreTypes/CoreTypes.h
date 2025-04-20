#pragma once

#include "TypeDefines.h"
enum class ERenderingAPI : uint8
{
    Vulkan,
    OpenGL,
    DirectX
};

struct WindowSettings
{
    String WindowTitle = "";
    uint16 Width, Height;
    SWindowFlags Flags;
};