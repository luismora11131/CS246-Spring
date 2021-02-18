#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include <string>
#include <sstream>
#include "Interface.h"
#include "Node.h"

using ulong = unsigned long;

namespace ds
{
	template<class T>
	class ArrayIterator : public Iterator<T>
	{
		private:
		T* data;
		ulong capacity;
		ulong index;
		ArrayIterator();

		public:
		ArrayIterator(T* data,ulong capacity) : data(data), capacity(capacity), index(0) {}

		bool HasNext() const 
		{
			return (index != capacity);
		}

		T& Next()
		{
			if(index >= capacity)
			{
				throw "Out Of Bound";
			}
			index += 1;
			return data[index-1];
		}
	};
		
	template<class T>
	class ConstArrayIterator : public ReadOnlyIterator<T>
	{
		private:
		T* data;
		ulong capacity;
		ulong index;
		ConstArrayIterator();

		public:
		ConstArrayIterator(T* data,ulong capacity) : data(data), capacity(capacity), index(0) {}

		bool HasNext() const 
		{
			return (index != capacity);
		}

		const T& Next()
		{
			if(index >= capacity)
			{
				throw "Out Of Bound";
			}
			index += 1;
			return data[index-1];
		}
	};

	template<class T>
	class NodeIterator : public Iterator<T>
	{
		private:
		sn::Node<T>* data;
		NodeIterator();

		public:
		NodeIterator(sn::Node<T>* data) : data(data) {}

		bool HasNext() const 
		{
			return (data != NULL);
		}

		T& Next()
		{
			if(data == NULL)
			{
				throw "Out Of Bound";
			}
			sn::Node<T>* t = data;
			data = data->link;
			return t->data;
		}
	};

	template<class T>
	class ConstNodeIterator : public ReadOnlyIterator<T>
	{
		private:
		sn::Node<T>* data;
		ConstNodeIterator();

		public:
		ConstNodeIterator(sn::Node<T>* data) : data(data) {}

		bool HasNext() const 
		{
			return (data != NULL);
		}

		const T& Next()
		{
			if(data == NULL)
			{
				throw "Out Of Bound";
			}
			sn::Node<T>* t = data;
			data = data->link;
			return t->data;
		}
	};

	template<class T>
	class ArrayListIterator : public ListIterator<T>
	{
		private:
		T* data;
		ulong capacity;
		ulong index;
		ArrayListIterator();

		public:
		ArrayListIterator(T* data,ulong capacity) : data(data), capacity(capacity), index(0) {}

		bool HasNext() const 
		{
			return (index < capacity);
		}

		bool HasPrevious() const 
		{
			return (index > 0 && index <= capacity);
		}

		T& Next()
		{
			if(index >= capacity)
			{
				throw "Out Of Bound";
			}
			index += 1;
			return data[index-1];
		}

		T& Previous()
		{
			if(index <= 0 || index > capacity)
			{
				throw "Out Of Bound";
			}
			index -= 1;
			return data[index];
		}
	};

	template<class T>
	class NodeListIterator : public ListIterator<T>
	{
		private:
		dn::Node<T>* data;
		dn::Node<T>* t;
		NodeListIterator();

		public:
		NodeListIterator(dn::Node<T>* data) : data(data), t(data) {}

		bool HasNext() const 
		{
			return (data != NULL || (t != NULL && t->next != NULL));
		}

		bool HasPrevious() const 
		{
			return (data != NULL || (t != NULL && t->prev != NULL));
		}

		T& Next()
		{
			if(data == NULL && (t == NULL || t->next == NULL))
			{
				throw "Out Of Bound";
			}
			else if(data == NULL)
			{
				data = t;
			}
			else 
			{
				t = data;
				data = data->next;
			}
			return t->data;
		}

		T& Previous()
		{
			if(data == NULL && (t == NULL || t->prev == NULL))
			{
				throw "Out Of Bound";
			}
			else if(data == NULL)
			{
				data = t;
			}
			else 
			{
				t = data;
				data = data->prev;
			}
			return t->data;
		}
	};
}

#endif
