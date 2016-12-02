#include "TrainSensor.h"

void TrainSensor::generateEvents(Event event) // вообще по идее ему должен прилетать не event, а непосредственно сигнал с клавиатуры
{
	centralCoordinationUnit->handleEvent(event);
}




