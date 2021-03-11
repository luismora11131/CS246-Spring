#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"

namespace ds
{
	namespace sn
	{
		template<typename T>
		void Insert(Node<T>*& rt,Node<T>* nd,const T& itm)
		{
			if(rt == NULL)
			{
				rt = Create(itm);
			}
			else if(nd == NULL)
			{
				Node<T>* t = Create(itm);
				t->link = rt;
				rt = t;
			}
			else
			{
				Node<T>* t = Create(itm);
				t->link = nd->link;
				nd->link = t;
			}
		}

		template<typename T>
		void Remove(Node<T>*& rt,Node<T>* nd)
		{
			if(rt != NULL && nd != NULL)
			{
				if(rt == nd)
				{
					rt = rt->link;
					delete nd;
					nd = NULL;
				}
				else 
				{
					Node<T>* t = rt;

					while(t->link != nd)
					{
						t = t->link;
					}
					t->link = nd->link;
					delete nd;
					nd = NULL;
				}
			}
		}
	}

	namespace dn
	{
		template<typename T>
		void Insert(Node<T>*& rt,Node<T>* nd,const T& itm)
		{
			if(rt == NULL)
			{
				rt = Create(itm);
			}
			else if(nd == NULL)
			{
				Node<T>* t = Create(itm);
				t->next = rt;
				rt->prev = t;
				rt = t;
			}
			else 
			{
				Node<T>* t = Create(itm);
				t->next = nd->next;
				nd->next = t;
				t->prev = nd;
	
				if(t->next != NULL)
				{
					t->next->prev = t;
				}
			}
		}

		template<typename T>
		void Remove(Node<T>*& rt,Node<T>* nd)
		{
			if(rt != NULL && nd != NULL)
			{
				if(rt == nd)
				{
					rt = rt->next;
					delete nd;
					nd = NULL;

					if(rt != NULL)
					{
						rt->prev = NULL;
					}
				}
				else
				{
					nd->prev->next = nd->next;

					if(nd->next != NULL)
					{
						nd->next->prev = nd->prev;
					}
					delete nd;
					nd = NULL;
				}
			}
		}
	}

}

#endif
