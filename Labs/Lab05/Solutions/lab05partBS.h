#ifndef LAB05PARTB_H
#define LAB05PARTB_H

#include <iostream>
#include <string>
#include <sstream>
#include "Interface.h"
#include "Stack.h"
#include "Node.h"

class MaxStack : public ds::StackInterface<int> 
{
	private:
	int data[100];
	int top;
	int max;

	public:
	MaxStack() : top(0), max(-1) {}

	MaxStack(const MaxStack& obj)
	{
		top = obj.top;
		max = obj.max;

		for(int i = 0;i < top;i += 1)
		{
			data[i] = obj.data[i];
		}
	}

	MaxStack& operator=(const MaxStack& rhs)
	{
		if(this != &rhs)
		{
			top = rhs.top;
			max = rhs.max;

			for(int i = 0;i < top;i += 1)
			{
				data[i] = rhs.data[i];
			}
		}
		return *this;
	}

	~MaxStack() {}

	void Push(const int& itm)
	{
		if(top < 100)
		{
			if(max == -1 || data[max] < itm)
			{
				max = top;
			}
			data[top] = itm;
			top += 1;
		}
	}

	void Pop() 
	{
		if(top > 0)
		{
			top -= 1;
			
			if(top == 0)
			{
				max = -1;
			}
			else if(max >= top)
			{
				max = 0;

				for(int i = 1;i < top;i += 1)
				{
					if(data[max] < data[i])
					{
						max = i;
					}
				}
			}	
		}
	}

	const int& Top() const 
	{
		if(top == 0)
		{
			throw "Empty Stack";
		}
		return data[top-1];
	}

	const int& Max() const 
	{
		if(top == 0)
		{
			throw "Empty Stack";
		}
		return data[max];
	}

	bool IsEmpty() const 
	{
		return (top == 0);
	}

	bool IsFull() const 
	{
		return (top == 100);
	}

	std::string ToString() const 
	{
		std::stringstream out;
		out << "(";
		if(top != 0)
		{
			out << data[top-1] << "," << data[max];
		}
		out << ")";
		return out.str();
	}

	friend std::ostream& operator<<(std::ostream& out,const MaxStack& obj)
	{
		out << obj.ToString();
		return out;
	}
};

#endif
