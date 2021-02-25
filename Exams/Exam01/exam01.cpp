#include <iostream>
#include <string>
#include "Array.h"

/************************************************
* Problem 1 start below here
Runtime Table 
cost	| time	| operation 
================================================
1	| 1	| int n = a.Size();
1	| 1	| int m = (a[0] < a[n-1])?(a[0]):(a[n-1]);
1	| 1	| int i = 1;
1	| n	| i < n / 2;
1	| n - 1| int t = (a[i] < a[n-(i+1)])?(a[i]):(a[n-1]);
1	| n - 1| m > t;
1	| n - 1	| m = t;
1	| 1	| return m;
=================================================
T(n) = 4n + 3 
* Problem 1 ends above here
************************************************/

// Problem 2
template <typename T>
ulong IndexOfValueAfter(const Array<T> &data, const T &value, const T &delimit)
{
	bool after = false;
	bool found = false;
	for (int i = 0; i < data.Length(); i++)
	{
		if (data[i] == delimit)
		{
			after = true;
		}
		if (after == true)
		{
			if (data[i] == value)
			{
				bool found = true;
				return i;
			}
		}
	}
	if ((after == false) || (found == false) || (data.Length() == 0))
	{
		return data.Length();
	}
}

// Problem 3
template <typename T>
bool Complement(const Array<T> &ar1, const Array<T> &ar2)
{
	for (int a = 0; a < ar1.Length(); a++)
	{
		for (int b = 0; a < ar2.Length(); b++)
		{
			if (ar1[a] == ar2[b])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

// Problem 4
class Identifier
{
private:
	char middleInitial = 'N';
	string lastName = "Doe";
	string firstName = "Jane";
}

int
main()
{
	//declare the class
	// Identifier FullName;
	//use the class
	// FullName.middleInitial = 'N';
	// FullName.lastName = "Doe";
	// FullName.firstName = "Jane";

	return 0;
}

//Nothing must be written after the main function
