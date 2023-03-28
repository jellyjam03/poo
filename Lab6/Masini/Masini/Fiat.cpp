#include "Fiat.h"

double Fiat::getFuelCapacity()
{
	return 3;
}

double Fiat::getFuelConsumption()
{
	return 6.7;
}

double Fiat::getAvgSpeed(Weather w)
{
	if (w == sunny) return 50;
	if (w == rainy) return 27;
	return 18;
}

const char* Fiat::getCarName()
{
	return "Fiat Car";
}