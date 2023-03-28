#include "BMW.h"

double BMW::getFuelCapacity()
{
	return 4.6;
}

double BMW::getFuelConsumption()
{
	return 7;
}

double BMW::getAvgSpeed(Weather w)
{
	if (w == sunny) return 120;
	if (w == rainy) return 60;
	return 50;
}

const char* BMW::getCarName()
{
	return "BMW Car";
}