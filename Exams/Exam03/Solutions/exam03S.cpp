#include <iostream>
#include <string>
#include <cctype>
#include "Node.h"
#include "Stack.h"
#include "Queue.h"

template<typename T>
void SelectionSort(ds::dn::Node<T>* root)
{
	ds::dn::Node<T>* m;

	for(ds::dn::Node<T>* i = root;i != NULL;i = i->next)
	{
		m = i;

		for(ds::dn::Node<T>* j = i->next;j != NULL;j = j->next)
		{
			if(m->data > j->data)
			{
				m = j;
			}
		}

		if(m != i)
		{
			T t = m->data;
			m->data = i->data;
			i->data = t;
		}
	}
}

std::string AdjacentDuplicateRemoval(std::string str)
{
	ds::Stack<char> s;
	
	for(int i = 0;str[i] != '\0';i += 1)
	{
		if(s.IsEmpty() || s.Top() != str[i])
		{
			s.Push(str[i]);
		}
		else
		{
			s.Pop();
		}
	}

	std::string r = "";

	while(!s.IsEmpty())
	{
		r = s.Top() + r;
		s.Pop();
	}
	return r;
}

bool QueenPath(char bd[],int s,int e)
{
	if(s >= 0 && s < 64 && e >= 0 && e < 64)
	{
		ds::Queue<int> q;
		bool visited[64];
		int v;

		for(int i = 0;i < 64;i += 1)
		{
			visited[i] = false;
		}

		q.Enqueue(s);

		while(!q.IsEmpty())
		{
			v = q.Peek();
			q.Dequeue();
			visited[v] = true;

			if(v == e || (v + 8) == e || (v - 8) == e || (v + 1) == e || (v - 1) == e)
			{
				return true;
			}

			if(v + 8 < 64 && bd[v+8] != 'o' && !visited[v+8])
			{
				q.Enqueue(v+8);
			}
			
			if(v - 8 >= 0 && bd[v-8] != 'o' && !visited[v-8])
			{
				q.Enqueue(v-8);
			}
			
			if(v + 1 < 64  && v % 8 != 7 && bd[v+1] != 'o' && !visited[v+1])
			{
				q.Enqueue(v+1);
			}
			
			if(v - 1 >= 0 && v % 8 != 0 && bd[v-1] != 'o' && !visited[v-1])
			{
				q.Enqueue(v-1);
			}
	
			if(v + 9 < 64 && v % 8 != 7 && bd[v+9] != 'o' && !visited[v+9])
			{
				q.Enqueue(v+9);
			}

			if(v + 7 < 64 && v % 8 != 0 && bd[v+7] != 'o' && !visited[v+7])
			{
				q.Enqueue(v+7);
			}
		
			if(v - 7 >= 0 && v % 8 != 7 && bd[v-7] != 'o' && !visited[v-7])
			{
				q.Enqueue(v-7);
			}

			if(v - 9 >= 0 && v % 8 != 0 && bd[v-9] != 'o' && !visited[v-9])
			{
				q.Enqueue(v-9);
			}
		}
		return false;
	}
	return false;
}

/******************************************************************************
4.
01. s := []
02. s := [0]
03. s := [0,1]
04. s := [0]
05. s := [0,2]
06. s := [0,2,0]
07. s := [0,2,0,1]
08. s := [0,2,0]
09. s := [0,2,0,2]
10. s := [0,2,0,2,0]
11. s := [0,2,0,2,0,1]
12. s := [0,2,0,2,0]
13, s := [0,2,0,2,0,2]
14. s := [0,2,0,2,0,2,0]
15. s := [0,2,0,2,0,2,0,1]
16. s := [0,2,0,2,0,2,0]
17. s := [0,2,0,2,0,2,0,2]
18. s := [0,2,0,2,0,2,0,2,0]
19. s := [0,2,0,2,0,2,0,2,0,1]
20. s := [0,2,0,2,0,2,0,2,0]
21. s := [0,2,0,2,0,2,0,2,0,2]
22. s := [0,2,0,2,0,2,0,2,0,2,0]
******************************************************************************/
	 
int main()
{
	ds::dn::Node<int>* a[5];
	
	for(int i = 0;i < 5;i += 1)
	{
		a[i] = ds::dn::Create(5-i);
	}
	
	for(int i = 0;i < 4;i += 1)
	{
		a[i]->next = a[i+1];
		a[i+1]->prev = a[i];
	}

	std::cout << "a = [";
	for(ds::dn::Node<int>* t = a[0];t != NULL;t = t->next)
	{
		std::cout << t->data;
	
		if(t->next != NULL)
		{
			std::cout << ",";
		}
	}
	std::cout << "]\n";

	SelectionSort(a[0]);

	std::cout << "a = [";
	for(ds::dn::Node<int>* t = a[0];t != NULL;t = t->next)
	{
		std::cout << t->data;
	
		if(t->next != NULL)
		{
			std::cout << ",";
		}
	}
	std::cout << "]\n";
	ds::dn::Clear(a[0]);

	std::cout << AdjacentDuplicateRemoval("passse") << "\n";
	std::cout << AdjacentDuplicateRemoval("abbaca") << "\n";
	return 0;
}
