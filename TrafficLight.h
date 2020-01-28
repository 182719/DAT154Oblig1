#pragma once

enum class LightState {
    red=0,redYellow,yellow,green
};

class TrafficLight {
    LightState lightState;
public:
    TrafficLight(LightState s = LightState::red);

    void setLightState(LightState s);

    LightState getLightState();
};