/**
 * @(#) TrafficLight.h
 */

#ifndef TRAFFICLIGHT_H_H
#define TRAFFICLIGHT_H_H

#include "ElectricitySupplyDetector.h"
class TrafficLight: ElectricitySupplyDetector
{
	
public:
	void Graduate( );
	void setTrafficLightState(bool newSign);
	bool getTrafficLightState();
	void showTrafficLight();
	
private:
	bool Sign;
	
	
};

#endif
