//#pragma once
#ifndef STACK_ITERATOR_HEADER
#define STACK_ITERATOR_HEADER

#include "stack.h"

template<typename T>
struct LinkedListNode;

template<typename T>
class StackIterator
{
private:
	ListIterator<T> iter;
public:
	StackIterator                  (ListIterator<T> _iter)            : iter(_iter)                                  {}
	StackIterator                  (const StackIterator& other)       : iter(other.iter)                             {}
	StackIterator&     operator ++ ()                                 { ++iter; return *this;                         }
	StackIterator      operator ++ (int)                              { StackIterator tmp(*this); ++iter; return tmp; }
	bool               operator == (const StackIterator& other) const { return iter == other.iter;                    }
	bool               operator != (const StackIterator& other) const { return iter != other.iter;                    }
	const T&           operator *  ()                           const { return *(iter);                               }
	T&                 operator *  ()                                 { return *(iter);                               }

};






#endif // !STACK_ITERATOR_HEADER
