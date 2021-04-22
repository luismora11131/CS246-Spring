#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Queue.h"

void PopulateBoard(char board[])
{
	for(int i = 0;i < 64;i += 1)
	{
		board[i] = (rand() % 3 == 0)?('o'):('x');
	}
}

void DisplayBoard(char board[])
{
	std::cout << "  ";
	for(int i = 0;i < 8;i += 1)
	{
		std::cout << i << " ";
	}
	std::cout << "\n";

	for(int i = 0,j = 0;i < 64;i += 1)
	{
		if(i % 8 == 0)
		{
			std::cout << j << " ";
			j += 1;
		}

		std::cout << board[i] << " ";

		if((i + 1) % 8 == 0)
		{
			std::cout << "\n";
		}
	}
	std::cout << "\n";
}

bool RookPath(char board[],int s,int e)
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

			if(v + 8 < 64 && board[v+8] != 'o' && !visited[v+8])
			{
				q.Enqueue(v+8);
			}
			
			if(v - 8 >= 0 && board[v-8] != 'o' && !visited[v-8])
			{
				q.Enqueue(v-8);
			}
			
			if(v + 1 < 64  && v % 8 != 7 && board[v+1] != 'o' && !visited[v+1])
			{
				q.Enqueue(v+1);
			}
			
			if(v - 1 >= 0 && board[v-1] != 'o' && !visited[v-1])
			{
				q.Enqueue(v-1);
			}
		}
		return false;
	}
	return false;
}

int main()
{
	srand(time(NULL));
	int s, e;
	char b[64];

	PopulateBoard(b);
	DisplayBoard(b);

	std::cout << "Enter start position: ";
	std::cin >> s;
	std::cout << "Enter end position: ";
	std::cin >> e;

	std::cout << std::boolalpha;
	std::cout << "RookPath(b," << s << "," << e << ") = " << RookPath(b,s,e) << "\n";
	
	return 0;
}
