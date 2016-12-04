#include "TrainComingSensor.h"


void TrainComingSensor::generateEvents()
{
	centralCoordinationUnit->handleEvents(TRAIN_COMING);
}
