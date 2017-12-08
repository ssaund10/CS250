#include "project1_LinkedList.hpp"

Node::Node()
{
    //throw runtime_error( "Node() not yet implemented" );
	
	m_ptrNext = nullptr;
	m_ptrPrev = nullptr;


}

LinkedList::LinkedList()
{
    //throw runtime_error( "LinkedList() not yet implemented" );
	m_ptrFirst = nullptr;
	m_ptrLast = nullptr;

	int m_itemCount = 0;
}

LinkedList::~LinkedList()
{
    //throw runtime_error( "~LinkedList() not yet implemented" );
	Clear();
}

void LinkedList::Clear()
{
   // throw runtime_error( "Clear() not yet implemented" );
	while (!IsEmpty())
	{
		PopFront();
	}
}

void LinkedList::PushFront(CustomerData newData)
{
	//throw runtime_error( "PushFront() not yet implemented" );
	Node* newNode = new Node;
	newNode->m_data = newData;


	if (IsEmpty())
	{
		m_ptrFirst = newNode;
		m_ptrLast = newNode;
	}
	else
	{
		m_ptrFirst->m_ptrPrev = newNode;
		newNode->m_ptrNext = m_ptrFirst;
		m_ptrFirst = newNode;
	}
	m_itemCount++;
}

void LinkedList::PushBack(CustomerData newData)
{
	//throw runtime_error( "PusBack() not yet implemented" );
	Node* newNode = new Node;
	newNode->m_data = newData;


	if (IsEmpty())
	{
		m_ptrFirst = newNode;
		m_ptrLast = newNode;
	}
	else
	{
		m_ptrLast->m_ptrNext = newNode;
		newNode->m_ptrPrev = m_ptrLast;
		m_ptrLast = newNode;
	}

	m_itemCount++;
}

void LinkedList::PopFront() noexcept //////////////////////// MAYBE
{
    //throw runtime_error( "PopFront() not yet implemented" );
	if (!IsEmpty())
	{

		if (m_ptrFirst == m_ptrLast)
		{
			delete m_ptrFirst;
			m_ptrFirst = nullptr;
			m_ptrLast = nullptr;
			m_itemCount--;

		}
		else
		{
			Node* ptrSecond = m_ptrFirst->m_ptrNext;
			ptrSecond->m_ptrPrev = nullptr;
			delete m_ptrFirst;
			m_ptrFirst = ptrSecond;
			m_itemCount--;
		}
	}


}

void LinkedList::PopBack() noexcept
{
    //throw runtime_error( "PopBack() not yet implemented" );
	if (!IsEmpty())
	{

		if (m_ptrFirst == m_ptrLast)
		{
			delete m_ptrFirst;
			m_ptrFirst = nullptr;
			m_ptrLast = nullptr;
			m_itemCount--;

		}
		else
		{
			Node* ptrSecondToLast = m_ptrLast->m_ptrPrev;
			ptrSecondToLast->m_ptrNext = nullptr;
			delete m_ptrLast;
			m_ptrLast = ptrSecondToLast;
			m_itemCount--;
		}
	}

}

CustomerData LinkedList::GetFront()
{
    //throw runtime_error( "GetFront() not yet implemented" );

	if (IsEmpty())
	{
		throw out_of_range("Linked List empty");
	}
	else
	{
		return m_ptrFirst->m_data;
	}
}

CustomerData LinkedList::GetBack()
{
    //throw runtime_error( "GetBack() not yet implemented" );
	if (IsEmpty())
	{
		throw out_of_range("Linked List empty");
	}
	else
	{
		return m_ptrLast->m_data;
	}



}

CustomerData& LinkedList::operator[]( const int index )
{
    //throw runtime_error( "operator[]() not yet implemented" );
	int counter = 0;
	Node* ptrCurrent = m_ptrFirst;


	if (index < 0 || index >= m_itemCount)
	{
		throw out_of_range("Index invalid");
	}
	else
	{
		while (counter != index)
		{
			ptrCurrent = ptrCurrent->m_ptrNext;
			counter++;


		}
		if (counter == index)
		{
			return ptrCurrent->m_data;
		}
	}

}

bool LinkedList::IsEmpty()
{
    //throw runtime_error( "IsEmpty() not yet implemented" );
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
    //throw runtime_error( "Size() not yet implemented" );
	return m_itemCount;
}

void LinkedList::Insert(CustomerData newData, int index)
{
	throw runtime_error("Insert() not yet implemented");/*
	Node* newNode = new Node;
	newNode->m_data = newData;
	m_itemCount++;

	if (IsEmpty())
	{
		m_ptrFirst = newNode;
		m_ptrLast = newNode;
	}

	int counter = 0;
	Node* ptrCurrent = m_ptrFirst;

	if (index < 0 || index >= m_itemCount)
	{
		while (counter != index)
		{
			ptrCurrent = ptrCurrent->m_ptrNext;
			counter++;
		}
	}

	/*
	m_ptrLast->m_ptrNext = newNode;
	newNode->m_ptrPrev = m_ptrLast;
	m_ptrLast = newNode;
	*/
	


}

