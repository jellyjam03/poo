#pragma once
#include <iostream>
using namespace std;


template <typename T>
class Tree
{
	typedef bool (*funcPointer) (T, T);
	typedef bool (*funcPointer2) (Tree<T>&, Tree<T>&);

	T info;
	int cnt; //number of children
	int order; //the exponent of 2 that represents the memory allocated for the list of children
	Tree<T>** children;

public:
	static bool Equals(T a, T b);

	Tree();
	Tree(T value);
	Tree(Tree<T>& x);
	Tree(Tree<T>&& x);
	~Tree();
	void PrintInfo();
	Tree<T>* AddNode(T value);
	Tree<T>* GetNode(int index);
	Tree<T>* GetRoot();
	T& GetVal();
	void DeleteNode(int index);
	Tree<T>* Find(funcPointer Equals, T value);
	Tree<T>* Insert(int index, T value);
	Tree<T>* Sort(funcPointer2 cmp);
	Tree<T>* Sort();
	int Count();

	friend bool operator< (Tree<T>& a, Tree<T>& b);
};

template<typename T>
static bool Tree<T>::Equals(T a, T b)
{
	return a == b;
}

template<typename T>
Tree<T>::Tree()
{
	this->children = nullptr;
	this->cnt = 0;
	this->info = (T)0;
	this->order = 0;
	this->size = 0;
}

template<typename T>
Tree<T>::Tree(T value)
{
	this->children = nullptr;
	this->cnt = 0;
	this->info = value;
	this->order = 0;
}

template<typename T>
Tree<T>::Tree(Tree<T>& x)
{
	this->cnt = x.cnt;
	this->info = x.info;
	this->order = x.order;
	if (x.children == nullptr)
	{
		this->children = nullptr;
		return;
	}

	int i;
	this->children = new Tree<T>*[(1 << (x.order))];
	for (i = 0; i < cnt; i++)
		this->children[i] = new Tree<T>(x.children[i]);
}

template<typename T>
Tree<T>::Tree(Tree<T>&& x)
{
	this->cnt = x.cnt;
	this->info = x.info;
	this->order = x.order;
	this->children = x.children;

	x.cnt = 0;
	x.info = (T)0;
	x.order = 0;
	x.children = nullptr;
}


template<typename T>
Tree<T>::~Tree()
{
	this->cnt = 0;
	this->info = (T)0;
	this->order = 0;
	if (children == nullptr) return;

	int i;
	for (i = 0; i < cnt; i++)
		delete children[i];
	delete[] children;
	//DeleteNode(this->root);
}

template<typename T>
Tree<T>* Tree<T>::AddNode(T value)
{
	this->cnt++;
	if (this->cnt == 1)
	{
		this->children = new Tree<T>*;
		this->children[0] = new Tree<T>(value);
		this->order = 0;
		return this->children[0];
	}
	if (this->cnt > (1 << this->order))
	{
		this->order++;
		Tree<T>** aux = new Tree<T>*[(1 << this->order)];
		int i;
		for (i = 0; i < this->cnt-1; i++)
			aux[i] = this->children[i];
		aux[i] = new Tree<T>(value);
		delete[] this->children;
		this->children = aux;
		return this->children[this->cnt - 1];
	}
	this->children[this->cnt] = new Tree<T>(value);
	return this->children[this->cnt - 1];
}

template<typename T>
Tree<T>* Tree<T>::GetNode(int index)
{

	if (!(0 <= index && index < cnt)) return nullptr;
	return this->children[index];
}

template<typename T>
Tree<T>* Tree<T>::GetRoot()
{
	return this;
}

template<typename T>
T& Tree<T>::GetVal()
{
	return info;
}

template<typename T>
void Tree<T>::DeleteNode(int index)
{
	if (index >= cnt || index < 0) return;
	if (this->children == nullptr) return;

	int i;
	delete this->children[index];
	for (i = index; i < cnt - 1; i++)
		children[i] = children[i + 1];
	cnt--;
	if (cnt < (1 << (order-1)))
	{
		Tree<T>** aux = new Tree<T>*[(1 << (order - 1))];
		order--;
		for (i = 0; i < cnt; i++)
			aux[i] = children[i];
		delete[] children;
		children = aux;
	}
}

template<typename T>
Tree<T>* Tree<T>::Find(funcPointer Equals, T value)
{
	if (Equals(value, info)) return this;

	int i;
	Tree<T>* p;
	for (i = 0; i < cnt; i++)
	{
		p = children[i]->Find(Equals, value);
		if (p != nullptr)
			return p;
	}

	return nullptr;
}

template<typename T>
void Tree<T>::PrintInfo()
{
	cout << info << '\n';
}

template<typename T>
Tree<T>* Tree<T>::Insert(int index, T value)
{
	if (!(0 <= index && index < cnt)) return nullptr;

	int i;
	
	if (cnt + 1 > (1 << (order)))
	{
		Tree<T>** aux = new Tree<T>* [(1 << order+1)];
		for (i=0; i<cnt; i++)
			aux[i] = children[i];
		delete[] children;
		children = aux;
	}

	Tree<T>* cop1 = new Tree<T>(value), *cop2;
	for (i = index; i < cnt; i++)
	{
		cop2 = children[i];
		children[i] = cop1;
		cop1 = cop2;
	}
	children[i] = cop1;
	cnt++;
	return children[index];
}

template<typename T>
int Tree<T>::Count()
{
	int sum = 0, i;
	for (i = 0; i < cnt; i++)
		sum = sum + 1 + children[i]->Count();
	return sum;
}

template<typename T>
Tree<T>* Tree<T>::Sort(funcPointer2 cmp)
{
	Tree<T>* aux;
	int i;
	bool gasit;

	do
	{
		gasit = 0;
		for (i=0; i<cnt-1; i++)
			if (cmp(*children[i], *children[i + 1]) == 0)
			{
				gasit = 1;
				aux = children[i];
				children[i] = children[i + 1];
				children[i + 1] = aux;
			}
	} while (gasit);

	return this;
}

//template<typename T>
//bool Tree<T>::operator< (Tree<T>& a)
//{
//	return this->info < a->info;
//}

template<typename T>
bool operator< (Tree<T>& a, Tree<T>& b)
{
	return a.GetVal() < b.GetVal();
}

template<typename T>
Tree<T>* Tree<T>::Sort()
{
	return this->Sort(operator<);
}