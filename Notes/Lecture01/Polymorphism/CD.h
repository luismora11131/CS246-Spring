#ifndef CD_H
#define CD_H

#include <iostream>
#include <sstream>
#include <string>

namespace cw1
{
	//Derived Class: CD Bank Account
	//Special Member Functions and Friends 
	//are not inherited
	class CD : public Account 
	{
        	private:
        	//Change access of base method in derived class
        	//by using the using statement
        	//Deposit() will be private for CD objects
        	using Account::Deposit; 
		using Account::Withdraw;

		public:
        	//Initializes with base overloaded constructor 
		CD() : Account(500)  
		{
			std::cout << "It is a CD account\n";
		}

        	//Initializes with base overloaded constructor 
        	CD(double amt) : Account(amt)
        	{
            		std::cout << "It is a CD account\n";
        	}	

        	//Upcasting to call base class copy constructor
		CD(const CD& obj) : Account(static_cast<const Account&>(obj)) {}

		CD& operator=(const CD& rhs)
		{
			if(this != &rhs)
			{
                		Account::operator=(static_cast<const Account&>(rhs));
			}
			return *this;
		}

		~CD() {} 

        	//Overridding ToString() method
		std::string ToString() const 
		{
			std::stringstream out;
            		out << "CD " << Account::ToString();
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const CD& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}

#endif
