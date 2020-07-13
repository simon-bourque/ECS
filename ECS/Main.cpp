#include <iostream>

#include "Entities.h"
#include "ComponentID.h"

using namespace std;

struct ComponentA {};
struct ComponentB {};

int main()
{
	//cout << ComponentID<ComponentA>::GetID() << endl;
	//cout << ComponentID<ComponentB>::GetID() << endl;
	//
	//cout << ComponentID<ComponentA>::GetID() << endl;
	//cout << ComponentID<ComponentB>::GetID() << endl;

	std::function<void(ComponentA&, ComponentB&)> lambda = [](ComponentA& a, ComponentB& b)
	{
	
	};
	Entities::ForEach(lambda);

	return 0;
}