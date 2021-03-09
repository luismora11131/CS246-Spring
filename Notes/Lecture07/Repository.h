#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <iostream>
#include <string>
#include "Array.h"

namespace ds
{
	//Generic Swap Function
	template<typename T>
	void Swap(T& a,T& b)
	{
		T t = a;
		a = b;
		b = t;
	}

	//Bubble Sort Function
	template<typename T>
	void BubbleSort(Array<T>& data)
	{
		int sz = data.Size();

		for(int i = sz - 1;i > 0;i -= 1)
		{
			for(int j = 0;j < i;j += 1)
			{
				if(data[j] > data[j+1]) 
				{
					Swap(data[j],data[j+1]);
				}
			}
		}
	}

	//Insertion Sort Function
	template<typename T>
	void InsertionSort(Array<T>& data)
	{
		int sz = data.Size();
		int j;

		for(int i = 1;i < sz;i += 1)
		{
			j = i;
			
			while(j > 0 && data[j] < data[j-1])
			{
				Swap(data[j],data[j-1]);
				j -= 1;
			}
		}
	}

	//Selection Sort Function
	template<typename T>
	void SelectionSort(Array<T>& data)
	{
		int sz = data.Size();
		int mn;

		for(int i = 0;i < sz;i += 1)
		{
			mn = i;

			for(int j = i + 1;j < sz;j += 1)
			{
				if(data[j] < data[mn])
				{
					mn = j;
				}
			}
			
			if(mn != i)
			{
				Swap(data[i],data[mn]);
			}
		}
	}  
}

#endif
