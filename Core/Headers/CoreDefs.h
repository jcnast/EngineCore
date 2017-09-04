#pragma once

#include "../Debugging/Headers/Declarations.h"

#include <algorithm>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>

namespace Core
{
	template <typename T>
	using List = std::vector<T>;

	using String = std::string;

	template <typename T1, typename T2 = T1>
	using Pair = std::pair<T1, T2>;
	
	template <typename T>
	T Min(T a, T b) { return ((a < b) ? a : b); }
	template <typename T>
	T Max(T a, T b) { return ((a > b) ? a : b); }
	template <typename T>
	T Clamp(T a, T min, T max) { return (Max(Min(a, max), min)); }
	
	using uint = unsigned int;
};