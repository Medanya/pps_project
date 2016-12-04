#include "CentralCoordinationUnit.hpp"

CentralCoordinationUnit CentralCoordinationUnit::instance;

void CentralCoordinationUnit::handleEvent(Event event) {
	switch (event) {
		case TRAIN_COMING: {
			trainComing = true;
			boomBarrier[0].setBoomBarrierState(vehicleOnCrossing[0]);
			boomBarrier[1].setBoomBarrierState(vehicleOnCrossing[1]);
			if (vehicleOnCrossing[0] || vehicleOnCrossing[1])
				for (unsigned i = 0; i < kNumberOfRailways; ++i)
					trainTrafficLights[i].
			break;
		}
		case TRAIN_LEAVING:
			trainComing = false;
			for (BoomBarrier *barrier : boomBarrierOut)
				barrier->setBoomBarrierState(true);
			for (BoomBarrier *barrier : boomBarrierIn)
				barrier->setBoomBarrierState(true);
			break;
		case VEHICLE_ON_CROSSING:
			vehicleOnCrossing = true;
			if (trainComing) {
				for (BoomBarrier *barrier : boomBarrierOut)
					barrier->setBoomBarrierState(true);
				for (BoomBarrier *barrier : boomBarrierIn)
					barrier->setBoomBarrierState(false);
			}
			else {
				for (BoomBarrier *barrier : boomBarrierOut)
					barrier->setBoomBarrierState(true);
				for (BoomBarrier *barrier : boomBarrierIn)
					barrier->setBoomBarrierState(true);
			}
			break;
		case VEHICLE_LEAVING:
			vehicleOnCrossing = false;
			if (trainComing) {
				for (BoomBarrier *barrier : boomBarrierOut)
					barrier->setBoomBarrierState(false);
				for (BoomBarrier *barrier : boomBarrierIn)
					barrier->setBoomBarrierState(false);
			}
			else {
				for (BoomBarrier *barrier : boomBarrierOut)
					barrier->setBoomBarrierState(true);
				for (BoomBarrier *barrier : boomBarrierIn)
					barrier->setBoomBarrierState(true);
			}
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

CentralCoordinationUnit *CentralCoordinationUnit::getInstance() {
	return &instance;
}
