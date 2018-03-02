#ifndef STACK_CONTAINER_HEADER
#define STACK_CONTAINER_HEADER

#include "stack.h"

template<typename T>
class StackContainer : public Stack<T>, public Container<T>
{
private:
    void format(std::ostream&) const;
public:
	using Condition = bool(*)(const T&);

	void add_element(const T& newData);
	bool remove_element();
	bool member(const T& x)const;
	size_t length()const;
	bool contains(Condition condtion)const;
	void filter(Condition condition);
	void sort();
	void print();
	


};

template<typename T>
inline void StackContainer<T>::format(std::ostream &out) const
{
	out << "S ";
	Stack::format(out);
}

template<typename T>
inline void StackContainer<T>::add_element(const T & newData)
{
	Stack::push(newData);
}

template<typename T>
inline bool StackContainer<T>::remove_element()
{
	return Stack::pop();
}

template<typename T>
inline bool StackContainer<T>::member(const T & x)const
{
	return Stack::member(x);
}

template<typename T>
inline size_t StackContainer<T>::length()const
{
	return Stack::length();
}

template<typename T>
inline bool StackContainer<T>::contains(Condition condition)const 
{
	return Stack::contains(condition);
}

template<typename T>
inline void StackContainer<T>::filter(Condition condition)
{
	Stack::filter(condition);
}

template<typename T>
inline void StackContainer<T>::sort()
{
	Stack::sort();
}

template<typename T>
inline void StackContainer<T>::print()
{
	Stack::print();
}

#endif // !STACK_CONTAINER_HEADER
