#pragma once

#include "SelfDefectFinder.hpp"
#include "TrafficLight.hpp"
#include "CentralCoordinationUnit.hpp"
#include <vector>

class RemoteControl {
private:
	CentralCoordinationUnit *CCU;
public:
	RemoteControl(CentralCoordinationUnit *_CCU) : CCU(_CCU) {};
	void takeManualControl();
	void returnToAutomaticControl();
	std::vector<SelfDefectFinder *> getDefectiveComponents();
	void setPedestrianTrafficLightColor(int n, TrafficLightColor color);
	void setTrainTrafficLightColor(int n, TrafficLightColor color);
	void setCarTrafficLightColor(int n, TrafficLightColor color);
	void setBoomBarrierState(int n, bool state);
	void graduate(SelfDefectFinder *device);
};
