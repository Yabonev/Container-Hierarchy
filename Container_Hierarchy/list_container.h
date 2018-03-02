#ifndef LIST_CONTAINER_HEADER
#define LIST_CONTAINER_HEADER

#include "dl_list.h"
#include "container.h"

template<typename T>
class ListConIterator;

template<typename T>
class ListContainer : public DoublyLinkedList<T>, public Container<T>
{
    void format(std::ostream&) const;
public:
	using Condition = bool(*)(const T&);

	void add_element(const T& newData);
	bool remove_element();
	bool member(const T& x)const;
	size_t length()const;
	bool contains(Condition condition)const;
	void filter(Condition condition);
	void sort();
	void print();


};

template<typename T>
inline void ListContainer<T>::format(std::ostream &out) const
{
	out << "L ";
	DoublyLinkedList::format(out);
}

template<typename T>
inline void ListContainer<T>::add_element(const T & newData)
{
	DoublyLinkedList::push_front(newData);

}

template<typename T>
inline bool ListContainer<T>::remove_element()
{
	return pop_front();
}

template<typename T>
inline bool ListContainer<T>::member(const T & x)const
{
	return DoublyLinkedList::member(x);
}

template<typename T>
inline size_t ListContainer<T>::length()const
{
	return DoublyLinkedList::length();
}

template<typename T>
inline bool ListContainer<T>::contains(Condition condition)const
{
	return DoublyLinkedList::contains(condition);
}

template<typename T>
inline void ListContainer<T>::filter(Condition condition)
{
	DoublyLinkedList::filter(condition);
}

template<typename T>
inline void ListContainer<T>::sort()
{
	DoublyLinkedList::sort();
}

template<typename T>
inline void ListContainer<T>::print()
{
	DoublyLinkedList::print();
}

#endif // !LIST_CONTAINER_HEADER
