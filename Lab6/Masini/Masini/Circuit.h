#pragma once
#include "Car.h"
#include <iostream>

using namespace std;

class Circuit
{
	struct participant
	{
		Car* car;
		double time;
	} *array; //vecorul de masini cu timpul asociat
	int carCnt;

	double length;
	Weather weather;

public:

	Circuit();
	Circuit(participant* p, const int size);
	Circuit(Car** const p, const int size);
	~Circuit();
	Circuit(const Circuit& circuit);
	Circuit(Circuit&& circuit);
	void SetLength(const double l);
	void SetWeather(const Weather w);
	double GetLength();
	Weather GetWeather();
	void AddCar(Car* const c);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();


};
