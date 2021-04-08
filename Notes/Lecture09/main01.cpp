#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"

bool IsPalindrome(std::string file)
{
	ds::Stack<char> s;
	char ch;
	std::ifstream in(file.data());

	if(!in.is_open())
	{	
		std::cout << "file cannot open.\n";
		return false;
	}

	while(in >> ch)
	{
		s.Push(ch);
	}
	in.close();
	in.open(file.data());

	while(in >> ch)
	{
		if(!s.IsEmpty())
		{
			if(s.Top() != ch)
			{
				return false;
			}
			s.Pop();
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	std::string name;

	std::cout << "Enter filename: ";
	std::getline(std::cin,name);
	
	std::cout << std::boolalpha;
	std::cout << "IsPalindrome(" + name + ") = " << IsPalindrome(name) << "\n";
	
	return 0;
}
