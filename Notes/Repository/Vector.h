#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <sstream>
#include <initializer_list>
#include "Interface.h"
#include "Iterator.h"

using ulong = unsigned long;

namespace ds
{
	template<class T>
	class Vector : public List<T>
	{
		private:
		T* data;
		ulong size;
		ulong capacity;
	
		void Resize()
		{
			ulong tcp = capacity, i;
			T* cpy = new T[capacity];

			for(i = 0;i < tcp;i += 1)
			{
				cpy[i] = data[i];
			}
			delete[] data;
			capacity *= 2;
			data = new T[capacity];

			for(i = 0;i < tcp;i += 1)
			{
				data[i] = cpy[i];
			}
			delete[] cpy;
		}
	
		public:
		Vector() : capacity(50), size(0) 
		{
			data = new T[capacity];
		}
		
		Vector(ulong cp,const T& itm) : capacity(cp), size(cp)
		{
			data = new T[capacity];

			for(ulong i = 0;i < size;i += 1)
			{
				data[i] = itm;
			}
		}

		Vector(std::initializer_list<T> lt)
		{
			capacity = lt.size();
			size = lt.size();
			data = new T[capacity];
			ulong i = 0;

			for(T x : lt)
			{
				data[i] = x;
				i += 1;
			}
		}

		Vector(const Vector<T>& obj)
		{
			capacity = obj.capacity;
			size = obj.size;
			data = new T[capacity];

			for(ulong i = 0;i < size;i += 1)
			{
				data[i] = obj.data[i];
			}
		}

		Vector<T>& operator=(const Vector<T>& rhs)
		{
			if(this != &rhs)
			{
				capacity = rhs.capacity;
				size = rhs.size;
				delete[] data;
				data = new T[capacity];

				for(ulong i = 0;i < size;i += 1)
				{
					data[i] = rhs.data[i];
				}
			}
			return *this;
		}

		~Vector()
		{
			delete[] data;
		} 

		ulong Size() const 
		{
			return size;
		}

		void Insert(const T& itm)
		{
			if(size == capacity)
			{
				Resize();
			}
			data[size] = itm;
			size += 1;
		}

		void Remove(const T& itm)
		{
			ulong idx = 0;

			while(idx < size && data[idx] != itm)
			{
				idx += 1;
			}

			if(idx != size)
			{
				size -= 1;
				
				while(idx < size)
				{
					data[idx] = data[idx+1];
					idx += 1;
				}
			}
		}

		bool Contains(const T& itm) const
		{
			ulong idx = 0;

			while(idx < size && data[idx] != itm)
			{
				idx += 1;
			}
			return (idx != size);
		}

		ulong Search(const T& itm) const
		{
			ulong idx = 0;

			while(idx < size && data[idx] != itm)
			{
				idx += 1;
			}
			return idx;
		}

		bool IsEmpty() const 
		{
			return (size == 0);
		}

		T& operator[](ulong idx)
		{
			if(idx >= size)
			{
				throw "Out Of Bound";
			}
			return data[idx];
		}
	
		const T& operator[](ulong idx) const
		{
			if(idx >= size)
			{
				throw "Out Of Bound";
			}
			return data[idx];
		}
	
		ListIterator<T>* GetIterator() 
		{
			return new ArrayListIterator<T>(data,size);
		}

		std::string ToString() const
		{
			std::stringstream out;

			out << "[";

			for(ulong i = 0;i < size;i += 1)
			{
				out << data[i];

				if((i + 1) < size)
				{
					out << ",";
				}
			}
			out << "]";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Vector<T>& obj)
		{
			out << obj.ToString();
			return out;
		} 
	};	
}

#endif

