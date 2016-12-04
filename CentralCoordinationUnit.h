#include <set>
#include <vector>
#include <string>

#include "VehicleDetector.h"
#include "ElectricitySupplyDetector.h"
#include "BoomBarrier.h"
#include "TrainComingSensor.h"
#include "TrainLeavingSensor.h"
#include "TrafficLight.h"

#define 0 red
#define 1 green

#define 0 down
#define 1 up

class CentralCoordinationUnit {
private:
	std::vector<EventPublisher *> connectedPublishers; // Шаблон Event Channel1
	std::vector<BoomBarrier *> barrier;
	TrafficLight * trafficLightTrain;
	std::vector<TrafficLight *> trafficLightVehicle;
	std::vector<VehicleDetector *> vehicleDetector;
	static CentralCoordinationUnit instance; // Шаблон Singleton
	int numberOfTrains;
	bool currentLane;

public:
	void handleEvent(Event event);
	void eventLoop();
	void connectPublisher(EventPublisher *publisher);
	void disconnectPublisher(EventPublisher *publisher);
	CentralCoordinationUnit *getInstance();
};
