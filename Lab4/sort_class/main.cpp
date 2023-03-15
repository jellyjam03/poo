#include <iostream>
#include "Sort.h"

using namespace std;

int main()
{
    Sort a(10, 15, 100);
    a.Print();
    a.BubbleSort();
    a.Print();
    return 0;
}
