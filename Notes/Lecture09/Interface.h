#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>
#include <sstream>

using ulong = unsigned long;

namespace ds
{
	template<class T>
	class Iterator
	{
		public:
		virtual bool HasNext() const = 0;
		virtual T& Next() = 0;
	};

	template<class T>
	class ReadOnlyIterator
	{
		public:
		virtual bool HasNext() const = 0;
		virtual const T& Next() = 0;
	};

	template<class T>
	class ListIterator : public Iterator<T>
	{
		public:
		virtual bool HasPrevious() const = 0;
		virtual T& Previous() = 0;
	};

	template<class T>
	class Collection
	{
		public:
		virtual void Insert(const T&) = 0;
		virtual void Remove(const T&) = 0;
		virtual bool Contains(const T&) const = 0;
		virtual ulong Size() const = 0;
		virtual bool IsEmpty() const = 0;
		virtual std::string ToString() const = 0;
	};

	template<class T>
	class List : public Collection<T>
	{
		public:
		virtual ulong Search(const T&) const = 0;
		virtual T& operator[](ulong) = 0;
		virtual const T& operator[](ulong) const = 0;
		virtual ListIterator<T>* GetIterator() = 0;
	};

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

	template<class K,class V>
	class MapInterface
	{
		public:
		virtual void Put(const K&,const V&) = 0;
		virtual V& Get(const K&) = 0;
		virtual const V& Get(const K&) const = 0;
		virtual void Remove(const K&) = 0;
		virtual bool IsEmpty() const = 0;
		virtual ulong Size() const = 0;
		virtual bool Contains(const K&) const = 0;
		virtual V& operator[](const K&) = 0;
		virtual const V& operator[](const K&) const = 0;
	}; 
}

#endif
