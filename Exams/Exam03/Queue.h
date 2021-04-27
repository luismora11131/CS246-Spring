#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"
#include "Interface.h"

using ulong = unsigned long;

namespace ds
{
	template<class T>
	class Queue : public QueueInterface<T>
	{
		private:
		sn::Node<T>* front;
		sn::Node<T>* back;
	
		public:
		Queue() : front(NULL), back(NULL) {}

		Queue(const Queue<T>& obj)
		{
			front = sn::Copy(obj.front);
			back = front;

			if(back != NULL)
			{
				while(back->link != NULL)
				{
					back = back->link;
				}
			}
		}

		Queue<T>& operator=(const Queue<T>& rhs)
		{
			if(this != &rhs)
			{
				sn::Clear(front);
				front = sn::Copy(rhs.front);
				back = front;
				
				if(back != NULL)
				{
					while(back->link != NULL)
					{
						back = back->link;
					}
				}
			}
			return *this;
		}

		~Queue()
		{
			sn::Clear(front);
			front = NULL;
			back = NULL;
		} 

		void Enqueue(const T& itm)
		{
			if(front == NULL)
			{
				front = sn::Create(itm);
				back = front;
			}
			else
			{
				back->link = sn::Create(itm);
				back = back->link;
			}
		}

		void Dequeue()
		{
			if(front != NULL)
			{
				sn::Node<T>* t = front;
				front = front->link;
				delete t;
				t = NULL;

				if(front == NULL)
				{
					back = NULL;
				}
			}
		}

		const T& Peek() const 
		{
			if(front == NULL)
			{
				throw "Empty Queue";
			}
			return front->data;
		}

		bool IsEmpty() const 
		{
			return (front == NULL);
		}

		std::string ToString() const
		{
			std::stringstream out;

			out << "[";

			if(front != NULL)
			{
				out << front->data;
			}
			out << "]";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Queue<T>& obj)
		{
			out << obj.ToString();
			return out;
		} 
	};	
}

#endif

