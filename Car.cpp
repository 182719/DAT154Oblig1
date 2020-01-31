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

void Car::setCarInFront(Car* c)
{
	carInFront = c;
}

//TODO: ingen kræsjing
void Car::move()
{
	if (!horizontal) {
		if (carInFront == NULL) {
			if (position.y < 350) {
				position.y += 10;
			}
			else if (position.y >= 350 && trafficLight->getCurrentState().green)
			{
				position.y += 10;
			}
			else if (position.y > 351) {
				position.y += 10;
			}
		}
		else {
			if (position.y < 350 && (carInFront->getPosition().y) - 60 > position.y) { //trekker fra 60 pga lengden på bilen
				position.y += 10;
			}
			else if (position.y >= 350 && trafficLight->getCurrentState().green && carInFront->getPosition().y > position.y)
			{
				position.y += 10;
			}
			else if (position.y > 351 && (carInFront->getPosition().y) - 60 > position.y) {
				position.y += 10;
			}
		}
	}
	else {
		if (carInFront == NULL) {
			if (position.x < 350) {
				position.x += 10;
			}
			else if (position.x >= 350 && trafficLight->getCurrentState().green)
			{
				position.x += 10;
			}
			else if (position.x > 351) {
				position.x += 10;
			}
		}
		else {
			if (position.x < 350 && (carInFront->getPosition().x) - 60 > position.x) { //trekker fra 60 pga lengden på bilen
				position.x += 10;
			}
			else if (position.x >= 350 && trafficLight->getCurrentState().green && carInFront->getPosition().x > position.x)
			{
				position.x += 10;
			}
			else if (position.x > 351 && (carInFront->getPosition().x) - 60 > position.x) {
				position.x += 10;
			}
		}
	}


}