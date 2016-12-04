#ifndef TRAINSENSOR_H_H
#define TRAINSENSOR_H_H

class TrainSensor : public EventPublisher {

public:
	TrainSensor();
	void generateEvents();
};

#endif
