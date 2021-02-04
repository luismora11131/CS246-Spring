#include <iostream>
#include <string>
#include <typeinfo>
#include "Account.h"
#include "Checking.h"
#include "Savings.h"
#include "CD.h"
using namespace cw1;

void Withdraw(Account& acct,double amt)
{
	if(typeid(acct).name() == typeid(Account).name())
	{
		std::cout << "Account Type: Account\n";
	}
	else if(typeid(acct).name() == typeid(Checking).name())
	{
		std::cout << "Account Type: Checking\n";
	}
	else if(typeid(acct).name() == typeid(Savings).name())
	{
		std::cout << "Account Type: Savings\n";
	}
	acct.Withdraw(amt);
}

int main()
{
	Account acc;
    	Checking acc2(500);
    	Savings acc3;
    	CD acc4(10000.00);

    	std::cout << "Account Run\n";
    	std::cout << acc << "\n";
    	acc.Deposit(700.00);
    	std::cout << acc << "\n";
    	acc.Withdraw(800.50);
    	std::cout << acc << "\n";

    	std::cout << "\nChecking Run\n";
    	std::cout << acc2 << "\n";
    	acc2.Deposit(700.00);
    	std::cout << acc2 << "\n";
    	acc2.Withdraw(800.50);
    	std::cout << acc2 << "\n";

    	std::cout << "\nSavings Run\n";
    	std::cout << acc3 << "\n";
    	acc3.Deposit(700.00);
    	std::cout << acc3 << "\n";
    	acc3.Withdraw(800.50);
    	std::cout << acc3 << "\n";

    	std::cout << "\nCD Run\n";
    	std::cout << acc4 << "\n";
    	//If you remove the comment symbols 
    	//you will receive an error
    	//acc4.Deposit(700.00);
    	std::cout << acc4 << "\n";
    	//acc4.Withdraw(800.50);
    	std::cout << acc4 << "\n";

    	std::cout << "CD Copy\n";
    	CD acc5 = acc4;
    	std::cout << acc5 << "\n";

	std::cout << "Withdraw Function Calls\n\n";
	std::cout << "Account 1 (Standard): Withdraw 1000.00\n";
	std::cout << "Old Balance: " << acc.GetBalance() << "\n";
	Withdraw(acc,1000);
	std::cout << "New Balance: " << acc.GetBalance() << "\n\n";

	std::cout << "Account 2 (Checking): Withdraw 1000.00\n";
	std::cout << "Old Balance: " << acc2.GetBalance() << "\n";
	Withdraw(acc2,1000);
	std::cout << "New Balance: " << acc2.GetBalance() << "\n\n";
	
	std::cout << "Account 3 (Savings): Withdraw 1000.00\n";
	std::cout << "Old Balance: " << acc3.GetBalance() << "\n";
	Withdraw(acc3,1000);
	std::cout << "New Balance: " << acc3.GetBalance() << "\n\n";
	
    return 0;
}
