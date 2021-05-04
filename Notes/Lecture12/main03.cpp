#include <iostream>
#include <string>
#include <cctype>
#include "Node.h"
#include "Repository.h"

/*
The following program is a decision tree algoirthm.
It will predict a number you are thinking about 
by asking a series of yes or no questions. It is 
implemented by using a binary tree data structure
*/

//Linked Tree Leaf Function
/*Determines if a subtree is a leaf*/
bool IsLeaf(ds::tn::Node<std::string>* rt)
{
	if(rt == NULL)
	{
		return false;
	}
	return (rt->left == NULL && rt->right == NULL);
}

//Linked Tree Population
void PopulateDecisionTree(ds::tn::Node<std::string>*& rt)
{
	rt = ds::tn::Create(std::string("Is your number even?"));
	rt->left = ds::tn::Create(std::string("Is your number greater than 5?"));
	rt->right= ds::tn::Create(std::string("Is your number greater than 6?"));
	rt->left->left = ds::tn::Create(std::string("Is your number prime?"));
	rt->left->right = ds::tn::Create(std::string("Is your number prime?"));
	rt->right->left = ds::tn::Create(std::string("Does your number have an odd prime factor?"));
	rt->right->right = ds::tn::Create(std::string("Does your number have an odd prime factor?"));
	rt->left->left->left = ds::tn::Create(std::string("Your number is 1"));
	rt->left->left->right = ds::tn::Create(std::string("Is one more than your number a perfect square?"));
	rt->left->right->left = ds::tn::Create(std::string("Your number is 9"));
	rt->left->right->right = ds::tn::Create(std::string("Your number is 7")); 
	rt->right->left->left = ds::tn::Create(std::string("Is your number prime?"));
	rt->right->left->right = ds::tn::Create(std::string("Your number is 6"));
	rt->right->right->left = ds::tn::Create(std::string("Your number is 8")); 
	rt->right->right->right = ds::tn::Create(std::string("Your number is 10"));
	rt->left->left->right->left = ds::tn::Create(std::string("Your number is 5"));
	rt->left->left->right->right = ds::tn::Create(std::string("Your number is 3")); 
	rt->right->left->left->left = ds::tn::Create(std::string("Your number is 4"));
	rt->right->left->left->right = ds::tn::Create(std::string("Your number is 2")); 
}

//Linked Tree PredictNumber Program
void PredictNumber()
{
	char answer;
	ds::tn::Node<std::string>* questions;

	PopulateDecisionTree(questions);
	ds::tn::Node<std::string>* cn = questions;

	std::cout << "Number Prediction Game\n";
	std::cout << "Think of a number between 1 and 10 inclusively and write it down somewhere\n";
	std::cout << "By asking at most 5 yes or no questions, I will determine your number\n";
	std::cout << "Enter y for yes and n for no for each question\n";
	std::cout << "Ready to start!\n\n";

	for(int i = 1;i <= 5;i += 1)
	{
		if(!IsLeaf(cn))
		{
			std::cout << "Question " << i << ": " << cn->data << "\n";
			
			while(true)
			{
				std::cin >> answer;
	
				if(tolower(answer) == 'n' || tolower(answer) == 'y')
				{
					break;
				}
				else 
				{
					std::cout << "I did not understand your answer. Please reenter it: ";
				}
			}

			cn = (tolower(answer) == 'n')?(cn->left):(cn->right);
		}
		else
		{
			std::cout << cn->data << "\n";
			break;
		}
	}

	ds::tn::Clear(questions);
}

int main()
{
	PredictNumber(); 
	return 0;
}
