#ifndef VECTORCALCULATOR_H
#define VECTORCALCULATOR_H

#include "NumberSystem.h"

class VectorCalculator : public NumberSystem
{
	private:
	double firstOperand[2];
	double secondOperand[2];

	public:	
	VectorCalculator()
	{
		firstOperand[0] = 0;
		firstOperand[1] = 0;
		secondOperand[0] = 0;
		secondOperand[1] = 0;
	}
	
	VectorCalculator(const VectorCalculator& obj)
	{
		firstOperand[0] = obj.firstOperand[0];
		firstOperand[1] = obj.firstOperand[1];
		secondOperand[0] = obj.secondOperand[0];
		secondOperand[1] = obj.secondOperand[1];
	}

	VectorCalculator& operator=(const VectorCalculator& rhs)
	{
		if(this != &rhs)
		{
			firstOperand[0] = rhs.firstOperand[0];
			firstOperand[1] = rhs.firstOperand[1];
			secondOperand[0] = rhs.secondOperand[0];
			secondOperand[1] = rhs.secondOperand[1];
		}
		return *this;
	}

	~VectorCalculator() {}

	double GetICoordinate(bool op) const 
	{
		return ((op)(firstOperand[0]):(secondOperand[0]));
	}

	double GetJCoordinate(bool op) const 
	{
		return ((op)(firstOperand[1]):(secondOperand[1]));
	}

	void SetICoordinate(bool op,double value)
	{
		if(op)
		{
			firstOperand[0] = value;
		}
		else
		{
			secondOperand[0] = value;
		}
	}

	void SetJCoordinate(bool op,double value)
	{
		if(op)
		{
			firstOperand[1] = value;
		}
		else
		{
			secondOperand[1] = value;
		}
	}

	virtual void Addition()
	{
		firstOperand[0] = firstOperand[0] + secondOperand[0];
		firstOperand[1] = firstOperand[1] + secondOperand[1];
	}

	virtual void Subtraction() 
	{
		firstOperand[0] = firstOperand[0] - secondOperand[0];
		firstOperand[1] = firstOperand[1] - secondOperand[1];
	}
};

#endif
