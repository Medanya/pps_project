#pragma once

#include <set>
#include <vector>
#include "Event.hpp"
#include "EventPublisher.hpp"
#include "BoomBarier.hpp"
#include "TrafficLight.hpp"

class CentralCoordinationUnit {
private:
	static const unsigned kNumberOfRailways = 4;
	
	std::set<EventPublisher *> connectedPublishers; // Шаблон Event Channel
	BoomBarrier *boomBarrier[2];
	TrafficLight *trainTrafficLights[kNumberOfRailways];
	TrafficLight *carTrafficLights[kNumberOfRailways];
	TrafficLight *pedestrianTrafficLights[kNumberOfRailways];
	static CentralCoordinationUnit instance; // Шаблон Singleton
	bool trainComing;
	bool vehicleOnCrossing[2];

public:
	void handleEvent(Event event);
	void eventLoop();
	void connectPublisher(EventPublisher *publisher);
	void disconnectPublisher(EventPublisher *publisher);
	CentralCoordinationUnit *getInstance();
};
