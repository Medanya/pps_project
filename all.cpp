#include <set>

enum Event {
	TRAIN_COMING = 0,
	TRAIN_LEAVING,
	VEHICLE_ON_CROSSING,
	VEHICLE_LEAVING
};

class CentralCoordinationUnit {
private:
	std::set<EventPublisher *> connectedPublishers; // Шаблон Event Channel1
	std::set<BoomBarrier *> boomBarrierIn;
	std::set<BoomBarrier *> boomBarrierOut;
	static CentralCoordinationUnit instance; // Шаблон Singleton
	bool trainComing;
	bool vehicleOnCrossing;

public:
	void handleEvent(Event event);
	void eventLoop();
	void connectPublisher(EventPublisher *publisher);
	void disconnectPublisher(EventPublisher *publisher);
	CentralCoordinationUnit *getInstance();
};

class BoomBarrier {
public:
	void setBoomBarrierState(bool);
};

class EventPublisher {
public:
	virtual void generateEvents() = 0;
	void enable();
	void disable();
};

class TrainSensor : public EventPublisher {
private:
	bool trainComingState;
	bool trainLeavingState;

	bool isTrainComing();
	bool isTrainLeaving();

public:
	TrainSensor();
	void generateEvents();
};

class VehicleDetector : public EventPublisher {
private:
	bool vehicleOnCrossing;

	bool isVehicleOnCrossing();

public:
	VehicleDetector();
	void generateEvents();
};

void CentralCoordinationUnit::handleEvent(Event event) {
	switch (event) {
		case TRAIN_COMING:
			trainComing = true;
			if (vehicleOnCrossing) {
				for (BoomBarrier *barrier : boomBarrierOut)
					barrier->setBoomBarrierState(true);
				for (BoomBarrier *barrier : boomBarrierIn)
					barrier->setBoomBarrierState(false);
			}
			else {
				for (BoomBarrier *barrier : boomBarrierOut)
					barrier->setBoomBarrierState(false);
				for (BoomBarrier *barrier : boomBarrierIn)
					barrier->setBoomBarrierState(false);
			}
			break;
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

CentralCoordinationUnit* CentralCoordinationUnit::getInstance() {
	return &instance;
}

TrainSensor::TrainSensor() : trainComingState(false), trainLeavingState(false) {
	enable(); // Включаем себя при создании
}

void TrainSensor::generateEvents() {
	bool newState;
	newState = isTrainComing();
	if (newState == true && trainComingState == false)
		CentralCoordinationUnit::getInstance()->handleEvent(TRAIN_COMING);
	trainComingState = newState;
	newState = isTrainLeaving();
	if (newState == true && trainLeavingState == false)
		CentralCoordinationUnit::getInstance()->handleEvent(TRAIN_LEAVING);
	trainLeavingState = newState;
}

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
