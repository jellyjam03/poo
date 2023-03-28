#pragma once
#include "Weather.h"


class Car
{
public:

	virtual double getFuelCapacity() = 0;
	virtual double getFuelConsumption() = 0;
	virtual double getAvgSpeed(Weather w) = 0;
	virtual const char* getCarName() = 0;
};