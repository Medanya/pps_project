#pragma once

#include "SelfDefectFinder.hpp"

enum TrafficLightColor {
	TL_COLOR_RED = 0,
	TL_COLOR_GREEN
};

class TrafficLight : public SelfDefectFinder {
private:
	TrafficLightColor color;

public:
	void setColor(TrafficLightColor color);
};
