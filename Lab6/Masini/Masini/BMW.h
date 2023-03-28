#pragma once
#include "Car.h"

class BMW : public Car
{
public:
	double getFuelCapacity();
	double getFuelConsumption();
	double getAvgSpeed(Weather w);
	const char* getCarName();
};