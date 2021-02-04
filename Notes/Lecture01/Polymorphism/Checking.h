#ifndef CHECKING_H
#define CHECKING_H

#include <iostream>
#include <sstream>
#include <string>

namespace cw1
{
	//Derived Class: Checking Bank Account
	//Special Member Functions and Friends 
	//are not inherited
	class Checking : public Account 
	{
		public:
		//Base class default constructor used
		//for initialization of the Checking
		//constructor since no constructor is
		//explicitly called
		Checking()  
		{
			std::cout << "It is a checking account\n";
		}

		//Initializes with base overloaded constructor 
		Checking(double amt) : Account(amt)
		{
			std::cout << "It is a checking account\n";
		}

		//Upcasting to call base class copy constructor
		Checking(const Checking& obj) : Account(static_cast<const Account&>(obj)) {}

		Checking& operator=(const Checking& rhs)
		{
			if(this != &rhs)
			{
				Account::operator=(static_cast<const Account&>(rhs));
			}
			return *this;
		}

		~Checking() {} 

		//Overridding ToString() method
		std::string ToString() const 
		{
			std::stringstream out;
			out << "Checking " << Account::ToString();
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Checking& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}

#endif
