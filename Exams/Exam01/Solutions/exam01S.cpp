#include <iostream>
#include <string>
#include "Array.h"

/************************************************
* Problem 1 start below here
cost	| time		| operation
1	| 1		| int n = a.Size();
1	| 1		| int m = (a[0] < a[n-1])?(a[0]):(a[n-1]);
1	| 1		| int i = 1
1	| n/2		| i < n / 2
1	| n/2 - 1	| int t = (a[i] < a[n-(i+1)])?(a[i]):(a[n-(i+1)]);
1	| n/2 - 1	| m > t
1	| n/2 - 1	| m = t
1	| n/2 - 1	| i += 1
1	| 1		| return m;

T(n) = 5 * (n / 2) where n is the size of the array

* Problem 1 ends above here
*************************************************/

template <typename T>
ulong indexOfValueAfter(const ds::Array<T>& data,const T& value,const T& delimit)
{
	ulong n = data.Size();
	ulong idx = 0;

	if(n == 0)
	{
		return 0;
	}

	while(idx < n)
	{
		if(data[idx] == delimit)
		{
			break;
		}
		idx += 1;
	}
	
	if(idx == n)
	{
		return n;
	}
	
	for(ulong i = idx + 1;i < n;i += 1)
	{
		if(data[i] == value)
		{
			return i;
		}
	}
	return n;
}

template <typename T>
bool Complement(const ds::Array<T>& ar1,const ds::Array<T>& ar2)
{
	ulong n1 = ar1.Size();
	ulong n2 = ar2.Size();

	if(n1 == 0 && n2 == 0)
	{
		return false;
	}

	for(ulong i = 0;i < n1;i += 1)
	{
		for(ulong j = 0;j < n2;j += 1)
		{
			if(ar2[j] == ar1[i])
			{
				return false;
			}
		}
	}
	return true;
}

class Identifier
{
	char middleInitial;
	std::string lastName;
	std::string firstName;
	
	public:
	Identifier() : firstName("Jane"), lastName("Doe"), middleInitial('N') {}
	
	Identifier(const Identifier& obj)
	{
		firstName = obj.firstName;
		lastName = obj.lastName;
		middleInitial = obj.middleInitial;
	} 	

	Identifier& operator=(const Identifier& rhs)
	{
		if(this != &rhs)
		{
			firstName = rhs.firstName;
			lastName = rhs.lastName;
			middleInitial = rhs.middleInitial;
	 	}
		return *this;
	}

	~Identifier() {}
};
		
int main()
{
	return 0;
}

//Nothing must be written after the main function
