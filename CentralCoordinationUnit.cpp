#include "CentralCoordinationUnit.hpp"

CentralCoordinationUnit CentralCoordinationUnit::instance;

void CentralCoordinationUnit::handleEvent(Event event) {
	
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
