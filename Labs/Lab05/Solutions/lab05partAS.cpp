#include <iostream>
#include <string>
#include "Stack.h"
#include "Node.h"

bool ValidEnclosure(std::string str)
{
	ds::Stack<char> a;
	int n = str.length();

	for(int i = 0;i < n;i += 1)
	{
		if(str[i] == '(')
		{
			a.Push('a');
		}
		else if(str[i] == '{')
		{
			a.Push('b');
		}
		else if(str[i] == ')')
		{
			if(a.IsEmpty() || a.Top() == 'b') 
			{
				return false;
			}
			a.Pop();
		}
		else if(str[i] == '}')
		{
			if(a.IsEmpty() || a.Top() == 'a')
			{
				return false;
			}
			a.Pop();
		}
		else 
		{
			return false;
		}
	}
	return a.IsEmpty();
}

int main()
{
	std::string a;

	std::cout << "Enter a string: ";
	std::getline(std::cin,a);

	std::cout << std::boolalpha;
	std::cout << "ValidEnclosure(\"" + a + "\") = " << ValidEnclosure(a) << "\n"; 
	return 0;
}
