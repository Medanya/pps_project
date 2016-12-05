#pragma once

#include <set>
#include <vector>
#include "Event.hpp"
#include "EventPublisher.hpp"
#include "BoomBarier.hpp"
#include "TrafficLight.hpp"

class CentralCoordinationUnit {
private:
	std::set<EventPublisher *> connectedPublishers; // Шаблон Event Channel

public:
	static const unsigned kNumberOfRailways = 4;
	static const unsigned kNumberOfLines = 2;
	
private:
	int trainComing;
	bool manualControl;
	bool vehicleOnCrossing[kNumberOfLines];

	CentralCoordinationUnit() : trainComing(0), manualControl(false) {};

public:
	BoomBarrier boomBarrier[kNumberOfLines];
	TrafficLight trainTrafficLights[kNumberOfRailways];
	TrafficLight carTrafficLights[kNumberOfLines];
	TrafficLight pedestrianTrafficLights[kNumberOfLines];
	
	bool getManualControl() const;
	void setManualControl(bool flag);
	void handleEvent(Event event);
	void eventLoop();
	void connectPublisher(EventPublisher *publisher);
	void disconnectPublisher(EventPublisher *publisher);
	static CentralCoordinationUnit *getInstance();
};
