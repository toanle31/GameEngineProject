#include "ServiceLocator.h"

namespace Bonk
{
	std::unordered_map<std::type_index, std::shared_ptr<void>>& ServiceLocator::GetServicesMap()
	{
		// Static variable inside a function has internal linkage
		// This is not a global variable - it's encapsulated within this function
		static std::unordered_map<std::type_index, std::shared_ptr<void>> s_Services;
		return s_Services;
	}
}