#include <iostream>
#include "Canvas.h"

using namespace std;

int main()
{
 Canvas a(20, 20);
 a.FillRect(1, 2, 7, 6, '@');
 a.Print();
 return 0;
}
