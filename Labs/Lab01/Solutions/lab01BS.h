#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class Point
{
	private:
	double coor[2];

	public:
	Point() 
	{
		coor[0] = 0;
		coor[1] = 0;
	}

	Point(const Point& obj)
	{
		coor[0] = obj.coor[0];
		coor[1] = obj.coor[1];
	}

	Point& operator=(const Point& rhs)
	{
		if(this != &rhs)
		{
			coor[0] = rhs.coor[0];
			coor[1] = rhs.coor[1];
		}
		return *this;
	}

	~Point() {}

	double GetX() const
	{
		return coor[0];
	}

	double GetY() const 
	{
		return coor[1];
	}

	void SetX(double value)
	{
		coor[0] = value;
	}

	void SetY(double value)
	{
		coor[1] = value;
	}

	std::string ToString() const 
	{
		std::stringstream out;
		
		out << std::fixed << std::setprecision(2) << "(" << coor[0] << "," << coor[1] << ")";
		return out.str(); 
	}

	friend std::ostream& operator<<(std::ostream& out,const Point& obj)
	{
		out << obj.ToString();
		return out;
	}
};
#endif
