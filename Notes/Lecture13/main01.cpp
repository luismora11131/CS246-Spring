#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Array.h"

template <typename T>
void Merge(ds::Array<T>& data,int p,int q,int r)
{
	int i, lc = 0, rc = 0, ln = r - p + 1, rn = q - r;
	ds::Array<T> L(ln), R(rn);

	for(i = 0;i < ln;i += 1)
	{
		L[i] = data[p+i];
	}

	for(i = 0;i < rn;i += 1)
	{
		R[i] = data[r+1+i];
	}

	for(i = p;lc < ln && rc < rn;i += 1)
	{
		if(L[lc] <= R[rc])
		{
			data[i] = L[lc];
			lc += 1;
		}
		else
		{
			data[i] = R[rc];
			rc += 1;
		}
	}

	while(lc < ln)
	{
		data[i] = L[lc];
		lc += 1;
		i += 1;
	}

	while(rc < rn)
	{
		data[i] = R[rc];
		rc += 1;
		i += 1;
	}
}

template <typename T>
void MergeSort(ds::Array<T>& data,int p,int q)
{
	if(p < q)
	{
		int r = (p + q) / 2;
		MergeSort(data,p,r);
		MergeSort(data,r+1,q);
		Merge(data,p,q,r);
	}
}

void RandomArray(ds::Array<int>& data)
{
	int n = data.Size();

	for(int i = 0;i < n;i += 1)
	{
		data[i] = (rand() % 900) + 100;
	}
}

int main()
{
	srand(time(NULL));
	ds::Array<int> a(20);

	RandomArray(a);
	std::cout << "Before Sort:\n" << a << "\n";

	MergeSort(a,0,19);
	std::cout << "After Sort:\n" << a << "\n";
	
	return 0;
}
