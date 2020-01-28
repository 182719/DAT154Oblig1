struct LightState {
    bool red;
    bool yellow;
    bool green;
};

class TrafficLight {
    LightState state;
public:
    TrafficLight(LightState s) {
        state = s;
    }
    void setLightState(LightState s) {
        state = s;
    }
    LightState getLightState() {
        return state;
    }
};