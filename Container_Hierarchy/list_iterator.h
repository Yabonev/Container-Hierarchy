#ifndef LIST_ITERATOR_HEADER
#define LIST_ITERATOR_HEADER

#include "dl_list.h"

template<typename T>
class ListIterator //: public std::iterator<std::forward_iterator_tag, LinkedListNode<T>>
{
private:
	LinkedListNode<T> * head;
public:
	ListIterator                   (LinkedListNode<T> * _head)       : head(_head)                                    {}
	ListIterator                   (const ListIterator& other)       : head(other.head)                               {}
	ListIterator&      operator ++ ()                                { head = head->next; return *this;                }
	ListIterator       operator ++ (int)                             { ListIterator tmp(*this); ++(*this); return tmp; }
	bool               operator == (const ListIterator& other) const { return head == other.head;                      }
	bool               operator != (const ListIterator& other) const { return head != other.head;                      }
	const T&           operator *  ()                          const { return head->data;                              }
	T&                 operator *  ()                                { return head->data;                              }

	
};



#endif // !LIST_FORWARD_ITERATOR_HEADER