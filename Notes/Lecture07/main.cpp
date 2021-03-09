#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.h"
#include "Repository.h"

int main()
{
	ds::Array<int> a[3];
	srand(time(NULL));

	for(int i = 0;i < 20;i += 1)
	{
		a[0][i] = (rand() % 100) + 1;
	}

	a[1] = a[0];
	a[2] = a[0];

	for(int i = 0;i < 3;i += 1)
	{
		std::cout << a[i] << "\n";
	}

	ds::BubbleSort(a[0]);
	ds::InsertionSort(a[1]);
	ds::SelectionSort(a[2]);

	std::cout << "\n";	
	
	for(int i = 0;i < 3;i += 1)
	{
		std::cout << a[i] << "\n";
	}
	return 0;
}
