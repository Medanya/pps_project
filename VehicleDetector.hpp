#pragma once

#include "EventPublisher.hpp"

class VehicleDetector : public EventPublisher {
private:
	bool vehicleOnCrossing;
	unsigned side;

	bool isVehicleOnCrossing();

public:
	VehicleDetector(unsigned side);
	void generateEvents();
};
