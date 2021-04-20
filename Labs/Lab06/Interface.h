#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>
#include <sstream>

namespace ds
{
	template<class T>
	class DequeInterface
	{
		public:
		virtual void InsertFirst(const T&) = 0;
		virtual void InsertLast(const T&) = 0;
		virtual void RemoveFirst() = 0;
		virtual void RemoveLast() = 0;
		virtual const T& First() const = 0;
		virtual const T& Last() const = 0;
		virtual bool IsEmpty() const = 0;
	};
}

#endif
