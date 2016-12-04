#include <iostream>
#include "CentralCoordinationUnit.hpp"
#include "TrainSensor.hpp"

int main() {
	CentralCoordinationUnit CCU = CentralCoordinationUnit();
	TrainSensor trainSensors[CentralCoordinationUnit::kNumberOfRailways];
	
	for (unsigned i = 0; i < CentralCoordinationUnit::kNumberOfRailways; ++i) {
		CCU.connectPublisher(&trainSensors[i]);
	}
	
	
	
	CCU.eventLoop();
	
	return 0;
}
