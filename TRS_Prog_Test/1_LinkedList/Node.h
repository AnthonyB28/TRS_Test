#pragma once

template<class T>
struct Node
{
	Node(T data)
		: m_Data(data)
		, m_Link(nullptr)
	{}

	Node(T data, Node* next)
		: m_Data(data)
		, m_Link(next)
	{}

	~Node()
	{
		m_Link = nullptr;
	}

	T m_Data;
	Node<T>* m_Link;
};