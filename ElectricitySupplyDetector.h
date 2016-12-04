/**
 * @(#) ElectricitySupplyDetector.h
 */

#ifndef ELECTRICITYSUPPLYDETECTOR_H_H
#define ELECTRICITYSUPPLYDETECTOR_H_H

#include "Graduation.h"
#include "CentralCoordinationUnit.h"

class ElectricitySupplyDetector: public Graduation
{
	
public:
	void generateEvents();
	void EmergencyEvent( );
	bool GetElectricityState( );
	void Graduate( );

protected:
	string property;
	CentralCoordinationUnit* centralCoordinationUnit;
	
private:
	Boolean isElectrified;
	
	
};

#endif
