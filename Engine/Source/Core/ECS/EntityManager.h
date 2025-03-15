#pragma once

#include "Entity.h"

/*
* Manages all entity including the World Entity itself.
*/
class ENGINE_API EntityManager
{
public:
	virtual ~EntityManager() = default;
	
	static Entity GetWorld();

private:

};