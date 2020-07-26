#pragma once

#include <type_traits>

#include "Types.h"

struct ComponentIDGenerator
{
	static uint64 GenerateID()
	{
		static uint64 id = 0;
		return ++id;
	}
};

template <typename T>
struct ComponentID
{
	static_assert(std::is_pod_v<T>, "Invalid component");
	static uint64 GetID()
	{
		static uint64 id = ComponentIDGenerator::GenerateID();
		return id;
	}
};

struct ComponentInfo
{
	uint64 Id = 0;
	uint64 Size = 0;

	template<typename T>
	static ComponentInfo Info()
	{
		return { ComponentID<T>::GetID(), sizeof(T) };
	}

	bool operator==(const ComponentInfo info) const { return Id == info.Id && Size == info.Size; }
};

namespace std
{
	template<>
	struct hash<ComponentInfo>
	{
		std::size_t operator()(const ComponentInfo& info) const noexcept
		{
			return std::hash<uint64>{}(info.Id);
		}
	};
}