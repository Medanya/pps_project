#include "RemoteControl.hpp"

void RemoteControl::setBoomBarrierState(int n, bool state) {
	CCU->boomBarrier[n].setBoomBarrierState(state);
}

void RemoteControl::setTrainTrafficLightColor(int n, TrafficLightColor color) {
	CCU->trainTrafficLights[n].setColor(color);
}
