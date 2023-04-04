#include <iostream>

using namespace std;

float operator"" _Kelvin(const char*);
float operator"" _Fahrenheit(const char*);

int main()
{
	float a = 300_Kelvin;
	float b = 120_Fahrenheit;

	cout << a << ' ' << b;

	return 0;
}

float operator"" _Kelvin(const char* x)// (F-32)/1.8
{
	float value=0;
	while (*(x) != 0)
	{
		value = value * 10 + *(x)-'0';
		x++;
	}

	value = value - 273.15;
	return value;
}

float operator"" _Fahrenheit(const char* x)// K-273.15
{
	float value = 0;
	while (*(x) != 0)
	{
		value = value * 10 + *(x)-'0';
		x++;
	}

	value = (value - 32) / 1.8;
	return value;
}