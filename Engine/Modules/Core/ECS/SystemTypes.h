#pragma once

struct Entity;
class SystemBase
{
public:
	virtual ~SystemBase() = default;

	virtual void Process(const Entity& InEntity) = 0;
};