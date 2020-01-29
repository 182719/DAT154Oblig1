#pragma once

typedef struct {
    bool red;
    bool yellow;
    bool green;
} LightState;

class TrafficLight {
    LightState lightState[4];
    int stateNumber;
public:
    TrafficLight(int s);

    void nextState();

    LightState getCurrentState();
};