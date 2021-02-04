#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <sstream>
#include <string>

//Enapsulation Lesson Version

namespace cw1 
{
	class Rational 
	{
		private:
		int numerator;
		int denominator;
		bool sign;

		public:
		//Default Constructor
		//This version uses the member initialization list
		//to initialize the fields
		Rational() : numerator(0), denominator(1), sign(false) {} 
		
		//Overloaded Constructor
		Rational(int n,int d)
		{
			if(d == 0)
			{
				throw "Denominator cannot be 0";
			}

			sign = (n * d) < 0;
			numerator = (n < 0)?(-1 * n):(n);
			denominator = (d < 0)?(-1 * d):(d);
		}
		
		//Copy Constructor
		Rational(const Rational& obj)
		{
			sign = obj.sign;
			numerator = obj.numerator;
			denominator = obj.denominator;
		}
		
		//Assignment Operator 
		Rational& operator=(const Rational& rhs)
		{
			if(this != &rhs)
			{
				sign = rhs.sign;
				numerator = rhs.numerator;
				denominator = rhs.denominator;
			}
			return *this;
		}
		
		//Destructor
		//It is empty 
		~Rational() {}
		
		//Get Methods [Read Methods]
		//Only the numerator will be represented as
		//negative if sign is true
		int GetNumerator() const
		{
			return (sign)?(-1 * numerator):(numerator);
		}

		int GetDenominator() const 
		{
			return denominator;
		}

		//Non-constant versions. Not actually necessary,
		//but you can define both without an error 
		int GetNumerator() 
		{
			return (sign)?(-1 * numerator):(numerator);
		}

		int GetDenominator() 
		{
			return denominator;
		}

		//Set Methods [Write Methods]
		//Set methods cannot be constant
		void SetNumerator(int value)
		{
			if(value < 0)
			{
				sign = true;
				numerator = (-1 * value);
			}
			else
			{
				sign = false;
				numerator = value;
			}
		}

		//Only change the denominator if the parameter is 
		//not zero
		void SetDenominator(int value)
		{
			if(value != 0)
			{
				if(value < 0)
				{
					sign = true;
					denominator = (-1 * value);
				}
				else 
				{
					sign = false;
					denominator = value;
				}
			}
		} 

		//Constant ToString() Method
		//Used to create a string representation of
		//a rational object
		std::string ToString() const 
		{
			std::stringstream out;
			
			if(sign)
			{
				out << "-";
			}
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
