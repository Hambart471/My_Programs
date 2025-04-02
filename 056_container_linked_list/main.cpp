// Linked List

#include <iostream>

template<typename T>
class List
{
public:
	List();
	void pushFront(T data);
	void popFront();
	void clear();
	~List();
	void insert(int index, T data);
	void pushBack(T data);
	void removeAt(int index);
	void popBack();
	T& operator[](const int index);
	int getSize() const;
	void print() const;
private:
	class Node
	{
	public:
		Node(T data = 0, Node* pNext = nullptr)
			:data(data), pNext(pNext) {}
		T data;
		Node* pNext;
	};
	Node* pHead;
	int size;
};

// Constructor: Initialize empty list
template<typename T>
List<T>::List() :pHead(nullptr), size(0) {}

// Insert element at the beginning
template<typename T>
void List<T>::pushFront(T data)
{
	pHead = new Node(data, pHead);
	++size;
}

// Remove first element
template<typename T>
void List<T>::popFront()
{
	if (!pHead)
		return;
	Node* pDelete = pHead;
	pHead = pHead->pNext;
	delete pDelete;
	--size;
}

// Remove all elements
template<typename T>
void List<T>::clear()
{
	while (size)
	{
		popFront();
	}
}

// Destructor: Free memory
template<typename T>
List<T>::~List()
{
	clear();
}

// Insert element at a specific index
template<typename T>
void List<T>::insert(int index, T data)
{
	if (index == 0)
	{
		pushFront(data);
	}
	else if (index > size)
	{
		return;
	}
	else
	{
		Node* pCurrent = pHead;
		for (int i = 0; i < index - 1; ++i)
		{
			pCurrent = pCurrent->pNext;
		}
		pCurrent->pNext = new Node(data, pCurrent->pNext);
		++size;
	}
}

// Insert element at the end
template<typename T>
void List<T>::pushBack(T data)
{
	insert(size, data);
}

// Remove element at a specific index
template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		popFront();
	}
	else if (index > size - 1)
	{
		return;
	}
	else
	{
		Node* pCurrent = pHead;
		for (int i = 0; i < index - 1; ++i)
		{
			pCurrent = pCurrent->pNext;
		}
		Node* pDelete = pCurrent->pNext;
		pCurrent->pNext = pDelete->pNext;
		delete pDelete;
		--size;
	}
}

// Remove last element
template<typename T>
void List<T>::popBack()
{
	removeAt(size - 1);
}

// Access element by index
template<typename T>
T& List<T>::operator[](const int index)
{
	Node* pCurrent = pHead;
	for (int i = 0; i < index; ++i)
	{
		pCurrent = pCurrent->pNext;
	}
	return pCurrent->data;
}

// Get list size
template<typename T>
int List<T>::getSize() const
{
	return size;
}

// Print list details
template<typename T>
void List<T>::print() const
{
	if (!pHead)
	{
		std::cout << "List is empty\n";
		return;
	}
	Node* pCurrent = pHead;
	int i = 1;

	while (pCurrent)
	{
		std::cout << i++ << "/" << size << '\n';
		std::cout << "pHead = \t" << pHead << '\n';
		std::cout << "pCurrent = \t" << pCurrent << '\n';
		std::cout << "pNext = \t" << pCurrent->pNext << '\n';
		std::cout << "data = \t" << pCurrent->data << '\n' << '\n';
		pCurrent = pCurrent->pNext;
	}
}

int main()
{
	List<int> list;
	list.pushBack(rand());
	list.pushBack(rand());
	list.pushBack(rand());
	//list[1] = 10;
	for (int i = 0; i < list.getSize(); ++i)
	{
		std::cout << list[i] << '\n';
	}
	std::cout << '\n';
	list.print();
}