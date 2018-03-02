#pragma once
#ifndef QUEUE_ITERATOR_HEADER
#define QUEUE_ITERATOR_HEADER

#include "queue.h"

template<typename T>
struct LinkedListNode;

template<typename T>
class QueueIterator
{
private:
	ListIterator<T> iter;
public:
	QueueIterator                  (ListIterator<T> _iter)            : iter(_iter)                                    {}
	QueueIterator                  (const QueueIterator& other)       : iter(other.iter)                               {}
	QueueIterator&     operator ++ ()                                 { ++iter; return *this;                           }
	QueueIterator      operator ++ (int)                              { QueueIterator tmp(*this); ++iter; return tmp;   }
	bool               operator == (const QueueIterator& other) const { return iter == other.iter;                      }
	bool               operator != (const QueueIterator& other) const { return iter != other.iter;                      }
	const T&           operator *  ()                           const { return iter.head->data;                         }
	T&                 operator *  ()                                 { return *(iter);                         }

};


#endif // !QUEUE_ITERATOR_HEADER