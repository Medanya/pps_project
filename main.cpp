#include <iostream>
#include "CentralCoordinationUnit.hpp"
#include "TrainSensor.hpp"
#include "VehicleDetector.hpp"

int main() {
	CentralCoordinationUnit &CCU = *CentralCoordinationUnit::getInstance();
	TrainSensor trainSensors[CentralCoordinationUnit::kNumberOfRailways];
	VehicleDetector *vehicleDetectors[CentralCoordinationUnit::kNumberOfLines];
	
	for (unsigned i = 0; i < CentralCoordinationUnit::kNumberOfRailways; ++i) {
		CCU.connectPublisher(&trainSensors[i]);
	}
	
	for (unsigned i = 0; i < CentralCoordinationUnit::kNumberOfLines; ++i) {
		vehicleDetectors[i] = new VehicleDetector(bool(i));
		CCU.connectPublisher(vehicleDetectors[i]);
	}
	
	CCU.eventLoop();
	
	return 0;
}
