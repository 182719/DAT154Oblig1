#include "Car.h"
#include "stdlib.h"



Car::Car() {
	position = { 100,100 };
	int r = rand() % 255;
	int g = rand() % 255;
	int b = rand() % 255;
	color = { r,g,b };
}
Car::Car(Position p) : position(p) 
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