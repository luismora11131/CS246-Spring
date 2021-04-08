#include <iostream>
#include <string>
#include "Array.h"
#include "Node.h" //singly linked node in sn namespace
using namespace std;
using namespace ds;

/******************************************************************************
BubbleSort
01. array := [7,4,5,1,2,6,3]
02. array := [7,5,4,1,2,6,3]
03. array := [7,5,4,2,1,6,3]
04. array := [7,5,4,2,6,1,3]
05. array := [7,5,4,2,6,3,1]
06. array := [7,5,4,6,2,3,1]
07. array := [7,5,4,6,3,2,1]
08. array := [7,5,6,4,3,2,1]
09. array := [7,6,5,4,3,2,1]

InsertionSort
01. array := [7,4,5,1,2,6,3]
02. array := [7,5,4,1,2,6,3]
03. array := [7,5,4,2,1,6,3]
04. array := [7,5,4,2,6,1,3]
05. array := [7,5,4,6,2,1,3]
06. array := [7,5,6,4,2,1,3]
07. array := [7,6,5,4,2,1,3]
08. array := [7,6,5,4,2,3,1]
09. array := [7,6,5,4,3,2,1]

SelectionSort
01. array := [7,4,5,1,2,6,3]
02. array := [7,6,5,1,2,4,3]
03. array := [7,6,5,4,2,1,3]
04. array := [7,6,5,4,3,1,2]
05. array := [7,6,5,4,3,2,1]
******************************************************************************/

template <typename T>
void BackAppend(sn::Node<T>*& data,sn::Node<T>* addon)
{
	if(addon != NULL)
	{
		if(data == NULL)
		{
			data = addon;
		}
		else 
		{
			sn::Node<T>* t = data;
	
			while(t->link != NULL)
			{
				t = t->link;
			}
			t->link = addon;
		}
	}
}

template <typename T>
int NthOccurrence(Array<T>& data,const T& value,int n)
{
	if(data.Size() == 0 || n <= 0)
	{
		return -1;
	}

	int cnt = 0, s = data.Size();
	
	for(int i = 0;i < n;i += 1)
	{
		if(data[i] == value)
		{
			cnt += 1;

			if(cnt == n)
			{
				return i;
			}
		}
	}
	return -1;
}

bool IsSet(Array<int>& data)
{
	int n = data.Size();

	for(int i = 0;i < n;i += 1)
	{
		for(int j = i + 1;j < n;j += 1)
		{
			if(data[i] == data[j])
			{
				return false;
			}
		}
	}
	return true;
}
   	
int main()
{
	return 0;
}
