#include <iostream>
#include <string>
#include "Stack.h"

bool ValidParenthesesEnclosure(std::string s)
{
	ds::Stack<char> a;
	int n = s.length();

	for(int i = 0;i < n;i += 1)
	{
		if(s[i] == '(')
		{
			a.Push('a');
		}
		else if(s[i] == ')')
		{
			if(a.IsEmpty())
			{
				return false;
			}
			a.Pop();
		}
	}
	return (a.IsEmpty());
}

int main()
{
	std::string a;

	std::cout << "Enter string: ";
	std::getline(std::cin,a);
	
	std::cout << std::boolalpha;
	std::cout << "ValidParenthesesEnclosure(\"" + a + "\") = " << ValidParenthesesEnclosure(a) << "\n";
	
	return 0;
}
