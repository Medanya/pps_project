#include "BoomBarier.hpp"

bool BoomBarrier::getBoomBarrierState() const {
	return state;
}

void BoomBarrier::setBoomBarrierState(bool state) {
	this->state = state;
}
