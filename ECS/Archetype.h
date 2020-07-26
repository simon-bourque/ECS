#pragma once

#include <unordered_set>

#include "Types.h"
#include "ComponentInfo.h"

class Archetype
{
private:
	std::unordered_set<ComponentInfo> m_Components;
public:
	template<typename T>
	void AddComponentType();

	template<typename T>
	void RemoveComponentType();

	template<typename T>
	bool Contains() const { return m_Components.count(ComponentInfo<T>::Info()) > 0; }
	
	bool IsEmpty() const { return m_Components.empty(); }

	const std::unordered_set<ComponentInfo>& GetComponents() const { return m_Components; }
};

template<typename T>
void Archetype::AddComponentType()
{
	m_Components.insert(ComponentInfo::Info<T>());
}

template<typename T>
void Archetype::RemoveComponentType()
{
	m_Components.erase(ComponentInfo::Info<T>());
}