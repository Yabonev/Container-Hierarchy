#pragma once
#ifndef LIST_CONTAINER_ITERATOR_HEADER
#define LIST_CONTAINER_ITERATOR_HEADER

#include "list_iterator.h"
#include "container_iterator.h"

template<typename T>
class ListConIterator : private ListIterator<T>, public ContainerIterator<T>
{
public:
	ListConIterator&       operator ++ ()                                   { ListIterator<T>::operator++();           }
	ListConIterator        operator ++ (int)                                { ListIterator<T>::operator++(int);        }
	bool                   operator == (const ListConIterator& other) const { ListIterator<T>::operator==(other.head); }
	bool                   operator != (const ListConIterator& other) const { ListIterator<T>::operator!=(other.head); }
	const T&               operator *  ()                             const { ListIterator<T>::operator*();            }
	T&                     operator *  ()                                   { ListIterator<T>::operator*();            }
};

#endif // !LIST_CONTAINER_ITERATOR_HEADER
