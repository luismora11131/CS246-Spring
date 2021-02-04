#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <sstream>
#include <string>

//Abstraction Lesson Version

namespace cw1 
{
	class Rational 
	{
		public:
		int numerator;
		int denominator;
		
		//Default Constructor
		//This version uses the member initialization list
		//to initialize the fields
		Rational() : numerator(0), denominator(1) {} 
		
		//Overloaded Constructor
		Rational(int n,int d)
		{
			if(d == 0)
			{
				throw "Denominator cannot be 0";
			}
			numerator = n;
			denominator = d;
		}
		
		//Copy Constructor
		Rational(const Rational& obj)
		{
			numerator = obj.numerator;
			denominator = obj.denominator;
		}
		
		//Assignment Operator 
		Rational& operator=(const Rational& rhs)
		{
			if(this != &rhs)
			{
				numerator = rhs.numerator;
				denominator = rhs.denominator;
			}
			return *this;
		}
		
		//Destructor
		//It is empty 
		~Rational() {}
		
		//Constant ToString() Method
		//Used to create a string representation of
		//a rational object
		std::string ToString() const 
		{
			std::stringstream out;
			
			out << numerator << "/" << denominator;
			return out.str();
		}
		
		//Overloaded ostream operator
		//Allows the object to be displayed by any 
		//ostream object
		friend std::ostream& operator<<(std::ostream& out,const Rational& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}

#endif