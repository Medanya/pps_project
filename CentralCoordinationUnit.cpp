#include "CentralCoordinationUnit.hpp"

CentralCoordinationUnit CentralCoordinationUnit::instance;

void CentralCoordinationUnit::handleEvent(Event event) {
	/*switch (event) {
		case TRAIN_COMING: {
			trainComing = true;
			unsigned i = 0;
			for (; i < kNumberOfRailways; ++i)
				if (vehicleOnCrossing[i])
					break;
			if (i < kNumberOfRailways) {
				
			}
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
	}*/
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
