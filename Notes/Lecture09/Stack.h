#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"
#include "Interface.h"

using ulong = unsigned long;

namespace ds
{
	template<class T>
	class Stack : public StackInterface<T>
	{
		private:
		sn::Node<T>* head;
	
		public:
		Stack() : head(NULL) {}

		Stack(const Stack<T>& obj)
		{
			head = sn::Copy(obj.head);
		}

		Stack<T>& operator=(const Stack<T>& rhs)
		{
			if(this != &rhs)
			{
				sn::Clear(head);
				head = sn::Copy(rhs.head);
			}
			return *this;
		}

		~Stack()
		{
			sn::Clear(head);
			head = NULL;
		} 

		void Push(const T& itm)
		{
			sn::Node<T>* t = sn::Create(itm);
			t->link = head;
			head = t;
		}

		void Pop()
		{
			if(head != NULL)
			{
				sn::Node<T>* t = head;
				head = head->link;
				delete t;
				t = NULL;
			}
		}

		const T& Top() const 
		{
			if(head == NULL)
			{
				throw "Empty Stack";
			}
			return head->data;
		}

		bool IsEmpty() const 
		{
			return (head == NULL);
		}

		std::string ToString() const
		{
			std::stringstream out;

			out << "[";

			if(head != NULL)
			{
				out << head->data;
			}
			out << "]";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Stack<T>& obj)
		{
			out << obj.ToString();
			return out;
		} 
	};	
}

#endif

