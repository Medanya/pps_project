#include "TrainLeavingSensor.h"


void TrainLeavingSensor::generateEvents()
{
	centralCoordinationUnit->handleEvents(TRAIN_COMING);
}
