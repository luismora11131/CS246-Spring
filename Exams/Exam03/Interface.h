#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>
#include <sstream>

using ulong = unsigned long;

namespace ds
{
	template<class T>
	class StackInterface
	{
		public:
		virtual void Push(const T&) = 0;
		virtual void Pop() = 0;
		virtual const T& Top() const = 0;
		virtual bool IsEmpty() const = 0;
	};

	template<class T>
	class QueueInterface
	{
		public:
		virtual void Enqueue(const T&) = 0;
		virtual void Dequeue() = 0;
		virtual const T& Peek() const = 0;
		virtual bool IsEmpty() const = 0;
	};
}

#endif
