#include <iostream>
#include <string>
#include "Array.h"

template <typename T>
ulong OutOfPlace(ds::Array<T>& data)
{
	ulong n = data.Size(), i = 1;

	for(;i < n;i += 1)
	{
		if(data[i-1] > data[i]) 
		{
			return (i - 1);
		}
	}
	return data.Size();
}

int main()
{
	ds::Array<int> a = {1,2,6,3,4,5}, b = {6,1,2,3,4,5};
	std::cout << "data = " << a << " OutOfPlace(data) = " << OutOfPlace(a) << "\n";
	std::cout << "data = " << b << " OutOfPlace(data) = " << OutOfPlace(b) << "\n";
	return 0;
}
