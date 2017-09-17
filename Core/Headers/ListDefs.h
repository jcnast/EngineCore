#pragma once

#include "../Debugging/Headers/Declarations.h"

#include <algorithm>
#include <cstdlib>
#include <stdlib.h>
#include <vector>

namespace Core
{
	template <typename T>
	using List = std::vector<T>;

	template <typename T>
	struct Truth
	{
		bool Valid;
		T Result;

		bool operator()
		{
			return Valid;
		}

		T operator()
		{
			return Result;
		}
	};

	template <typename T>
	void Push(List<T> list, T entry)
	{
		list.push_back(entry);
	}

	template <typename T>
	void Push(List<T> list, T entry, T... otherEntries)
	{
		Push(list, entry);
		Push(list, otherEntries...);
	}

	template <typename T>
	Truth<T> InList(List<T> list, T entry)
	{
		auto index = std::find(list.begin(), list.end(), entry);
		
		if (index != list.end())
		{
			return Truth{ false, 0 };
		}

		return Truth{ true, index };
	}

	template <typename T>
	Truth<T> InList(List<T> list, T entry, T... otherEntries)
	{
		if (InList(list, entry))
		{
			return InList(list, otherEntries...);
		}

		return Truth{ false, 0 };
	}

	template <typename T>
	bool Remove(List<T> list, T entry)
	{
		if (auto truth = InList(list, entry))
		{
			list.erase(truth);
			return true;
		}

		return false;
	}

	template <typename T>
	bool Remove(List<T> list, T entry, T... otherEntries)
	{
		if (Remove(list, entry))
		{
			return Remove(list, otherEntries...);
		}

		return false;
	}
};