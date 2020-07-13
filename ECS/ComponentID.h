#pragma once

#include <type_traits>

#include "Types.h"

struct ComponentIDGenerator
{
	static int64 GenerateID()
	{
		static int64 id = 0;
		return ++id;
	}
};

template <typename T>
struct ComponentID 
{
	static_assert(std::is_pod_v<T>, "Invalid component");
	static int64 GetID()
	{
		static int64 id = ComponentIDGenerator::GenerateID();
		return id;
	}
};