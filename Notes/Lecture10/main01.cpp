#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Queue.h"
#include "Array.h"

void QueueWrite(ds::Array<int>& data)
{
	ds::Queue<int> q;
	int n = data.Size();

	for(int i = 0;i < n;i += 1)
	{
		q.Enqueue(data[i]);
	}

	for(int i = 0;i < n;i += 1)
	{
		if(!q.IsEmpty())
		{
			data[i] = q.Peek(); 
			q.Dequeue();
		}
	}
}

int main()
{
	srand(time(NULL));
	
	ds::Array<int> a(10);

	for(int i = 0;i < 10;i += 1)
	{
		a[i] = rand() % 90 + 10;
	}

	std::cout << "Before:\n" << a << "\n";
	QueueWrite(a);
	std::cout << "After:\n" << a << "\n"; 
	return 0;
}
