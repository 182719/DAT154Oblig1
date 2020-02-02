#pragma once
#include "framework.h"
#include "DAT154Oblig1.h"
#include "TrafficLight.h"
#include "Car.h"

void drawTrafficLight(HDC hdc, int x, int y, TrafficLight trafficLight);

void drawRoad(HDC hdc);

void drawCar(HDC hdc, Car* car);
void drawCarI(HDC hdc, Car* car);