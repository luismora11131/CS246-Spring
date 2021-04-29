#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <iostream>
#include <string>
#include "Node.h"

//Tree Traversals

template<typename T>
void InfixPrint(ds::tn::Node<T>* root)
{
	if(root != NULL)
	{
		InfixPrint(root->left);
		std::cout << root->data << " ";
		InfixPrint(root->right);
	}
}

template<typename T>
void PrefixPrint(ds::tn::Node<T>* root)
{
	if(root != NULL)
	{
		std::cout << root->data << " ";
		PrefixPrint(root->left);
		PrefixPrint(root->right);
	}
}

template<typename T>
void PostfixPrint(ds::tn::Node<T>* root)
{
	if(root != NULL)
	{
		PostfixPrint(root->left);
		PostfixPrint(root->right);
		std::cout << root->data << " ";
	}
}

template<typename T>
int Size(ds::tn::Node<T>* root)
{
	if(root == NULL)
	{
		return 0;
	}
	else 
	{
		return 1 + Size(root->left) + Size(root->right);
	}
}

#endif
