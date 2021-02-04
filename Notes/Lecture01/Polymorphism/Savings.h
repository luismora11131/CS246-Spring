#ifndef SAVINGS_H
#define SAVINGS_H

#include <iostream>
#include <sstream>
#include <string>

namespace cw1
{
	//Derived Class: Savings Bank Account
	//Special Member Functions and Friends 
	//are not inherited
	class Savings : public Account 
	{
		public:
    		//Base class default constructor used
        	//for initialization of the Checking
        	//constructor since no constructor is
        	//explicitly called
		Savings()  
		{
			std::cout << "It is a savings account\n";
		}

        	//Initializes with base overloaded constructor 
        	Savings(double amt) : Account(amt)
        	{
            		std::cout << "It is a checking account\n";
        	}

        	//Upcasting to call base class copy constructor
		Savings(const Savings& obj) : Account(static_cast<const Account&>(obj)) {}

		Savings& operator=(const Savings& rhs)
		{
			if(this != &rhs)
			{
                		Account::operator=(static_cast<const Account&>(rhs));
			}
			return *this;
		}

		~Savings() {} 

        	//Overridding Widthdraw to prohibit overdraws
        	bool Withdraw(double amt)
        	{
            		//Since GetBalance() is not
            		//overridden in Savings the
            		//compiler knows you are 
            		//referring to Account 
            		if(amt < GetBalance()) 
            		{
                		Account::Withdraw(amt);
            		} 
            		return false;          
        	}

        	//Overridding ToString() method
		std::string ToString() const 
		{
			std::stringstream out;
            		out << "Savings " << Account::ToString();
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Savings& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}

#endif
