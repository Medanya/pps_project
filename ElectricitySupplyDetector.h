/**
 * @(#) ElectricitySupplyDetector.h
 */

#ifndef ELECTRICITYSUPPLYDETECTOR_H_H
#define ELECTRICITYSUPPLYDETECTOR_H_H

#include "Graduation.h"
<<<<<<< HEAD
#include "CentralCoordinationUnit.h"

class ElectricitySupplyDetector: public Graduation
=======
#include <string>
class ElectricitySupplyDetector: Graduation
>>>>>>> 18109425b78335d1b91edf2be7c7711584f26f8f
{
	
public:
	void generateEvents();
<<<<<<< HEAD
	void EmergencyEvent( );
=======
	void EmergencyEvent();
>>>>>>> 18109425b78335d1b91edf2be7c7711584f26f8f
	bool GetElectricityState( );
	void Graduate( );

protected:
	string property;
	CentralCoordinationUnit* centralCoordinationUnit;
	
private:
	Boolean isElectrified;
	
	
};

#endif
