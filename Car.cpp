#include "Car.h"
#include "stdlib.h"



Car::Car() {
	position = { 100,100 };
	int r = rand() % 255;
	int g = rand() % 255;
	int b = rand() % 255;
	color = { r,g,b };
	horizontal = false;
}
Car::Car(Position p, bool h, TrafficLight* t) : position(p), horizontal(h), trafficLight(t)
{
	int r = rand() % 255;
	int g = rand() % 255;
	int b = rand() % 255; 
	color = {r,g,b};
}

Color Car::getColor()
{
	return color;
}

Position Car::getPosition()
{
	return position;
}

void Car::setPosition(Position p)
{
	position = p;
}

void Car::move()
{
	if (trafficLight->getCurrentState().green) {
		position.y += 50;
	}
}