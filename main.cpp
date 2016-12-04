#include <iostream>
#include "CentralCoordinationUnit.hpp"

int main() {
	CentralCoordinationUnit CCU = CentralCoordinationUnit();
	CCU.eventLoop();
	
	return 0;
}
