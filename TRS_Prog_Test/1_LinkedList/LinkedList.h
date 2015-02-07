#include "Node.h"

#pragma once

template <class T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void PushBack(T data);
	void PushFront(T data);
	void Sort();
	void Print() const;
	T GetHead() const;
	T GetTail() const;
	unsigned int GetSize() const;

private:
	void MergeSort(Node<T>** head); // O(nlogn)
	void Split(Node<T>* beginning, Node<T>** left, Node<T>**  right);
	Node<T>* Merge(Node<T>* left, Node<T>* right);

	unsigned int m_Size;
	Node<T>* m_Head;
	Node<T>* m_Tail;
};