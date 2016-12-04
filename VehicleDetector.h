#ifndef VEHICLEDETECTOR_H_H
#define VEHICLEDETECTOR_H_H

#include "CentralCoordinationUnit.h"

class VehicleDetector: public ElectricitySupplyDetector {

private:
        bool currentLane;
	vector<bool> isVehicle;
	
public:
	bool getCurrentLane();
	void setCurrentLane(bool newLane);
	bool getState(int index);
	void setState(bool state, int index);
}

#endif
