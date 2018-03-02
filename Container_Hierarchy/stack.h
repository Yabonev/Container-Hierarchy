#ifndef STACK_HEADER
#define STACK_HEADER

#include "list_iterator.h"
#include <iostream>
#include "container.h"


template<typename T>
class StackIterator;

template<typename T>
class Stack
{
private:
	DoublyLinkedList<T> listS;


	bool remove(const T& data);
public:
	Stack();
	void push(const T& newData);
	bool pop();
	T    top()const;
	bool empty()const;
	void print();
	StackIterator<T> begin();
	StackIterator<T> end();

	using  Condition = bool(*)(const T&);

	bool   member(const T& x)const;
	size_t length()const;
	void   sort();
	void   filter(Condition condition);
	bool contains(Condition condition)const;
	void format(std::ostream& out)const;
};

template<typename T>
inline bool Stack<T>::remove(const T & data)
{
	listS.remove(data);
}

template<typename T>
inline Stack<T>::Stack() : listS() {}


template<typename T>
inline void Stack<T>::push(const T& newData)
{
	listS.push_front(newData);
}

template<typename T>
inline bool Stack<T>::pop()
{
	return listS.pop_front();
}

template<typename T>
inline T Stack<T>::top()const
{
	assert(!empty());
	return listS.front();
}

template<typename T>	
inline bool Stack<T>::empty()const
{
	return listS.empty();
}

template<typename T>
inline size_t Stack<T>::length()const
{
	return listS.length();
}

template<typename T>
inline void Stack<T>::sort()
{
	listS.sort();
}

template<typename T>
inline void Stack<T>::filter(Condition condition)
{

	listS.filter(condition);
}

template<typename T>
inline bool Stack<T>::contains(Condition condition)const
{
	return listS.contains(condition);
}

template<typename T>
inline void Stack<T>::format(std::ostream & out) const
{
	listS.format(out);
}

template<typename T>
inline void Stack<T>::print()
{
	ListIterator< T> it = listS.begin();
	
	while (it != listS.end())
	{
		std::cout << "| " << std::setw(10) << *(it) << " |" << std::endl;
		++it;
	}
	std::cout << "------------------------------------------------------------------------------------------------------" << std::endl;
}

template<typename T>
inline StackIterator<T> Stack<T>::begin()
{
	return StackIterator<T>(listS.begin());
}

template<typename T>
inline StackIterator<T> Stack<T>::end()
{
	return StackIterator<T>(listS.end());
}

template<typename T>
inline bool Stack<T>::member(const T & x)const
{
	return listS.member(x);
}



#endif // !STACK_HEADER
