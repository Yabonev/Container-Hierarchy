// ContainerHierarchy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "h_container.h"
#include <cassert>
#include <sstream>
#include "list_iterator.h"
#include "stack_container.h"
#include "queue_iterator.h"
#include "stack_iterator.h"

void linked_list_test();
void stack_queue_container_test();
void hc_test();

bool isEven(const int & x);
int main()
{	
	//linked_list_test();
	//stack_queue_container_test();
	hc_test();
	return 0;
}
void linked_list_test()
{
	DoublyLinkedList<int> d;
	d.print();

	d.push_back(5);
	d.print();

	d.pop_back();
	d.print();

	d.push_back(5);
	d.push_front(1);
	d.print();

	d.pop_back();
	d.print();

	d.push_back(5);
	d.pop_front();
	d.pop_front();
	d.print();

	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	d.print();

	std::cout << "Front -> " << d.front() << "     ,    End -> " << d.back() << std::endl;
	d.print();

	std::cout << "remove 3 : "  << d.remove(3) << std::endl;
	d.print();
	std::cout << "remove 5 : " << d.remove(5) << std::endl;

	d.print();
	d.push_back(7);
	d.push_back(8);
	d.push_back(9);
	//d.print();
	int i = 0;
	ListIterator<int> it(d.begin());
	for (ListIterator<int> it = d.begin(); it != d.end(); ++it)
	{
		std::cout << ++i << " : " << *(it) << std::endl;
		
	}	
	DoublyLinkedList<int> d2;
	d2.push_back(10);
	d2.push_back(19);
	d2.push_back(18);
	d2.push_back(17);
	d2.push_back(16);
	d2.push_back(15);
	for(int a : d2)
	{
		a = 5;
		std::cout << a << " ";
	}
	std::cout << std::endl;
	DoublyLinkedList<int> copyconstruct(d2);
	for (int a : copyconstruct)
	{
		std::cout << a << " : ";
	}
	std::cout << std::endl;
	d2.pop_back();
	d2.pop_front();
	for (int a : d2)
	{
		std::cout << a << " : ";
	}
	std::cout << std::endl;

	d2 = copyconstruct;
	for (int a : d2)
	{
		std::cout << a << " : ";
	}
	std::cout << std::endl;
	d2.remove(10);
	for (int a : d2)
	{
		std::cout << a << " : ";
	}
	std::cout << std::endl;
	for (int a : copyconstruct)
	{
		std::cout << a << " : ";
	}
	std::cout << std::endl;
	d2 = d2;
	for (int a : d2)
	{
		std::cout << a << " : ";
	}
	std::cout << std::endl;
	std::cout << "wazaaaaaaaaaaaaaaaaaaaaaaaaaaa" << std::endl;
	d2.format(std::cout);


}
void stack_queue_container_test()
{
	Stack<int> s;
	s.push(1);
	s.push(3);
	s.push(2);
	Stack<int> ss(s);
	s.push(5);
	ss = s;
	ss.print();
	std::cout << std::endl;
	for (int i : ss)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	StackContainer<int> s1;
	s1.add_element(1);
	s1.add_element(78);
	s1.add_element(5);
	std::cout << std::endl;
	for (int i : s1)
	{
		std::cout << i << " ";
	}

	ListContainer<int> list1;
	list1.add_element(1);
	list1.add_element(2);
	list1.add_element(3);
	list1.add_element(4);
	list1.print();
	for (int i : list1)
	{
		std::cout << i << " ";
	}
	std::cout << s1.length();
	std::cout << s1.contains(isEven) << std::endl;
	s1.print();
	Queue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.print();
	for (int a : q)
	{
		std::cout << a << " ";
	}


}
void hc_test()
{
	std::ifstream hallo;
	hallo.open("magicNumbers.txt");
	HeterogeneousContainer<std::string> hc;
	hallo >> hc;
	hc.print();
	std::cout << hc.member("qwerty");
	hc.balanced_insert("3");
	hc.print();
	std::ofstream bye;
	bye.open("output.txt");
	bye << hc;
}
bool isEven(const int &x)
{
	return x % 2 == 0;
}