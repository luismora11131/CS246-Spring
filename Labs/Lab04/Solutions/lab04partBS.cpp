#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Node.h"

template <typename T>
bool Similar(ds::sn::Node<T>* ar1,ds::sn::Node<T>* ar2)
{
	ds::sn::Node<T> *t1 = ar1, *t2 = ar2;

	while(t1 != NULL && t2 != NULL)
	{
		if(t1->data != t2->data)
		{
			return false;
		}
		t1 = t1->link;
		t2 = t2->link;
	}
	return true;
}

int main()
{
	srand(time(NULL));	
	ds::sn::Node<int>* a = ds::sn::Create((rand() % 10 + 1)), *t, *s;
	t = a;

	for(int i = 0;i < 4;i += 1)
	{
		t->link = ds::sn::Create((rand() % 10 + 1));
		t = t->link;
	}
	ds::sn::Node<int>* b = ds::sn::Copy(a);
	t = b;

	while(t->link->link != NULL)
	{
		t = t->link;
	}
	s = t->link;
	t->link = NULL;;
	delete s;
	s = NULL;
	t = a;

	while(t != NULL)
	{
		std::cout << t->data << " ";
		t = t->link;
	}
	std::cout << "\n";
	t = b;

	while(t != NULL)
	{
		std::cout << t->data << " ";
		t = t->link;
	}
	std::cout << "\n";
	std::cout << std::boolalpha;
	std::cout << Similar(a,b) << "\n";

	ds::sn::Clear(a);
	ds::sn::Clear(b);
	return 0;
}

