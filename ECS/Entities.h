#pragma once

#include <functional>
#include <iostream>
#include "ComponentID.h"

class Entities
{
public:
	template<typename... T>
	static void ForEach(std::function<void(T&...)>& lambda)
	{
		(std::cout << ... << ComponentID<T>::GetID());
	}
};