#include <vector>
#include "SirkList.h"
#include "car.h"

SirkList::SirkList()
{
	vector<Car*> x;
}

void SirkList::push_back(Car* c) {
	x.push_back(c);
}

Car* SirkList::pop() {
	Car* c = x.at(0);
	
	return c;
}