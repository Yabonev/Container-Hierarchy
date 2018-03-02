#ifndef QUEUE_HEADER
#define QUEUE_HEADER

#include <iostream>
#include "container.h"
#include "dl_list.h"
#include <cassert>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "list_iterator.h"

template<typename T>
class QueueIterator;

template<typename T>
class Queue
{
private:
	DoublyLinkedList<T> listQ;


    bool remove(const T& data); // what is this?
public:
	Queue();
	void enqueue(const T&  newData);
	bool dequeue();
	T front();
	bool empty()const;
	void print();
	QueueIterator<T> begin();
	QueueIterator<T> end();
protected:
	using  Condition = bool(*)(const T&);

	bool   member(const T& x)const;
	size_t length()const;
	void   sort();
	void   filter(Condition condition);
	bool contains(Condition condition)const;
	void format(std::ostream& out)const
	{
		listQ.format(out);

	}
	friend class QueueIterator<T>;
	/*QueueIterator<T> begin();
	QueueIterator<T> end();*/
};


template<typename T>
inline bool Queue<T>::remove(const T & data)
{
	return listQ.remove(data);
}

template<typename T>
inline Queue<T>::Queue() : listQ() {}

template<typename T>
inline void Queue<T>::enqueue(const T&  newData)
{
	listQ.push_back(newData);
}

template<typename T>
inline bool Queue<T>::dequeue()
{	
	return listQ.pop_front();
}

template<typename T>
inline T Queue<T>::front()
{	
	assert(!listQ.empty());
	return listQ.front();
}

template<typename T>
inline bool Queue<T>::empty()const
{
	return listQ.empty();
}

template<typename T>
inline void Queue<T>::print() // use iterator
{
	ListIterator<T> it = listQ.begin();
	std::cout << "<-- front " << std::endl;
	int indent = 1;
	while (it != listQ.end())
	{
		std::cout << *(it) << " ";
		++it; ++indent;
	}
	std::cout << std::endl;
	std::cout << std::setw(indent) << " " << "rear --> " << std::endl;
	std::cout << "------------------------------------------------------------------------------------------------------" << std::endl;

}

template<typename T>
inline size_t Queue<T>::length()const
{
	return listQ.length();
}

template<typename T>
inline void Queue<T>::sort()
{
	listQ.sort();
}
template<typename T>
inline void Queue<T>::filter(Condition condition)
{
	listQ.filter(condition);
}

template<typename T>
inline bool Queue<T>::contains(Condition condition)const
{
	return listQ.contains(condition);
}

template<typename T>
inline QueueIterator<T> Queue<T>::begin()
{
	return QueueIterator<T>(listQ.begin());
}

template<typename T>
inline QueueIterator<T> Queue<T>::end()
{
	return QueueIterator<T>(listQ.end());
}

template<typename T>
inline bool Queue<T>::member(const T & x)const
{
	return listQ.member(x);
}

#endif // !QUEUE_HEADER
