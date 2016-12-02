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
	void setBoomBarrierState(bool state);
	bool getBoomBarrierState();
	
private:
	bool isOpen;
};

#endif
