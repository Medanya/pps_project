<<<<<<< HEAD
#include <iostream>
#include <string>

#include "CentralCoordinationUnit.h"
#include "VehicleDetector.h"
#include "TrainComingSensor.h"
#include "TrainLeavingSensor.h"
#include "BoomBarrier.h"
#include "TrafficLight.h"
=======
#include <iostream>generateEvents(Event event)
>>>>>>> 18109425b78335d1b91edf2be7c7711584f26f8f

using namespace std;

int main ()
{
	CentralCoordinationUnit CCU = CentralCoordinationUnit();
	// надо всё создать и дать ссылки друг на друга, возможно, это и есть градуировка????
<<<<<<< HEAD
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
=======
	while(true)
	{
		switch (event) {
			case TRAIN_COMING:
				trainSensor->generateEvents(Event event);
			case TRAIN_LEAVING:
				
>>>>>>> 18109425b78335d1b91edf2be7c7711584f26f8f
	}
	return 0;
}
