#pragma once

#include "Types.h"
#include <functional>

struct Entity
{
	uint64 Id = 0;
	static const Entity Null;

	Entity() = default;
	Entity(uint64 id);
	Entity(const Entity& entity);

	Entity& operator=(const Entity& entity);
	bool operator==(const Entity& entity) const { return Id == entity.Id; }
	bool operator!=(const Entity& entity) const { return Id != entity.Id; }
};

namespace std
{
	template<>
	struct hash<Entity>
	{
		std::size_t operator()(const Entity& entity) const noexcept
		{
			return std::hash<uint64>{}(entity.Id);
		}
	};
}