#pragma once

#include "VectorTests.h"

#include "../../Debugging/Headers/Macros.h"

bool RunMathUnitTests()
{
	std::cout << "Starting unit tests..." << std::endl;

	bool vectorTests = VERIFY(Math::RunVectorTests());

	std::cout << "Finished unit tests..." << std::endl;

	return vectorTests;
}