#ifndef TRAINSENSOR_H_H
#define TRAINSENSOR_H_H

class TrainSensor : public EventPublisher {
private:
	CentralCoordinationUnit* centralCoordinationUnit;
	bool isTrainComing();
	bool isTrainLeaving();

public:
	TrainSensor();
	void generateEvents();
};

#endif
