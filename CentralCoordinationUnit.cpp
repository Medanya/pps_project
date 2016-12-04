/**
 * @(#) CentralCoordinationUnit.cpp
 */


#include "CentralCoordinationUnit.h"

void CentralCoordinationUnit::handleEvent(Event event) {
	switch (event) {
		case TRAIN_COMING:
			numberOfTrains++;
			trafficLightVehicle->setTrafficLightState(red);
			for (int i = 0; i < 2; ++i) {
				if (!vehicleDetector->getState(i)) {
					barrier->setBoomBarrierState(down);
				}
			}
			trafficLightTrain->setTrafficLightState(!vehicleDetector->getState(0) || vehicleDetector->getState(1));
			break;
		case TRAIN_LEAVING:
			numberOfTrains--;
			if (numberOfTrains == 0) {
				for (int i = 0; i < 2; ++i) {
					barrier->setBoomBarrierState(up);
				}
				trafficLightTrain->setTrafficLightState(green);
			}
			break;
		case VEHICLE_LEAVING:
			if (numberOfTrains > 0) {
				barrier[i]->setBoomBarrierState(down);
			}
			trafficLightTrain->setTrafficLightState(!vehicleDetector->getState(0) || vehicleDetector->getState(1));
			break;
	}
}

void CentralCoordinationUnit::eventLoop() {
	while (true) {
		for (EventPublisher *publisher : connectedPublishers)
			publisher->generateEvents();
	}
}

void CentralCoordinationUnit::connectPublisher(EventPublisher *publisher) {
	connectedPublishers.insert(publisher);
}

void CentralCoordinationUnit::disconnectPublisher(EventPublisher *publisher) {
	connectedPublishers.erase(publisher);
}

CentralCoordinationUnit* CentralCoordinationUnit::getInstance() {
	return &instance;
}

