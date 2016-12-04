#pragma once

enum TrafficLightColor {
	TL_COLOR_RED = 0,
	TL_COLOR_GREEN
};

class TrafficLight {
private:
	TrafficLightColor color;

public:
	void setColor(TrafficLightColor color);
};
