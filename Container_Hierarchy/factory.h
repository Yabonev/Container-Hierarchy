#ifndef FACTORY_HEADER
#define FACTORY_HEADER

#include "container.h"
#include "list_container.h"
#include "queue_container.h"
#include "stack_container.h"

template<typename T>
class Factory
{
public:
	static	Container<T>* spawn(char type);
};




template<typename T>
inline Container<T> * Factory<T>::spawn(char type)
{
	//assert(type == 'S' || type == 'Q' || type == 'L');
	if (type == 'L')
		return new ListContainer<T>();
	if (type == 'S')
		return new StackContainer<T>();
	if (type == 'Q')
		return new QueueContainer<T>();

	return nullptr;
}

#endif // !FACTORY_HEADER
