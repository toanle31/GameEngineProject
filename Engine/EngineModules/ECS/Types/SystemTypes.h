#pragma once

struct Entity;
class ECS_API SystemBase
{
public:
	virtual ~SystemBase() = default;

	virtual void Process(const Entity& InEntity) = 0;
};