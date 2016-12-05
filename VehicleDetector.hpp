#pragma once

#include "EventPublisher.hpp"
#include "SelfDefectFinder.hpp"

class VehicleDetector : public EventPublisher, public SelfDefectFinder {
private:
	bool vehicleOnCrossing;
	unsigned side;

	bool isVehicleOnCrossing();

public:
	VehicleDetector(unsigned side);
	void generateEvents();
};
