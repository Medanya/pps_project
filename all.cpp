#include <set>
#include <vector>
#include <string>

#define 0 red
#define 1 green

#define 0 down
#define 1 up

enum Event {
	TRAIN_COMING = 0,
	TRAIN_LEAVING,
	VEHICLE_ON_CROSSING,
	VEHICLE_LEAVING
};

class EventPublisher {
public:
	virtual void generateEvents() = 0;
	void enable();
	void disable();
};

	void generateEvents();
};


VehicleDetector::VehicleDetector() : vehicleOnCrossing(false) {
	enable(); // Включаем себя при создании
}

void VehicleDetector::generateEvents() {
	bool newState = isVehicleOnCrossing();
	if (newState != vehicleOnCrossing) {
		if (newState == true)
			CentralCoordinationUnit::getInstance()->handleEvent(VEHICLE_ON_CROSSING);
		if (newState == false)
			CentralCoordinationUnit::getInstance()->handleEvent(VEHICLE_LEAVING);
	}
	vehicleOnCrossing = newState;
}

void EventPublisher::enable() {
	CentralCoordinationUnit::getInstance()->connectPublisher(this);
}

void EventPublisher::disable() {
	CentralCoordinationUnit::getInstance()->disconnectPublisher(this);
}
