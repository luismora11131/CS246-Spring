#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Array.h"

#define PARENT(X)	(((X) - 1) / 2)
#define LEFT(X)		(2 * (X) + 1)
#define RIGHT(X)	(2 * (X) + 2)

template <typename T>
bool Contains(ds::tn::Node<T>* rt,const T& itm)
{
	if(rt == NULL)
	{
		return false;
	}
	else if(rt->data == itm)
	{
		return true;
	}
	else 
	{
		return (Contains(rt->left,itm) || Contains(rt->right,itm));
	}
}

template <typename T>
int Size(ds::tn::Node<T>* rt)
{
	if(rt == NULL)
	{
		return 0;
	}
	else 
	{
		return 1 + Size(rt->left) + Size(rt->right);
	}
}

template <typename T>
void Insert(ds::tn::Node<T>*& rt,const T& itm)
{
	if(rt == NULL)
	{
		rt = ds::tn::Create(itm);
	}
	else
	{
		//find path
		int n = Size(rt);
		int c = 0;
		ds::Array<int> path(n);

		while(n > 0)
		{
			path[c] = PARENT(n);
			n = PARENT(n);
			c += 1;
		}
		c -= 1;
		
		ds::tn::Node<T>* t = rt;

		while(c > 0)
		{
			if(path[c] % 2 == 1)
			{
				t = t->left;
			}
			else
			{
				t = t->right;
			}
			c -= 1;
		}

		//insert node
		if(t->left == NULL)
		{
			t->left = ds::tn::Create(itm);
		}
		else
		{
			t->right = ds::tn::Create(itm);
		}
	}
}

void RandomTree(ds::tn::Node<int>*& rt,int n)
{
	for(int i = 0;i < n;i += 1)
	{
		Insert(rt,((rand() % 900) + 100));
	}
}

void Print(ds::tn::Node<int>* rt)
{
	if(rt != NULL)
	{
		Print(rt->left);
		std::cout << rt->data << " ";
		Print(rt->right);
	}
}

int main()
{
	srand(time(NULL));
	ds::tn::Node<int>* a = NULL;
	int n;

	RandomTree(a,7);
	std::cout << "Before Sort:\n";
	Print(a);
	std::cout << "\n";

	std::cout << "Enter a value: ";
	std::cin >> n;

	std::cout << n << ((Contains(a,n))?(" is "):(" is not ")) << " contained in a\n";
	ds::tn::Clear(a);

	return 0;
}
