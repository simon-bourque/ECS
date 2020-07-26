#include <iostream>

#include "Entities.h"
#include "ComponentInfo.h"
#include "ByteBuffer.h"
#include "Archetype.h"
#include "ComponentBuffer.h"

using namespace std;

struct ComponentA {};
struct ComponentB {};

struct ComponentC
{
	uint32 a;
	uint32 b;
};

struct ComponentD
{
	uint64 b;
	uint32 a;
};

int main()
{
	//cout << ComponentID<ComponentA>::GetID() << endl;
	//cout << ComponentID<ComponentB>::GetID() << endl;
	//
	//cout << ComponentID<ComponentA>::GetID() << endl;
	//cout << ComponentID<ComponentB>::GetID() << endl;

	//cout << sizeof(uint32) << endl;
	//cout << sizeof(uint64) << endl;
	//cout << sizeof(ComponentD) << endl;
	//ComponentC test1 = { 10, 50 };
	//ComponentD test2 = { 75, 25 };
	//
	//ByteBuffer buffer(8);
	//
	//buffer.Add(&test1, sizeof(test1));
	//buffer.Add(&test2, sizeof(test2));
	//
	//std::function<void(ComponentA&, ComponentB&)> lambda = [](ComponentA& a, ComponentB& b)
	//{
	//
	//};
	//Entities::ForEach(lambda);

	Archetype archetype;
	archetype.AddComponentType<ComponentB>();
	archetype.AddComponentType<ComponentD>();
	archetype.AddComponentType<ComponentA>();

	ComponentBuffer buffer(archetype);

	cout << "Hello" << endl;

	return 0;
}