#ifndef CONTAINER_HEADER
#define CONTAINER_HEADER

#include <fstream>

template<typename T>
class ContainerIterator;

template<typename T>
class Container
{	
public:
	//virtual ~Container();
	virtual void add_element(const T& newData) = 0;
	virtual bool remove_element() = 0;
	virtual bool member(const T& x)const = 0;
	virtual void print() = 0;
	virtual size_t length() const= 0;
	virtual void sort() = 0;
	using Condition = bool(*)(const T&);
	virtual bool contains(Condition) const= 0;
	virtual void filter(Condition) = 0;
	virtual void format(std::ostream&) const = 0; // interface class implements iterator, deriving classes implement format function
	friend std::ostream& operator<<(std::ostream& out, const Container<T>& container)
	{
		container->format();
		return out;
	}
};
#endif // !CONTAINER_HEADER
