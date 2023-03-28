#pragma once
#include "Car.h"

class RangeRover : public Car
{
public:
	double getFuelCapacity();
	double getFuelConsumption();
	double getAvgSpeed(Weather w);
	const char* getCarName();
};
