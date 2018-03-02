#ifndef QUEUE_CONTAINER_ITERATOR_HEADER
#define QUEUE_CONTAINER_ITERATOR_HEADER

#include "queue_container.h"
#include "container_iterator.h"

template<typename T>
class QueueConIterator : private QueueIterator<T>, public ContainerIterator<T>
{
public:
	QueueConIterator&     operator ++  ()                                    { QueueIterator<T>::operator++();           }
	QueueConIterator      operator ++  (int)                                 { QueueIterator<T>::operator++(int);        }
	bool                   operator == (const QueueConIterator& other) const { QueueIterator<T>::operator==(other.head); }
	bool                   operator != (const QueueConIterator& other) const { QueueIterator<T>::operator!=(other.head); }
	const T&               operator *  ()                              const { QueueIterator<T>::operator*();            }
	T&                     operator *  ()                                    { QueueIterator<T>::operator*();            }
};

#endif // !LIST_CONTAINER_ITERATOR_HEADER
