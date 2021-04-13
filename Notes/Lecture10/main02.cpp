#include <iostream>
#include <string>
#include "Queue.h"

void BinaryCount(int n)
{
	std::string num = "1";
	ds::Queue<std::string> q;

	for(int i = 1;i <= n;i += 1)
	{
		std::cout << num << "\n";

		q.Enqueue(num + "0");
		q.Enqueue(num + "1");
		num = q.Peek();
		q.Dequeue();
	}
}

int main()
{
	int n;

	std::cout << "Enter a number: ";
	std::cin >> n;

	BinaryCount(n);
	return 0;
}
