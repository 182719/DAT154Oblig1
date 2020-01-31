#pragma once
#include <vector>
#include "Car.h"
using namespace std;

class SirkList
{
	vector<Car*> x;

public:
	SirkList();
	void push_back(Car* c);
	Car* pop();
};