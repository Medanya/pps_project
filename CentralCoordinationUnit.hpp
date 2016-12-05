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
	bool vehicleOnCrossing[kNumberOfLines];

	CentralCoordinationUnit() : trainComing(0) {};

public:
	BoomBarrier boomBarrier[kNumberOfLines];
	TrafficLight trainTrafficLights[kNumberOfRailways];
	TrafficLight carTrafficLights[kNumberOfLines];
	TrafficLight pedestrianTrafficLights[kNumberOfLines];
	
	void handleEvent(Event event);
	void eventLoop();
	void connectPublisher(EventPublisher *publisher);
	void disconnectPublisher(EventPublisher *publisher);
	static CentralCoordinationUnit *getInstance();
};
