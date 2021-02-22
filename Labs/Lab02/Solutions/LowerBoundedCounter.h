#ifndef LOWERBOUNDEDCOUNTER_H
#define LOWERBOUNDEDCOUNTER_H

#include "Counter.h"

class LowerBoundedCounter : public Counter
{
	private:
	int counter;
	int minimum;

	public:	
	LowerBoundedCounter() : counter(0), minimum(0) {}
	
	LowerBoundedCounter(const LowerBoundedCounter& obj)
	{
		counter = obj.counter;
		minimum = obj.minimum;
	}

	LowerBoundedCounter& operator=(const LowerBoundedCounter& rhs)
	{
		if(this != &rhs)
		{
			counter = rhs.counter;
			minimum = rhs.minimum;
		}
		return *this;
	}

	~LowerBoundedCounter() {}

	int GetCounter() const 
	{
		return counter;
	}

	int GetMinimum() const 
	{
		return maximum;
	}

	void SetCounter(int value)
	{
		if(value >= minimum)
		{
			counter = value;
		}
	}

	void SetMinimum(int value)
	{
		if(value <= counter)
		{
			minimum = value;
		}
	}

	virtual bool Increment()
	{
		counter += 1;
		return true;
	}

	virtual bool Decrement()
	{
		if(counter > minimum)
		{
			counter -= 1;
			return true;
		}
		return false;
	}
};

#endif
