#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>


template<typename T>
struct LinkedListNode
{
	T				 data;
	LinkedListNode * next;
	LinkedListNode * previous;

	LinkedListNode(T _data, LinkedListNode * _next, LinkedListNode * _previous);
};
template<typename T>
class ListIterator;

template<typename T>
class DoublyLinkedList
{
private:

	LinkedListNode<T> * head;
	LinkedListNode<T> * tail;

	void Delete(LinkedListNode<T> * crr);
public:
	using Condition = bool(*)(const T&);

	DoublyLinkedList();
	~DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList & other);
	DoublyLinkedList& operator =(DoublyLinkedList other);
	void   push_front(const T&  newData);
	void   push_back(const T&  newData);
	bool   pop_front();
	bool   pop_back();
	bool   remove(const T& data);
	bool   empty() const;
	T      front()const;
	T      back()const;
	void   print();
	size_t length()const;
	bool   contains(Condition condition)const;
	bool member(const T& x)const; // should in Object type class and in this class
	void sort(); // should in Object type class and in this
	void filter(Condition condition); // both Obj and here
	void format(std::ostream& out)const
	{
		LinkedListNode<T> * current = head;
		while (current != nullptr)
		{
			out << current->data << " ";
			current = current->next;
		}
		out << "\n";
	}

	void swap(DoublyLinkedList<T> & other);
	friend class ListIterator<T>;
	typedef ListIterator<T> iterator;
	typedef ListIterator<const T> const_iterator;

	ListIterator<T>        begin() { return iterator(head); }
	ListIterator<T>        end() { return iterator(nullptr); }
//	ListIterator<const T>  c_begin() { return const_iterator(head); }
	//ListIterator<const T>  c_end() { return const_iterator(nullptr); }



};

template<typename T>
inline LinkedListNode<T>::LinkedListNode(T _data, LinkedListNode * _next, LinkedListNode * _previous) :
														data(_data), next(_next), previous(_previous) {}


template<typename T>
inline void DoublyLinkedList<T>::Delete(LinkedListNode<T> * crr)
{	
	if (crr == nullptr)
		return;
	Delete(crr->next);
	delete crr;
}

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template<typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList()
{
	Delete(head);
}

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList & other)
{	
	
	if (other.length() == 0)
		head = tail = nullptr;
	else
	{
		head = new LinkedListNode<T>(other.head->data, tail, nullptr);


		LinkedListNode<T> * tailPrev = head;
		if (other.length() == 1) tail = head;

		LinkedListNode<T> * otherCurrent = other.head->next; // if length is 1 while cycle wont activate
		while (otherCurrent->next != nullptr)
		{
			tail = new LinkedListNode<T>(otherCurrent->data, nullptr,tailPrev);
			tailPrev = tail;
			tail = tail->next;
			otherCurrent = otherCurrent->next;	
		}
		tail = new LinkedListNode<T>(otherCurrent->data, nullptr, tailPrev);
		LinkedListNode<T> * current = tail; 
		while (current->previous != nullptr)
		{
			current->previous->next = current;
			current = current->previous;
		}
	}
}

template<typename T>
inline DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList other) // copy constructor during function call
{																				   // if it fails it will be before function body
	swap(other);

	return *this;
}

template<typename T>
inline void DoublyLinkedList<T>::push_front(const T&  newData)
{
	LinkedListNode<T> * newNode = new LinkedListNode<T>(newData, head, nullptr);

	if (empty())
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		head->previous = newNode;
		head = head->previous;
	}
	//++size;
}

template<typename T>
inline void DoublyLinkedList<T>::push_back(const T&  newData)
{
	LinkedListNode<T> * newNode = new LinkedListNode<T>(newData, nullptr, tail);

	if (empty())
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = tail->next;
	}
}

template<typename T>
inline bool DoublyLinkedList<T>::pop_front()
{
	assert(!empty()); // 0 elements
	if (head == tail) // 1 element
	{	
		delete head;
		head = nullptr;
		tail = nullptr;
		
	}
	else              // >= 2 elements
	{	
		LinkedListNode<T> * save = head;
		head = head->next;
		head->previous = nullptr;
		delete save;
	}
	return true;
	
}

template<typename T>
inline bool DoublyLinkedList<T>::pop_back()
{
	assert(!empty()); // 0 elements
	if (head == tail) // 1 element
	{
		delete head;
		head = tail = nullptr;
	}
	else
	{
		LinkedListNode<T> * save = tail;
		tail = tail->previous;
		tail->next = nullptr;
		delete save;
	}
	return true;
}


template<typename T>
inline bool DoublyLinkedList<T>::remove(const T& data)
{
	if (member(data))
	{
		if (head->data == data) // element is in the beginning of list
		{	
			pop_front();
			return true;
		}
		if (tail->data == data) // element is in the end of list
		{
			pop_back();
			return true;
		}
		LinkedListNode<T> * save = head; // element is not first nor last in the list
		while (save->data != data)
		{
			save = save->next;
		}
		save->next->previous = save->previous;
		save->previous->next = save->next;
		delete save;

		return true;

	}
	return false;
}

template<typename T>
inline bool DoublyLinkedList<T>::empty() const
{	
	return head == nullptr && tail == nullptr;
}

template<typename T>
inline void DoublyLinkedList<T>::print()
{
	LinkedListNode<T> * current = head;
	std::cout << "[NULL <-- ";
	while (current != nullptr)
	{
		std::cout << current->data;
		if(current->next != nullptr)
			std::cout << " <--> ";
		current = current->next;
	}
	std::cout << " --> NULL] " << std::endl;
	std::cout << "------------------------------------------------------------------------------------------------------" << std::endl;

}
template<typename T>
inline T DoublyLinkedList<T>::front()const
{	
	assert(!empty());
	return head->data;
}
template<typename T>
inline T DoublyLinkedList<T>::back()const
{
	assert(!empty());
	return tail->data;
}
template<typename T>
inline size_t DoublyLinkedList<T>::length()const
{
	LinkedListNode<T> * current = head;
	size_t size = 0;
	while (current != nullptr)
	{
		current = current->next;
		++size;
	}
	return size;
}



template<typename T>
inline void DoublyLinkedList<T>::sort()
{
	std::vector<T> vec;
	while (!empty())
	{
		vec.push_back(front());
		pop_front();
	} 
	std::sort(vec.begin(), vec.end());
	for (std::vector<T>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		push_back(*it);
	}
}
template<typename T>
inline bool DoublyLinkedList<T>::contains(Condition condition)const
{
	LinkedListNode<T> * current = head;
	while (current != nullptr)
	{
		if (condition(current->data))
			return true;
		current = current->next;
	}
	return false;
}
template<typename T>
inline void DoublyLinkedList<T>::swap(DoublyLinkedList<T>& other)
{
	using std::swap;

	swap(head, other.head);
	swap(tail, other.tail);
}
template<typename T>
inline void DoublyLinkedList<T>::filter(Condition condition)
{
	LinkedListNode<T> * current = head;
	T save;
	bool rmv = false;
	while (current != nullptr)
	{
		if (condition(current->data))
		{
			save = current->data;
			rmv = true;
		}
		current = current->next;
		if (rmv)
		{
			remove(save);
		}
	}


}
template<typename T>
inline bool DoublyLinkedList<T>::member(const T& x)const
{
	LinkedListNode<T> * current = head;
	while (current != nullptr)
	{
		if (current->data == x)
			return true;
		current = current->next;
	}
	return false;
}


#endif // !DOUBLY_LINKED_LIST
