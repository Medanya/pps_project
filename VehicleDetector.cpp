#include "VehicleDetector.h"
#include <iostream>


bool VehicleDetector::getCurrentLane() {
	return currentLane;
}

void VehicleDetector::setCurrentLane(bool newLane) {
	currentLane = newLane;
}

bool VehicleDetector::getState(int index) {
	return isVehicle[index];
}

void setState(bool state, int index) {
	isVehicle[index] = state;
}


void generateEvents() {
	bool currentLane;
	std::cin<<currentLane;
	isVehicle = !isVehicle;
	if (isVehicle) {
		centralCoordinationUnit->handleEvent(VEHICLE_LEAVING);
	}
}
