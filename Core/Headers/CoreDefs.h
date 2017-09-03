#pragma once

#include <cstdlib>
#include <vector>
#include <utility>
#include <string>

namespace Core
{
	template <typename T>
	using List = std::vector<T>;

	using String = std::string;

	template <typename T1, typename T2 = T1>
	using Pair = std::pair<T1, T2>;

	using uint = unsigned int;
};