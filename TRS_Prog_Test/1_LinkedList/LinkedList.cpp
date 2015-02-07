#include "LinkedList.h"
#include <stdio.h>
template <class T>
LinkedList<T>::LinkedList()
	: m_Size(0)
	, m_Head(nullptr) 
	, m_Tail(nullptr)
{}

template <class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* cur = m_Head;
	while (cur != nullptr)
	{
		m_Head = cur->m_Link;
		delete cur;
		cur = m_Head;
		--m_Size;
	}
}

template <class T>
void LinkedList<T>::PushBack(T data)
{
	Node<T>* newTail = new Node<T>(data);

	if (m_Size == 0)
	{
		m_Head = newTail;
		m_Tail = newTail;
	}
	else
	{
		m_Tail->m_Link = newTail;
		m_Tail = newTail;
	}
	++m_Size;
}

template <class T>
void LinkedList<T>::PushFront(T data)
{
	Node<T>* newHead = new Node<T>(data);
	if (m_Size == 0)
	{
		m_Head = newHead;
		m_Tail = newHead;
	}
	else
	{
		m_Head->m_Link = newHead;
		m_Head = newHead;
	}
	++m_Size;
}

template <class T>
T LinkedList<T>::GetHead() const
{
	return m_Head->m_Data;
}

template <class T>
T LinkedList<T>::GetTail() const
{
	return m_Tail->m_Data;
}

template <class T>
unsigned int LinkedList<T>::GetSize() const
{
	return m_Size;
}

template <class T>
void LinkedList<T>::Print() const
{
	Node<T>* cur = m_Head;
	while (cur != nullptr)
	{
		printf("%f\n", cur->m_Data);
		cur = cur->m_Link;
	}
}

template <class T>
void LinkedList<T>::Sort()
{
	MergeSort(&m_Head);
	Node<T>* cur = m_Head;
	while (cur->m_Link != nullptr)
	{
		cur = cur->m_Link;
	}
	m_Tail = cur;
}

template <class T>
void LinkedList<T>::MergeSort(Node<T>** head)
{
	if (*head == nullptr || (*head)->m_Link == nullptr)
	{
		return;
	}

	Node<T>* beginning = *head;
	Node<T>* left = nullptr;
	Node<T>* right = nullptr;
	Split(beginning, &left, &right);
	MergeSort(&left); 
	MergeSort(&right);
	*(head) = Merge(left, right); // Too many elements can cause stack overflow b/c of recursion
}

template <class T>
void LinkedList<T>::Split(Node<T>* beginning, Node<T>** left, Node<T>**  right)
{
	if (beginning == nullptr || beginning->m_Link == nullptr)
	{
		*left = beginning;
		right = nullptr;
		return;
	}

	Node<T>* cur = beginning;
	Node<T>* runner = beginning->m_Link;
	while (runner != nullptr)
	{
		runner = runner->m_Link;
		if (runner != nullptr)
		{
			cur = cur->m_Link;
			runner = runner->m_Link;
		}
	}

	*left = beginning;
	*right = cur->m_Link;
	cur->m_Link = nullptr;
}

template <class T>
Node<T>* LinkedList<T>::Merge(Node<T>* left, Node<T>*  right)
{
	Node<T>* head;
	if (left == nullptr)
	{
		head = right;
	}
	else if (right == nullptr)
	{
		head = left;
	}
	else
	{
		if (left->m_Data <= right->m_Data)
		{
			head = left;
			head->m_Link = Merge(left->m_Link, right);
		}
		else
		{
			head = right;
			head->m_Link = Merge(left, right->m_Link);
		}
	}

	return head;
}


// Explicit template declarations to keep cpp separate
template class LinkedList<float>;
template class LinkedList<int>;