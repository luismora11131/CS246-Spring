#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <sstream>
#include <string>

namespace cw1
{
	//The Base Class: Bank Account
	class Account 
	{
		private: 
		static int accNumGen; //Generates Next Account Number
		int accNum; //Account Number
		long balance;

		protected:
		//Overloaded Constructor that can be accessed by
		//derived classes
		Account(double amt) : accNum(accNumGen)
		{
			if(amt < 0)
			{
				throw "Invalid amount";
			}
			balance = (long)(amt * 100);
			accNumGen += 1;
			std::cout << "Account " << accNum << " created\n";
		}

		public:
		Account() : accNum(accNumGen), balance(0) 
		{
			//You cannot initialize static fields
			//in a constructor, but you can modify
			//them
			accNumGen += 1; 
			std::cout << "Account " << accNum << " created\n";
		}

		Account(const Account& obj)
		{
			//Copies will have the same balance
			//but a different account number
			accNum = accNumGen;
			accNumGen += 1;
			balance = obj.balance;
		}

		Account& operator=(const Account& rhs)
		{
			if(this != &rhs)
			{
				accNum = accNumGen;
				accNumGen += 1;
				balance = rhs.balance;
			}
			return *this;
		}

		~Account() 
		{
			std::cout << "Account " << accNum << " destroyed\n";
		}

		//Displays balance as a double 
		double GetBalance() const 
		{
			return (balance / 100.00);
		}
 
		//This is now a virtual method
		//which means the overridden 
		//versions of this method will be
		//call for derived class pointers
		//and references
		virtual bool Deposit(double amt) 
		{
			if(amt > 0)
			{
				balance += (long)(amt * 100);
				return true;
			}
			return false;
		}

		
		virtual bool Withdraw(double amt)
		{
			if(amt > 0)
			{
				balance -= (long)(amt * 100);
				return true;
			}
			return false;
		}

		std::string ToString() const 
		{
			std::stringstream out;

			out << "Account " << accNum << ": $";

			if(balance < 0)
			{
				long value = balance * -1;
				long dollars = value / 100;
				long cents = value % 100;

				out << "(" << dollars << ".";

				if(cents < 10)
				{
					out << "0" << cents;
				}
				else 
				{
					out << cents;
				}
				out << ")";
			}
			else 
			{
				long dollars = balance / 100;
				long cents = balance % 100;
			
				out << dollars << ".";
				
				if(cents < 10) 
				{
					out << "0" << cents;
				}
				else 
				{
					out << cents;
				}
			}
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Account& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
	
	//Initialize static fields using scope resolution operator outside 
	//class body
	int Account::accNumGen = 1; 

}

#endif
