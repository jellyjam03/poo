#include "Tree.h"

bool egal(int a, int b)
{
	return a == b;
}

int main()
{
	Tree <int> *a = new Tree<int>(10);
	a->AddNode(5);
	/*a->GetNode(0)->PrintInfo();
	a->Find(egal, 5)->PrintInfo();*/
	a->AddNode(7);
	a->Insert(1, 6);
	a->GetNode(1)->AddNode(11);
	a->Insert(2, 0);

	a->Sort();
	for (int i = 0; i < 4; i++)
		a->GetNode(i)->PrintInfo();
	return 0;
}