/**
 * @(#) ElectricitySupplyDetector.h
 */

#ifndef ELECTRICITYSUPPLYDETECTOR_H_H
#define ELECTRICITYSUPPLYDETECTOR_H_H

#include "Graduation.h"
class ElectricitySupplyDetector: Graduation
{
	
public:
	void EmergencyEvent( );
	void GetElectricityState( );
	void Graduate( );
	
private:
	Boolean isElectrified;
	
	
};

#endif
