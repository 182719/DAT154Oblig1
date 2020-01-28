#include "TrafficLight.h"

TrafficLight::TrafficLight() : lightState{ LightState{ true, false, false },
LightState { true, true, false },
LightState { false, false, true },
LightState { false, true, false }}, stateNumber(0)
{
}

void TrafficLight::nextState()
{
	stateNumber = (stateNumber + 1) % 4;
}

LightState TrafficLight::getCurrentState()
{
	return lightState[stateNumber];
}
