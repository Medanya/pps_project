#pragma once

#include "EventPublisher.hpp"
#include "SelfDefectFinder.hpp"

class TrainSensor : public EventPublisher, public SelfDefectFinder {
private:
	bool trainComingState;
	bool trainLeavingState;

	bool isTrainComing();
	bool isTrainLeaving();

public:
	TrainSensor();
	void generateEvents();
};
