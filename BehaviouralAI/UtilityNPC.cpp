#include "UtilityNPC.h"
#include <iostream>

namespace UtilitySystem
{
	void UtilityNPC::selectAction(float a_fdeltaTime)
	{
		collectFood(a_fdeltaTime);
	}
}