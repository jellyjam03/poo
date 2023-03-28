#include "Volvo.h"

double Volvo::getFuelCapacity()
{
	return 5.4;
}

double Volvo::getFuelConsumption()
{
	return 6.5;
}

double Volvo::getAvgSpeed(Weather w)
{
	if (w == sunny) return 60;
	if (w == rainy) return 30;
	return 25;
}

const char* Volvo::getCarName()
{
	return "Volvo Car";
}