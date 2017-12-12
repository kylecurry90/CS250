//@author Kyle Curry
//Project 1 - CS250
//Updated 10/1/17

#include "project1_LinkedList.hpp"

Node::Node()
{
	Node* m_ptrNext = nullptr;
	Node* m_ptrPrev = nullptr;
}

LinkedList::LinkedList()
{
	Node* m_ptrFirst = nullptr;
	Node* m_ptrLast = nullptr;
	m_itemCount = 0;
}

LinkedList::~LinkedList()
{
	Clear();
}

void LinkedList::Clear()
{
	while (m_itemCount != 0)
	{
		PopFront();
	}
}

void LinkedList::PushFront( CustomerData newData )
{
	if (m_itemCount == 0)
	{
		Node* newNode = new Node;
		newNode->m_data = newData;
		m_ptrFirst = newNode;
		m_ptrLast = newNode;
		m_itemCount++;
	}
	if (m_itemCount != 0)
	{
		Node* newNode = new Node;
		newNode->m_data = newData;
		m_ptrFirst->m_ptrPrev = newNode;
		newNode->m_ptrNext = m_ptrFirst;
		m_ptrFirst = newNode;
		m_itemCount++;
	}
}

void LinkedList::PushBack( CustomerData newData )
{
	if (m_itemCount == 0)
	{
		Node* newNode = new Node;
		newNode->m_data = newData;
		m_ptrFirst = newNode;
		m_ptrLast = newNode;
		m_itemCount++;
	}
	if (m_itemCount != 0)
	{
		Node* newNode = new Node;
		newNode->m_data = newData;
		m_ptrLast->m_ptrNext = newNode;
		newNode->m_ptrPrev = m_ptrLast;
		m_ptrLast = newNode;
		m_itemCount++;
	}
}

void LinkedList::PopFront() noexcept
{
	if (m_ptrFirst == m_ptrLast)
	{
		delete m_ptrFirst;
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
		m_itemCount--;
	}
	if (m_ptrFirst != m_ptrLast)
	{
		Node* tempNode = m_ptrFirst->m_ptrNext;
		tempNode->m_ptrPrev = nullptr;
		delete m_ptrFirst;
		m_ptrFirst = tempNode;
		m_itemCount--;
	}
}

void LinkedList::PopBack() noexcept
{
	if (m_ptrFirst == m_ptrLast)
	{
		delete m_ptrLast;
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
		m_itemCount--;
	}
	if (m_ptrFirst != m_ptrLast)
	{
		Node* tempNode = m_ptrLast->m_ptrPrev;
		tempNode->m_ptrNext = nullptr;
		delete m_ptrLast;
		m_ptrLast = tempNode;
		m_itemCount--;
	}
}

CustomerData LinkedList::GetFront()
{
	if (Size() == 0)
	{
		throw runtime_error("Invalid Index");
	}
	else
	{
		return m_ptrFirst->m_data;
	}
}

CustomerData LinkedList::GetBack()
{
	if (Size() == 0)
	{
		throw runtime_error("Invalid Index");
	}
	else
	{
		return m_ptrLast->m_data;
	}
}

CustomerData& LinkedList::operator[](const int index)
{
	int counter = 0;
	Node* ptrCurrent = m_ptrFirst;
	if (m_ptrFirst == nullptr)
	{
		throw out_of_range("Out of Range");
	}
	else if (index < 0 || index >= m_itemCount)
	{
		throw out_of_range("Invalid Index");
	}
	while (ptrCurrent != nullptr && counter < index)
	{
		ptrCurrent = ptrCurrent->m_ptrNext;
		counter++;
	}
	return ptrCurrent->m_data;
}

bool LinkedList::IsEmpty()
{
	if (m_itemCount == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int LinkedList::Size()
{
	return m_itemCount;
}

