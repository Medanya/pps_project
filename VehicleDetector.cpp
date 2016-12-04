#include "VehicleDetector.hpp"
#include "CentralCoordinationUnit.hpp"

VehicleDetector::VehicleDetector(unsigned _side) : vehicleOnCrossing(false), side(_side) {
	enable(); // Включаем себя при создании
}

void VehicleDetector::generateEvents() {
	bool newState = isVehicleOnCrossing();
	if (newState != vehicleOnCrossing) {
		if (newState == true)
			CentralCoordinationUnit::getInstance()->handleEvent(side == 0 ? VEHICLE_ON_CROSSING_1 : VEHICLE_ON_CROSSING_2);
		if (newState == false)
			CentralCoordinationUnit::getInstance()->handleEvent(side == 0 ? VEHICLE_LEAVING_1 : VEHICLE_LEAVING_2);
	}
	vehicleOnCrossing = newState;
}

bool VehicleDetector::isVehicleOnCrossing() {
	return false;
}
