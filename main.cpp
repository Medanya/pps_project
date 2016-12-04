#include <iostream>
#include <string>

#include "CentralCoordinationUnit.h"
#include "VehicleDetector.h"
#include "TrainComingSensor.h"
#include "TrainLeavingSensor.h"
#include "BoomBarrier.h"
#include "TrafficLight.h"

using namespace std;

int main ()
{
	CentralCoordinationUnit CCU = CentralCoordinationUnit();
	// надо всё создать и дать ссылки друг на друга, возможно, это и есть градуировка????
	string event;
	std::cin<<event;
	while(true)
	{
		switch (event) {
			case "TC":
				trainComingSensor->generateEvents();
			case "TL":
				trainLeavingSensor->generateEvents();
			case "VC" || "VL":
				vehicleDetector->generateEvents();
		}				
	}
	return 0;
}
