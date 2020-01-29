#pragma once
#include "TrafficLight.h"

typedef struct {
	int red;
	int green;
	int blue;
} Color;

typedef struct {
	int x;
	int y;
} Position;

class Car {
	Color color;
	Position position;
	bool horizontal;
	TrafficLight* trafficLight;
	Car* carInFront;

public:
	Car();
	Car(Position p, bool h, TrafficLight* t, Car* carInFront);
	Color getColor();
	Position getPosition();
	void setPosition(Position p);
	void move();
};

