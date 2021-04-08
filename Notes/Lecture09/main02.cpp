#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Stack.h"
#include "Array.h"

void StackEffect(ds::Array<int>& data)
{
	ds::Stack<int> s;
	int n = data.Length();

	for(int i = 0;i < n;i += 1)
	{
		s.Push(data[i]);
	}

	for(int i = 0;i < n;i += 1)
	{
		if(!s.IsEmpty())
		{
			data[i] = s.Top();
			s.Pop();
		}
	}
}

int main()
{
	ds::Array<int> a(10);

	for(int i = 0;i < 10;i += 1)
	{
		a[i] = rand() % 90 + 10;
	} 

	std::cout << "Before:\na = " << a << "\n";
	StackEffect(a);
	std::cout << "After:\na = " << a << "\n";

	return 0;
}
