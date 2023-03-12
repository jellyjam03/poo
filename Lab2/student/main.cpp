#include <iostream>
#include "Global.h"

using namespace std;

int main()
{
 Student a, b;
 a.setNume("Rotariu George");
 a.setEng(9);
 a.setIst(4);
 a.setMat(7);
 b.setNume("Balteanu Sara");
 b.setEng(8);
 b.setIst(7);
 b.setMat(6);
 cout << "compar numele: " << comparNume(a, b) << '\n';
 cout << "compar notele eng: " << comparEng(a, b) << '\n';
 cout << "compar notele ist: " << comparIst(a, b) << '\n';
 cout << "compar notele mat: " << comparMat(a, b) << '\n';
 cout << "compar avg: " << comparAvg(a, b) << '\n';
 return 0;
}
