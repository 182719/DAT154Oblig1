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



Car::Car(Position p, bool h, TrafficLight* t, Car* c) : position(p), horizontal(h), trafficLight(t), carInFront(c)
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

//TODO: ingen kræsjing
void Car::move()
{
	if (carInFront == NULL) {
		if (position.y < 400) {
			position.y += 10;
		}
		else if (position.y >= 400 && trafficLight->getCurrentState().green)
		{
			position.y += 10;
		}
		else if (position.y > 500) {
			position.y += 10;
		}
	}
	else {
		if (position.y < 400 && carInFront->getPosition().y > position.y) {
			position.y += 10;
		}
		else if (position.y >= 400 && trafficLight->getCurrentState().green && carInFront->getPosition().y > position.y)
		{
			position.y += 10;
		}
		else if (position.y > 500 && carInFront->getPosition().y > position.y) {
			position.y += 10;
		}
	}

}