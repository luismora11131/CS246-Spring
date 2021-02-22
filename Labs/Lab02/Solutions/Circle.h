#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
	private:
	double radius;
	static const double PI;

	public:	
	Circle() : radius(1) {}
	
	Circle(const Circle& obj)
	{
		radius = obj.radius;
	}

	Circle& operator=(const Circle& rhs)
	{
		if(this != &rhs)
		{
			radius = rhs.radius;
		}
		return *this;
	}

	~Circle() {}

	double GetRadius() const 
	{
		return radius;
	}

	static double GetPI()
	{
		return PI;
	}

	double GetDiameter() const 
	{
		return 2 * PI;
	}

	void SetRadius(double value)
	{
		if(value > 0)
		{
			radius = value;
		}
	}

	virtual double Area() const
	{
		return (PI * radius * radius);
	}

	virtual double Perimeter() const
	{
		return (2 * PI * radius);
	}
};

const double Circle::PI = 3.141592;

#endif
