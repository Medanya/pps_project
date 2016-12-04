#pragma once

class BoomBarrier {
private:
	bool state;

public:
	void setBoomBarrierState(bool);
	bool getBoomBarrierState() const;
};
