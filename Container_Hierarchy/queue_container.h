#ifndef QUEUE_CONTAINER_HEADER
#define QUEUE_CONTAINER_HEADER


#include "queue.h"
#include "container.h"

template<typename T>
class QueueContainer : public Queue<T>, public Container<T>
{
private:
	void format(std::ostream&)const;
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
inline void QueueContainer<T>::format(std::ostream &out) const
{
	out << "Q ";
	Queue::format(out);
}

template<typename T>
inline void QueueContainer<T>::add_element(const T & newData)
{
	Queue::enqueue(newData);
}

template<typename T>
inline bool QueueContainer<T>::remove_element()
{
	return Queue::dequeue();
}

template<typename T>
inline bool QueueContainer<T>::member(const T & x)const
{
	return Queue::member(x);
}

template<typename T>
inline size_t QueueContainer<T>::length()const
{
	return Queue::length();
}

template<typename T>
inline bool QueueContainer<T>::contains(Condition condition)const
{
	return Queue::contains(condition);
}

template<typename T>
inline void QueueContainer<T>::filter(Condition condition)
{
	Queue::filter(condition);
}

template<typename T>
inline void QueueContainer<T>::sort()
{
	Queue::sort();
}

template<typename T>
inline void QueueContainer<T>::print()
{
	Queue::print();
}

#endif // !QUEUE_CONTAINER_HEADER
