#include <iostream>
#include "Numberlist.h"

using namespace std;

int main()
{
 NumberList *a = new NumberList();

 a->Init();
 a->Add(3);
 a->Add(5);
 a->Add(100);
 a->Add(1);

 cout << "a list:\n\n";
 a->Print();
 a->Sort();
 cout<<"a sorted list:\n\n";
 a->Print();
 return 0;
}
