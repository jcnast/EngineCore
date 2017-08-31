#pragma once

#include <cstdlib>

namespace Core
{
	template <bool B, typename T = void>
	using EnableIf = std::enable_if<B, T>;

	template <typename T1, typename T2>
	using IsSame = std::is_same<T1, T2>;

	template <typename T1, typename T2>
	using IsBaseOf = std::is_base_of<T1, T2>;

	template <typename T1, typename T2> 
	using EqualTo = typename EnableIf<IsSame<T1, T2>::value>;
};