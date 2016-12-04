#include "EventPublisher.hpp"
#include "CentralCoordinationUnit.hpp"

void EventPublisher::enable() {
	CentralCoordinationUnit::getInstance()->connectPublisher(this);
}

void EventPublisher::disable() {
	CentralCoordinationUnit::getInstance()->disconnectPublisher(this);
}
