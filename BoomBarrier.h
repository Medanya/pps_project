/**
 * @(#) BoomBarrier.h
 */

#ifndef BOOMBARRIER_H_H
#define BOOMBARRIER_H_H

#include "ElectricitySupplyDetector.h"
class BoomBarrier: ElectricitySupplyDetector
{
	
public:
	void Graduate( );
	void SetBoomBarrierState(bool state);
	
private:
	bool isOpen;
	
	
};

#endif
