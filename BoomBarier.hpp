#pragma once

#include "SelfDefectFinder.hpp"

class BoomBarrier : public SelfDefectFinder {
private:
	bool state;

public:
	void setBoomBarrierState(bool);
	bool getBoomBarrierState() const;
};
