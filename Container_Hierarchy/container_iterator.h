#ifndef CONTAINER_ITERATOR_HEADER
#define CONTAINER_ITERATOR_HEADER

#include "container.h"

template<typename T>
class ContainerIterator // Base Iterator
{
public:
	ContainerIterator&     operator ++ ()                                 = 0;
	ContainerIterator      operator ++ (int)                              = 0;
	bool                   operator == (const StackIterator& other) const = 0;
	bool                   operator != (const StackIterator& other) const = 0;
	const T&               operator *  ()                           const = 0;
	T&                     operator *  ()                                 = 0;
};

#endif;
