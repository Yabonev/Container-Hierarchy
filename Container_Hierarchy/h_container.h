#ifndef HETEROGENEOUS_CONTAINER
#define HETEROGENEOUS_CONTAINER

#include "dl_list.h"
#include "queue.h"
#include "stack.h"
#include <string>
#include "factory.h"
#include <fstream>
#include <sstream>



template<typename T>
struct ContainerNode
{
	Container<T> * container;
	ContainerNode * next;
	ContainerNode() : container(nullptr), next(nullptr) {}
	ContainerNode(Container<T> * _thiscontainer) : container(_thiscontainer), next(nullptr) {}
};
//
//template<typename T>
//class HeterogeneousContainer;
//
//template<typename T>
//std::istream& operator>> (std::istream& in, HeterogeneousContainer<T>& hc);

template<typename T>
class HeterogeneousContainer
{

private:
	ContainerNode<T> * head;

public:
	HeterogeneousContainer() : head(nullptr) {}
	bool add_container(std::string data);
	bool member(const T& data);																							  
	bool balanced_insert(const T& newData);
	bool removeFront();

	using Condition = bool(*)(const T& x);

	bool contains(Condition condition);
	bool filter(Condition condition);
	void sort();
	void print();
//	ContainerIterator* find(const T& data);
	friend std::ostream& operator<<(std::ostream& out, const HeterogeneousContainer& hc)
	{
		ContainerNode<T> * current = hc.head;
		while (current != nullptr)
		{
			current->container->format(out); 
			current = current->next;
		}
		return out;
	}
	friend std::istream& operator>> (std::istream& in, HeterogeneousContainer& hc) // problems with templates arise if defined elsewhere
	{
		std::string line;
		while (in)
		{
			getline(in, line);
			if(line != "")
				hc.add_container(line);
		}
		return in;
	} 
};


template<typename T>
inline bool HeterogeneousContainer<T>::add_container(std::string data)
{	

	ContainerNode<T> * newNode = new ContainerNode<T>(Factory<T>::spawn(data[0]));
	newNode->next = head;
	head = newNode;
	data.erase(0, 2);
	size_t index = 0;
	T temporary;
	std::stringstream helper;
	while (!data.empty() && index != -1)
	{
		helper << data;
		helper >> temporary;
		newNode->container->add_element(temporary);
		index = data.find_first_of(" ");
		data.erase(0, index + 1);
		helper.str("");
		helper.clear();
	}
	return true;
}

template<typename T>
inline bool HeterogeneousContainer<T>::member(const T& data)
{
	ContainerNode<T> * current = head;
	while (current != nullptr)
	{
		if (current->container->member(data))
			return true;
		current = current->next;
	}
	return false;
}

template<typename T>
inline bool HeterogeneousContainer<T>::balanced_insert(const T& newData)
{
	size_t smallestSize = head->container->length();
	ContainerNode<T> * current = head;
	while (current != nullptr)
	{
		if (smallestSize > current->container->length())
			smallestSize = current->container->length();
		current = current->next;
	}
	current = head;
	while (current->container->length() != smallestSize)
	{
		current = current->next;
	}
	current->container->add_element(newData);
	return true;
}

template<typename T>
inline bool HeterogeneousContainer<T>::removeFront()
{
	assert(head != nullptr);
	ContainerNode<T> * save = head;
	head = head->next;
	delete save;
	return true;
}

template<typename T>
inline bool HeterogeneousContainer<T>::contains(Condition condition)
{
	ContainerNode<T> * current = head;
	while (current != nullptr)
	{
		if (current->container->contains(condition))
			return true;
		current = current->next;
	}
	return false;
}

template<typename T>
inline bool HeterogeneousContainer<T>::filter(Condition condition)
{
	ContainerNode<T> * current = head;
	while (current != nullptr)
	{
		current->container->filter(condition);
		current = current->next;
	}
	return true;
}

template<typename T>
inline void HeterogeneousContainer<T>::sort()
{
	ContainerNode<T> * current = head;
	while (current != nullptr)
	{
		current->container->sort();
		current = current->next;
	}
}

template<typename T>
inline void HeterogeneousContainer<T>::print()
{
	ContainerNode<T> * current = head;
	while (current != nullptr)
	{
		current->container->print();
		current = current->next;
	}
}




#endif // !HETEROGENEOUS_CONTAINER
