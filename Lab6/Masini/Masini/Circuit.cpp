#include "Circuit.h"

Circuit::Circuit()
{
	array = nullptr;
	length = 0;
	weather = sunny;
	carCnt = 0;
}

Circuit::Circuit(participant* p, const int size)
{
	array = new participant[size];
	int i;
	for (i = 0; i < size; i++)
		array[i] = p[i];
	length = 0;
	weather = sunny;
	carCnt = size;
}

Circuit::Circuit(Car** const p, const int size)
{
	array = new participant[size];
	int i;
	for (i = 0; i < size; i++)
	{
		array[i].car = p[i];
		array[i].time = 0;
	}
	length = 0;
	weather = sunny;
	carCnt = size;
}

Circuit::~Circuit()
{
	if (array != nullptr) delete[] array;
	length = 0;
	weather = sunny;
	carCnt = 0;
}

Circuit::Circuit(const Circuit& circuit)
{
	if (array != nullptr) delete[] array;
	this->array = new participant[circuit.carCnt];
	this->carCnt = circuit.carCnt;
	this->length = circuit.length;
	this->weather = circuit.weather;
}

Circuit::Circuit(Circuit&& circuit)
{
	this->array = circuit.array;
	circuit.array = nullptr;
	this->carCnt = circuit.carCnt;
	this->length = circuit.length;
	this->weather = circuit.weather;

}

void Circuit::SetLength(const double l)
{
	this->length = l;
}

void Circuit::SetWeather(const Weather w)
{
	this->weather = w;
}

double Circuit::GetLength()
{
	return this->length;
}

Weather Circuit::GetWeather()
{
	return this->weather;
}

void Circuit::AddCar(Car* const c)
{
	participant* temp = new participant[this->carCnt + 1];
	int i;
	for (i = 0; i < this->carCnt; i++)
		temp[i] = this->array[i];
	temp[this->carCnt].car = c;
	temp[this->carCnt].time = 0;

	if (this->array != nullptr) delete[] this->array;
	array = temp;
	this->carCnt++;
}

void Circuit::Race()
{
	int i;
	for (i = 0; i < this->carCnt; i++)
		if (this->array[i].car->getFuelCapacity() * 100 / this->array[i].car->getFuelConsumption() < this->length)
			this->array[i].time = -1;
		else
			this->array[i].time = this->length / this->array[i].car->getAvgSpeed(this->weather);

	bool gasit;
	participant aux;
	do
	{
		gasit = 0;
		for (i=0; i<this->carCnt-1; i++)
			if ((this->array[i].time  > this->array[i + 1].time && this->array[i+1].time != -1) || (this->array[i].time == -1 && this->array[i + 1].time != -1))
			{
				gasit = 1;
				aux = array[i];
				array[i] = array[i + 1];
				array[i + 1] = aux;
			}
	} while (gasit);
}

void Circuit::ShowFinalRanks()
{
	int i;

	if (this->array[0].time == -1)
	{
		cout << "No cars finished!\n\n";
		return;
	}

	cout << "Final Ranks:\n\n";

	for (i = 0; i < this->carCnt; i++)
		if (this->array[i].time != -1)
			cout << i + 1 << ". " << this->array[i].car->getCarName() << " finished in " << this->array[i].time << " hour(s)\n";

	cout << '\n';
}

void Circuit::ShowWhoDidNotFinish()
{
	int i;

	if (this->array[this->carCnt - 1].time != -1)
	{
		cout << "All of the cars finished the race!\n\n";
		return;
	}

	cout << "Did not finish:\n\n";

	for (i = this->carCnt - 1; this->array[i].time == -1; i++)
		cout << this->carCnt - i << ". " << this->array[i].car->getCarName() << '\n';

	cout << '\n';
}