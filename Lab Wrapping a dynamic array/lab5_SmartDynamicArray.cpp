#include "lab5_SmartDynamicArray.hpp"

#include "cuTEST/Menu.hpp"

SmartDynamicArray::SmartDynamicArray()
{
	m_itemCount = 0;
	m_data = nullptr;
}

SmartDynamicArray::~SmartDynamicArray()
{
	DeallocateMemory();
}

void SmartDynamicArray::AllocateMemory()
{
	AllocateMemory(10);
}

void SmartDynamicArray::AllocateMemory(int newSize)
{
	if (m_data == nullptr)
	{
		m_arraySize = newSize;
		m_itemCount = 0;

		m_data = new string[m_arraySize];

	}
	else
	{
		throw logic_error("Memory cannot be allocated because m_data is already pointing somewhere.");
	}
}

void SmartDynamicArray::DeallocateMemory()
{
	if (m_data != nullptr)
	{
		delete[] m_data;
		m_data = nullptr;
	}
}


bool SmartDynamicArray::IsInvalidIndex(int index) const
{
	if (index < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool SmartDynamicArray::IsNonContiguousIndex(int index) const
{
	if (index > m_itemCount)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void SmartDynamicArray::Push(const string& newItem)
{

	if (m_data == nullptr)
	{
		AllocateMemory();
	}
	if (IsFull())
	{
		Resize();
	}

	m_data[m_itemCount] = newItem;
	m_itemCount = m_itemCount + 1;



}


void SmartDynamicArray::Pop()
{
	if (m_itemCount > 0)
	{
		m_itemCount = m_itemCount - 1;
	}
}


bool SmartDynamicArray::IsEmpty() const
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


void SmartDynamicArray::ShiftRight(int index)
{
	for (int i = m_itemCount; i > index; i--)
	{
		m_data[i] = m_data[i - 1];
	}
}


void SmartDynamicArray::ShiftLeft(int index)
{
	for (int i = index; i < m_itemCount - 1; i++)
	{
		m_data[i] = m_data[i + 1];
	}
}


void SmartDynamicArray::Resize()
{
	Resize(m_arraySize + 10);
}


void SmartDynamicArray::Resize(int newSize)
{
	if (m_data == nullptr)
	{
		AllocateMemory(newSize);
		return;
	}
	string * newArray = new string[newSize];

	for (int i = 0; i < m_arraySize; i++)
	{
		newArray[i] = m_data[i];
	}

	delete[] m_data;
	m_data = newArray; // ?
	m_arraySize = newSize;
}


bool SmartDynamicArray::IsFull() const noexcept
{
	if (m_itemCount == m_arraySize)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int SmartDynamicArray::Size() const
{
	return m_itemCount;
}


void SmartDynamicArray::Remove(int index)
{
	if (index < 0 || index >= m_itemCount)
	{
		throw out_of_range("Cannot insert at index - out of range");

	}
	else
	{
		ShiftLeft(index);
		m_itemCount = m_itemCount - 1;
	}
}


string SmartDynamicArray::Get(int index) const
{
	if (index < 0 || index >= m_itemCount)
	{
		throw out_of_range("Out of range of array");
	}
	else
	{
		return m_data[index];
	}
}


void SmartDynamicArray::Insert(int index, const string& newItem)
{
	/*
	if (IsFull())
	{
		Resize();
	}
	else if (index > m_itemCount || index < 0)
	{
		throw std::out_of_range("Cannot insert at index - must be contiguous!");
	}
	else
	{
		ShiftRight(index);
		m_data[index] = newItem;
		m_itemCount++;
	}
	*/

	if (IsFull())
	{
		Resize();
	}

	if (index > m_itemCount || index < 0)
	{
		throw std::out_of_range("Cannot insert at index - must be contiguous!");
	}
	else
	{
		ShiftRight(index);
		m_data[index] = newItem;
		m_itemCount++;
	}

 

}


void SmartDynamicArray::Extend(const SmartDynamicArray& other)
{
	if (m_itemCount + other.m_itemCount >= m_arraySize)
	{
		Resize(m_itemCount + other.m_itemCount);

	}
	for (int i = 0; i < other.m_itemCount; i++)
	{
		Push(other.Get(i));
	}




}


string SmartDynamicArray::operator[](int index)
{
	return Get(index);
}


SmartDynamicArray& SmartDynamicArray::operator=(const SmartDynamicArray& other)
{
	for (int i = 0; i < other.m_itemCount; i++)
	{
		m_data[i] = other.m_data[i];
		m_itemCount++;
	}

	return *this;
}

bool SmartDynamicArray::operator==(const SmartDynamicArray& other)
{
	if (m_itemCount != other.m_itemCount)
	{
		return false;
	}

	for (int i = 0; i < m_itemCount; i++)
	{
		if (m_data[i] != other.m_data[i])
		{
			return false;
		}
	}

	return true;
}


bool SmartDynamicArray::operator!=(const SmartDynamicArray& other)
{
	return !(*this == other);
}
