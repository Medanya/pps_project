#include "CentralCoordinationUnit.hpp"
#include "sdl.hpp"

void CentralCoordinationUnit::handleEvent(Event event) {
	if (manualControl)
		return;
	switch (event) {
		case TRAIN_COMING: {
			++trainComing;
			if (trainComing == 1) {
				boomBarrier[0].setBoomBarrierState(vehicleOnCrossing[0]);
				boomBarrier[1].setBoomBarrierState(vehicleOnCrossing[1]);
				for (unsigned i = 0; i < kNumberOfRailways; ++i)
					trainTrafficLights[i].setColor((vehicleOnCrossing[0] || vehicleOnCrossing[1]) ? TL_COLOR_RED : TL_COLOR_GREEN);
				for (unsigned i = 0; i < kNumberOfLines; ++i) {
					carTrafficLights[i].setColor(TL_COLOR_RED);
					pedestrianTrafficLights[i].setColor(TL_COLOR_RED);
				}
			}
			break;
		}
		case TRAIN_LEAVING: {
			--trainComing;
			if (trainComing == 0) {
				boomBarrier[0].setBoomBarrierState(true);
				boomBarrier[1].setBoomBarrierState(true);
				for (unsigned i = 0; i < kNumberOfRailways; ++i)
					trainTrafficLights[i].setColor(TL_COLOR_GREEN);
				for (unsigned i = 0; i < kNumberOfLines; ++i) {
					carTrafficLights[i].setColor(TL_COLOR_GREEN);
					pedestrianTrafficLights[i].setColor(TL_COLOR_GREEN);
				}
			}
			break;
		}
		case VEHICLE_ON_CROSSING_1:
			vehicleOnCrossing[0] = true;
			if (trainComing > 0) {
				boomBarrier[0].setBoomBarrierState(true);
				boomBarrier[1].setBoomBarrierState(vehicleOnCrossing[1]);
				for (unsigned i = 0; i < kNumberOfRailways; ++i)
					trainTrafficLights[i].setColor(TL_COLOR_RED);
				for (unsigned i = 0; i < kNumberOfLines; ++i) {
					carTrafficLights[i].setColor(TL_COLOR_RED);
					pedestrianTrafficLights[i].setColor(TL_COLOR_RED);
				}
			}
			else {
				for (unsigned i = 0; i < kNumberOfRailways; ++i)
					trainTrafficLights[i].setColor(TL_COLOR_GREEN);
				for (unsigned i = 0; i < kNumberOfLines; ++i) {
					carTrafficLights[i].setColor(TL_COLOR_GREEN);
					pedestrianTrafficLights[i].setColor(TL_COLOR_GREEN);
				}
			}
			break;
		case VEHICLE_LEAVING_1:
			vehicleOnCrossing[0] = false;
			if (trainComing > 0) {
				boomBarrier[0].setBoomBarrierState(false);
				boomBarrier[1].setBoomBarrierState(vehicleOnCrossing[1]);
				for (unsigned i = 0; i < kNumberOfRailways; ++i)
					trainTrafficLights[i].setColor(vehicleOnCrossing[1] ? TL_COLOR_RED : TL_COLOR_GREEN);
				for (unsigned i = 0; i < kNumberOfLines; ++i) {
					carTrafficLights[i].setColor(TL_COLOR_RED);
					pedestrianTrafficLights[i].setColor(TL_COLOR_RED);
				}
			}
			else {
				for (unsigned i = 0; i < kNumberOfRailways; ++i)
					trainTrafficLights[i].setColor(TL_COLOR_GREEN);
				for (unsigned i = 0; i < kNumberOfLines; ++i) {
					carTrafficLights[i].setColor(TL_COLOR_GREEN);
					pedestrianTrafficLights[i].setColor(TL_COLOR_GREEN);
				}
			}
			break;
		case VEHICLE_ON_CROSSING_2:
			vehicleOnCrossing[1] = true;
			if (trainComing > 0) {
				boomBarrier[0].setBoomBarrierState(vehicleOnCrossing[0]);
				boomBarrier[1].setBoomBarrierState(true);
				for (unsigned i = 0; i < kNumberOfRailways; ++i)
					trainTrafficLights[i].setColor(TL_COLOR_RED);
				for (unsigned i = 0; i < kNumberOfLines; ++i) {
					carTrafficLights[i].setColor(TL_COLOR_RED);
					pedestrianTrafficLights[i].setColor(TL_COLOR_RED);
				}
			}
			else {
				for (unsigned i = 0; i < kNumberOfRailways; ++i)
					trainTrafficLights[i].setColor(TL_COLOR_GREEN);
				for (unsigned i = 0; i < kNumberOfLines; ++i) {
					carTrafficLights[i].setColor(TL_COLOR_GREEN);
					pedestrianTrafficLights[i].setColor(TL_COLOR_GREEN);
				}
			}
			break;
		case VEHICLE_LEAVING_2:
			vehicleOnCrossing[1] = false;
			if (trainComing > 0) {
				boomBarrier[0].setBoomBarrierState(vehicleOnCrossing[0]);
				boomBarrier[1].setBoomBarrierState(false);
				for (unsigned i = 0; i < kNumberOfRailways; ++i)
					trainTrafficLights[i].setColor(vehicleOnCrossing[0] ? TL_COLOR_RED : TL_COLOR_GREEN);
				for (unsigned i = 0; i < kNumberOfLines; ++i) {
					carTrafficLights[i].setColor(TL_COLOR_RED);
					pedestrianTrafficLights[i].setColor(TL_COLOR_RED);
				}
			}
			else {
				for (unsigned i = 0; i < kNumberOfRailways; ++i)
					trainTrafficLights[i].setColor(TL_COLOR_GREEN);
				for (unsigned i = 0; i < kNumberOfLines; ++i) {
					carTrafficLights[i].setColor(TL_COLOR_GREEN);
					pedestrianTrafficLights[i].setColor(TL_COLOR_GREEN);
				}
			}
			break;
	}
}

void CentralCoordinationUnit::eventLoop() {
	SDL::init();
	while (true) {
		for (EventPublisher *publisher : connectedPublishers)
			publisher->generateEvents();
		if (SDL::loop_step())
			break;
	}
}

void CentralCoordinationUnit::connectPublisher(EventPublisher *publisher) {
	connectedPublishers.insert(publisher);
}

void CentralCoordinationUnit::disconnectPublisher(EventPublisher *publisher) {
	connectedPublishers.erase(publisher);
}

CentralCoordinationUnit *CentralCoordinationUnit::getInstance() {
	static CentralCoordinationUnit instance; // Шаблон Singleton
	return &instance;
}

bool CentralCoordinationUnit::getManualControl() const {
	return manualControl;
}

void CentralCoordinationUnit::setManualControl(bool flag) {
	manualControl = flag;
}
