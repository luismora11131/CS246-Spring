#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <sstream>
#include <initializer_list>

using ulong = unsigned long;

namespace ds
{
	template<class T>
	class Array
	{
		private:
		T* data;
		ulong capacity;
		
		public:
		Array() : capacity(30) 
		{
			data = new T[capacity];
			
			for(ulong i = 0;i < capacity;i += 1)
			{
				data[i] = T();
			}
		}
		
		Array(ulong cp) : capacity(cp)
		{
			data = new T[capacity];

			for(ulong i = 0;i < capacity;i += 1)
			{
				data[i] = T();
			}
		}

		Array(std::initializer_list<T> lt)
		{
			capacity = lt.size();
			data = new T[capacity];
			int i = 0;

			for(const T& x : lt)
			{	
				data[i] = x;
				i += 1;
			}
		}

		Array(const Array<T>& obj)
		{
			capacity = obj.capacity;
			data = new T[capacity];

			for(ulong i = 0;i < capacity;i += 1)
			{
				data[i] = obj.data[i];
			}
		}

		Array<T>& operator=(const Array<T>& rhs)
		{
			if(this != &rhs)
			{
				capacity = rhs.capacity;
				delete[] data;
				data = new T[capacity];

				for(ulong i = 0;i < capacity;i += 1)
				{
					data[i] = rhs.data[i];
				}
			}
			return *this;
		}

		~Array()
		{
			delete[] data;
		} 

		ulong Size() const 
		{
			return capacity;
		}

		T& operator[](ulong idx)
		{
			if(idx >= capacity)
			{
				throw "Out Of Bound";
			}
			return data[idx];
		}
	
		const T& operator[](ulong idx) const
		{
			if(idx >= capacity)
			{
				throw "Out Of Bound";
			}
			return data[idx];
		}

		std::string ToString() const
		{
			std::stringstream out;

			out << "[";

			for(ulong i = 0;i < capacity;i += 1)
			{
				out << data[i];

				if((i + 1) < capacity)
				{
					out << ",";
				}
			}
			out << "]";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Array<T>& obj)
		{
			out << obj.ToString();
			return out;
		} 
	};	
}

#endif

