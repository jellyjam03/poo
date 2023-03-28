#include "Seat.h"

double Seat::getFuelCapacity()
{
	return 6.9;
}

double Seat::getFuelConsumption()
{
	return 8;
}

double Seat::getAvgSpeed(Weather w)
{
	if (w == sunny) return 50;
	if (w == rainy) return 20;
	return 15;
}

const char* Seat::getCarName()
{
	return "Seat Car";
}