#include "RangeRover.h"

double RangeRover::getFuelCapacity()
{
	return 8.5;
}

double RangeRover::getFuelConsumption()
{
	return 9;
}

double RangeRover::getAvgSpeed(Weather w)
{
	if (w == sunny) return 80;
	if (w == rainy) return 50;
	return 45;
}

const char* RangeRover::getCarName()
{
	return "Range Rover Car";
}