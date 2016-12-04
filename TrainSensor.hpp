#pragma once

#include "EventPublisher.hpp"

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
