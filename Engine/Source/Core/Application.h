#pragma once

namespace Core
{
class ENGINE_API Application
{
public:
	~Application() = default;
	int32 ApplicationMain();
};
}