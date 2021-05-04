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

//Array Binary Tree Initialization
/*Assigns each element NULL*/
void Init(std::string* rt[])
{
	for(int i = 0;i < 31;i += 1)
	{
		rt[i] = NULL;
	}
}

//Array Tree Leaf Function
/*Determines if a subtree is a leaf*/
bool IsLeaf(std::string* rt[],int n)
{
	if(n >= 0 && n < 31 && rt[n] != NULL) 
	{
		//handle lowest depth
		if(n >= 15)
		{
			return true;
		}
		else
		{
			return (rt[LEFT(n)] == NULL && rt[RIGHT(n)] == NULL);
		}
	}
	return false;
}

//Array Tree Population
void PopulateDecisionTree(std::string* rt[])
{
	rt[0] = new std::string("Is your number even?"); //root
	rt[1] = new std::string("Is your number greater than 5?"); //LEFT(root)
	rt[2] = new std::string("Is your number greater than 6?"); //RIGH(root)
	rt[3] = new std::string("Is your number prime?"); //LEFT(LEFT(root))
	rt[4] = new std::string("Is your number prime?"); //RIGHT(LEFT(root))
	rt[5] = new std::string("Does your number have an odd prime factor?"); //LEFT(RIGHT(root))
	rt[6] = new std::string("Does your number have an odd prime factor?"); //RIGHT(RIGHT(root))
	rt[7] = new std::string("Your number is 1"); //LEFT(LEFT(LEFT(root)))
	rt[8] = new std::string("Is one more than your number a perfect square?"); //RIGHT(LEFT(LEFT(root)))
	rt[9] = new std::string("Your number is 9"); //LEFT(RIGHT(LEFT(root)))
	rt[10] = new std::string("Your number is 7"); //RIGHT(RIGHT(LEFT(root)))
	rt[11] = new std::string("Is your number prime?"); //LEFT(LEFT(RIGHT(root)))
	rt[12] = new std::string("Your number is 6"); //RIGHT(LEFT(RIGHT(root)))
	rt[13] = new std::string("Your number is 8"); //LEFT(RIGHT(RIGHT(root)))
	rt[14] = new std::string("Your number is 10"); //RIGHT(RIGHT(RIGHT(root)))
	rt[17] = new std::string("Your number is 5"); //LEFT(RIGHT(LEFT(LEFT(root))))
	rt[18] = new std::string("Your number is 3"); //RIGHT(RIGHT(LEFT(LEFT(root))))
	rt[23] = new std::string("Your number is 4"); //LEFT(LEFT(LEFT(RIGHT(root))))
	rt[24] = new std::string("Your number is 2"); //RIGHT(LEFT(LEFT(RIGHT(root))))
}
		
//Array Tree Destruction
/*deallocates nodes*/
void Clear(std::string* rt[])
{
	for(int i = 0;i < 31;i += 1)
	{
		if(rt[i] != NULL) 
		{
			delete rt[i];
			rt[i] = NULL;
		}
	}
}

//Array Tree PredictNumber Program
void PredictNumber()
{
	char answer;
	std::string* questions[31];
	
	Init(questions);
	PopulateDecisionTree(questions);

	std::cout << "Number Prediction Game\n";
	std::cout << "Think of a number between 1 and 10 inclusively and write it down somewhere\n";
	std::cout << "By asking at most 5 yes or no questions, I will determine your number\n";
	std::cout << "Enter y for yes and n for no for each question\n";
	std::cout << "Ready to start!\n\n";

	for(int i = 1, cn = 0;i <= 5;i += 1)
	{
		if(!IsLeaf(questions,cn))
		{
			std::cout << "Question " << i << ": " << *(questions[cn]) << "\n";
			
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

			cn = (tolower(answer) == 'n')?(LEFT(cn)):(RIGHT(cn));
		}
		else
		{
			std::cout << *(questions[cn]) << "\n";
			break;
		}
	}

	Clear(questions);
}

int main()
{
	PredictNumber(); 
	return 0;
}
