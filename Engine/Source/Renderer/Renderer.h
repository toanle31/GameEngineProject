#pragma once
#include "Interfaces\ProductInterface.h"

class ENGINE_API Renderer final : public ISingletonProduct
{
	DECLARE_SINGLETON_PRODUCT(Renderer)
public:
	~Renderer() = default;
	void Initialize();
};