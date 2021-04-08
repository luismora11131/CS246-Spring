#include <iostream>
#include <string>
#include "Stack.h"

bool BackSpaceTextMatch(std::string s,std::string t)
{
	ds::Stack<char> a, b;
	int n = s.length(), m = t.length();

	for(int i = 0;i < n;i += 1)
	{
		if(s[i] == '#')
		{
			a.Pop();
		}
		else 
		{
			a.Push(s[i]);
		}
	}

	for(int i = 0;i < m;i += 1)
	{
		if(t[i] == '#')
		{
			b.Pop();
		}
		else 
		{
			b.Push(t[i]);
		}
	}

	while(!a.IsEmpty() && !b.IsEmpty())
	{
		if(a.Top() != b.Top())
		{
			return false;
		}
		a.Pop();
		b.Pop();
	}
	return (a.IsEmpty() && b.IsEmpty());
}

int main()
{
	std::string a, b;

	std::cout << "Enter text 1: ";
	std::getline(std::cin,a);

	std::cout << "Enter text 2: ";
	std::getline(std::cin,b);
	
	std::cout << std::boolalpha;
	std::cout << "BackSpaceTextMatch(" + a + "," + b + ") = " << BackSpaceTextMatch(a,b) << "\n";
	
	return 0;
}
