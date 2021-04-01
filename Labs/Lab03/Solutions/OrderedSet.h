#ifndef ORDEREDSET_H
#define ORDEREDSET_H

#include <iostream>
#include <sstream>
#include <string>
#include "Array.h"

template <typename T>
class OrderedSet
{
	private:
	ds::Array<T> data;
	ulong size;

	public:
	OrderedSet() : size(0) 
	{
		data = ds::Array<T>(100);
	}

	OrderedSet(const OrderedSet<T>& obj)
	{
		data = obj.data;
		size = obj.size;
	}

	OrderedSet<T>& operator=(const OrderedSet<T>& rhs)
	{
		if(this != &rhs)
		{
			data = rhs.data;
			size = rhs.size;
		}
		return *this;
	}

	~OrderedSet() {}

	void Insert(const T& itm)
	{
		if(size == 0)
		{
			data[size] = itm;
			size += 1;
		}
		else if(!Contains(itm) && size < 100)
		{
			int i = size - 1;

			while(i >= 0 && itm < data[i])
			{
				data[i+1] = data[i];
				i -= 1;
			}

			data[i+1] = itm;
			size += 1;
		}
	}

	void Remove(const T& itm)
	{
		if(!IsEmpty())
		{
			ulong i = 0;

			while(i < size && data[i] != itm)
			{
				i += 1;
			}
			
			if(i != size)
			{
				size -= 1;

				for(;i < size;i += 1)
				{
					data[i] = data[i+1];
				}
			}
		}
	}

	bool IsFull() const 
	{
		return (size == 100);
	}

	bool IsEmpty() const 
	{
		return (size == 0);
	}

	ulong Count() const 
	{
		return size;
	}

	bool Contains(const T& itm)
	{
		for(ulong i = 0;i < size;i += 1)
		{
			if(data[i] == itm)
			{
				return true;
			}
		}
		return false;
	}

	std::string ToString() const 
	{
		std::stringstream out;

		out << "{";

		for(ulong i = 0;i < size;i += 1)
		{
			out << data[i];
	
			if(i + 1 < size)
			{
				out << ",";
			}
		}
		out << "}";
		return out.str();
	}

	friend std::ostream& operator<<(std::ostream& out,const OrderedSet<T>& obj)
	{
		out << obj.ToString();
		return out;
	}		
};
#endif
