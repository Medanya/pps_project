#include "CentralCoordinationUnit.hpp"
#include "TrainSensor.hpp"

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

bool TrainSensor::isTrainComing() {
	return false;
}

bool TrainSensor::isTrainLeaving() {
	return false;
}
