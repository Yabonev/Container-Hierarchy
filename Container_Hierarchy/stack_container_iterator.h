#ifndef STACK_CONTAINER_ITERATOR_HEADER
#define STACK_CONTAINER_ITERATOR_HEADER

#include "stack_container.h"
#include "container_iterator.h"

template<typename T>
class StackConIterator : private StackIterator<T>, public ContainerIterator<T>
{
public:
	StackConIterator&      operator ++  ()                                   { StackIterator<T>::operator++();           }
	StackConIterator       operator ++  (int)                                { StackIterator<T>::operator++(int);        }
	bool                   operator == (const StackConIterator& other) const { StackIterator<T>::operator==(other.head); }
	bool                   operator != (const StackConIterator& other) const { StackIterator<T>::operator!=(other.head); }
	const T&               operator *  ()                              const { StackIterator<T>::operator*();            }
	T&                     operator *  ()                                    { StackIterator<T>::operator*();            }
};

#endif // !LIST_CONTAINER_ITERATOR_HEADER
