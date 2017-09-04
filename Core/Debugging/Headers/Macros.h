#pragma once

#include <cstdlib>
#include <iostream>
#include <cassert>

#include "Declarations.h"

bool verifyCondition(bool condition)
{
	bool result = condition;
	
	if (GLOBAL_EXPLICIT)
	{
		std::cout << "X was " << (result ? "TRUE" : "FALSE") << std::endl;
	}

	assert(result);
	return result;
}

#define VERIFY( X ) verifyCondition( X )