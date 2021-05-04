#include <iostream>
#include <string>
#include "Node.h"
#include "Repository.h"

int main()
{
	ds::tn::Node<int> * r = ds::tn::Create(1);
	r->left = ds::tn::Create(2);
	r->right = ds::tn::Create(3);
	r->left->left = ds::tn::Create(4);
	r->right->left = ds::tn::Create(5);
	r->left->right = ds::tn::Create(6);
	r->right->right = ds::tn::Create(7);

	std::cout << "Size(r) = " << Size(r) << "\nInfix of r:\n";
	InfixPrint(r);
	std::cout << "\nPrefix of r:\n";
	PrefixPrint(r);
	std::cout << "\nPostfix of r:\n";
	PostfixPrint(r);
	std::cout << "\n";
 
	return 0;
}
