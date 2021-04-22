#ifndef LAB06S_H
#define LAB06S_H

#include <iostream>
#include <string>
#include <sstream>
#include "Deque.h"

namespace ds
{
	template<class T>
	void Deque<T>::InsertFirst(const T& itm)
	{
		if(front == NULL)
		{
			front = dn::Create(itm);
			back = front;
		}
		else
		{
			front->prev = dn::Create(itm);
			front->prev->next = front;
			front = front->prev;
		}
	}

	template<class T>	
	void Deque<T>::InsertLast(const T& itm)
	{
		if(front == NULL)
		{
			front = dn::Create(itm);
			back = front;
		}
		else
		{
			back->next = dn::Create(itm);
			back->next->prev = back;
			back = back->next;
		}
	}

	template<class T>
	void Deque<T>::RemoveFirst()
	{
		if(front != NULL)
		{
			dn::Node<T>* t = front;
			front = front->next;
			delete t;
			t = NULL;

			if(front == NULL)
			{
				back = NULL;
			}
			else 
			{
				front->prev = NULL;
			}
		}
	}

	template<class T>
	void Deque<T>::RemoveLast()
	{
		if(back != NULL)
		{
			dn::Node<T>* t = back;
			back = back->prev;
			delete t;
			t = NULL;

			if(back == NULL)
			{
				front = NULL;
			}
			else
			{
				back->next = NULL;
			}
		}
	}
}

#endif

