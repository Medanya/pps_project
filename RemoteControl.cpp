#include "RemoteControl.hpp"
#include "EventPublisher.hpp"

void RemoteControl::setBoomBarrierState(int n, bool state) {
	CCU->boomBarrier[n].setBoomBarrierState(state);
}

void RemoteControl::setTrainTrafficLightColor(int n, TrafficLightColor color) {
	CCU->trainTrafficLights[n].setColor(color);
}

void RemoteControl::setCarTrafficLightColor(int n, TrafficLightColor color) {
	CCU->carTrafficLights[n].setColor(color);
}

void RemoteControl::setPedestrianTrafficLightColor(int n, TrafficLightColor color) {
	CCU->pedestrianTrafficLights[n].setColor(color);
}

std::vector<SelfDefectFinder *> RemoteControl::getDefectiveComponents() {
	std::vector<SelfDefectFinder *> defective;
	for (unsigned i = 0; i < CentralCoordinationUnit::kNumberOfRailways; ++i)
		if (CCU->trainTrafficLights[i].hasDefect())
			defective.push_back(&CCU->trainTrafficLights[i]);
	for (unsigned i = 0; i < CentralCoordinationUnit::kNumberOfLines; ++i) {
		if (CCU->carTrafficLights[i].hasDefect())
			defective.push_back(&CCU->carTrafficLights[i]);
		if (CCU->pedestrianTrafficLights[i].hasDefect())
			defective.push_back(&CCU->pedestrianTrafficLights[i]);
	}
	for (EventPublisher *publisher : CCU->connectedPublishers) {
		SelfDefectFinder *def = reinterpret_cast<SelfDefectFinder *>(publisher);
		if (def->hasDefect()) {
			publisher->disable();
			defective.push_back(def);
		}
	}
	return defective;
}

void RemoteControl::takeManualControl() {
	CCU->setManualControl(true);
}

void RemoteControl::returnToAutomaticControl() {
	CCU->setManualControl(false);
}
