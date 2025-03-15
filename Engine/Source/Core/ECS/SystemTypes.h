#pragma once

#include "Entity.h"

class ENGINE_API SystemBase
{
public:
	virtual ~SystemBase() = default;

	virtual void Process(const Entity& InEntity) = 0;
};