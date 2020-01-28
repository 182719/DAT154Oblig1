#include "TrafficLight.h"

TrafficLight::TrafficLight(LightState s) : lightState(s)
{
}

void TrafficLight::setLightState(LightState s)
{
	lightState = s;
}

LightState TrafficLight::getLightState()
{
	return lightState;
}