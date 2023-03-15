#include <cstdlib>
#include <ctime>
#include <cstdarg>
#include <cstring>
#include <iostream>

class Sort

{

    int n;
    int *a;

    void rev();
    // add data members

public:

    Sort(int nr, int minim, int maxim);

    Sort();

    Sort(int v[], int nr);

    Sort(int nr, ...);

    Sort(char s[]);
    // add constuctors

    void InsertSort(bool ascendent=false);

    void QuickSort(bool ascendent=false);

    void BubbleSort(bool ascendent=false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);

};
