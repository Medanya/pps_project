#pragma once

class EventPublisher {
public:
	virtual void generateEvents() = 0;
	void enable();
	void disable();
};
