#include <iostream>
#include <string>
#include "Rational.h"
using namespace cw1; //delimit namespace

int main()
{
	try 
	{
		//Create three objects in different ways:
		//Using the default constructor
		Rational a;

		//Using the overloaded constructor
		Rational b(3,1);
		
		//Using the copy construtor
		Rational c = b, d(a); 

		//Assigning values to fields  
		a.numerator = 7;
		a.denominator = 14;
		
		//Using the assignment operator
		c = a;

		//Displaying the objects 
		std::cout << a << "\n";
		std::cout << b << "\n";
		std::cout << c << "\n";
		std::cout << d << "\n";
	}
	catch(const char* e)
	{
		std::cout << e << "\n";
	}
	return 0;
}
