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

//TODO: ingen kr�sjing
void Car::move()
{
	if (!horizontal) {
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
			if (position.y < 400 && (carInFront->getPosition().y) - 60 > position.y) { //trekker fra 60 pga lengden p� bilen
				position.y += 10;
			}
			else if (position.y >= 400 && trafficLight->getCurrentState().green && carInFront->getPosition().y > position.y)
			{
				position.y += 10;
			}
			else if (position.y > 450 && (carInFront->getPosition().y) - 60 > position.y) {
				position.y += 10;
			}
		}
	}
	else {
		if (carInFront == NULL) {
			if (position.x < 400) {
				position.x += 10;
			}
			else if (position.x >= 400 && trafficLight->getCurrentState().green)
			{
				position.x += 10;
			}
			else if (position.x > 500) {
				position.x += 10;
			}
		}
		else {
			if (position.x < 400 && (carInFront->getPosition().x) - 60 > position.x) { //trekker fra 60 pga lengden p� bilen
				position.x += 10;
			}
			else if (position.x >= 400 && trafficLight->getCurrentState().green && carInFront->getPosition().x > position.x)
			{
				position.x += 10;
			}
			else if (position.x > 450 && (carInFront->getPosition().x) - 60 > position.x) {
				position.x += 10;
			}
		}
	}


}