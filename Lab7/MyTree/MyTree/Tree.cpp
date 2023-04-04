//#include "Tree.h"
//
//template<typename T>
//Tree<T>::Tree()
//{
//	this->root = nullptr;
//}
//
//template<typename T>
//Tree<T>::~Tree()
//{
//	DeleteNode(this->root);
//}
//
//template<typename T>
//Node<T>* Tree<T>::CreateNode(T value)
//{
//	Node<T>* aux = new Node<T>;
//	aux->info = value;
//	aux->children = nullptr;
//	aux->cnt = 0;
//	return aux;
//}
//
//template<typename T>
//Node<T>* Tree<T>::AddNode(Node<T>* parent, T value)
//{
//	if (parent == nullptr)
//		if (this->root != nullptr) return nullptr;
//		else
//		{
//			this->root = new Node(value);
//			return this->root;
//		}
//	parent->cnt++;
//	if (parent->cnt == 1)
//	{
//		parent->root = new Node*;
//		parent->root[0] = new Node(value);
//		parent->order = 0;
//		return parent->root[0];
//	}
//	if (parent->cnt > (1 << parent->order))
//	{
//		parent->order++;
//		Node<T>** aux = new Node<T>*[(1 << parent->order)];
//		int i;
//		for (i = 0; i < parent->cnt; i++)
//			aux[i] = parent->children[i];
//		aux[i] = new Node(value);
//		delete[] parent->children;
//		parent->children = aux;
//		parent->cnt++;
//		return parent->children[parent->cnt - 1];
//	}
//	parent->children[parent->cnt] = new Node(value);
//	parent->cnt++;
//	return parent->children[parent->cnt - 1];
//}
////Node<T>* GetNode(Node<T>* parent, int index);
////void DeleteNode(Node<T>* node);
////Node<T>* Find(funcPointer Equals, T value);
////Node<T>* Insert(Node<T>* parent, int index, T value);
////Node<T>* Sort(Node<T>* node);
////int Count(Node<T>* node);