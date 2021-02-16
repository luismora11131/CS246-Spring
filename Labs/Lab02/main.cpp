#include <iostream>
#include <string>
#include "Counter.h"
#include "NumberSystem.h"
#include "Shape.h"
using namespace std;

//Circle class

class Circle : public Shape
{
private:
  double radius;
  const double PI = 3.1415926;

public:
  Circle()
  {
    radius = 1;
  }
  Circle(const Circle &obj) {}
  Circle &operator=(const Circle &rhs) {}
  ~Circle() {}
  const double GetRadius()
  {
    return radius;
  }
  double GetPI()
  {
    return PI;
  }
  double GetDiameter()
  {
    return PI * (radius * 2);
  }
  void SetRadius(double a)
  {
    if (a > 0)
    {
      radius = a;
    }
  }
  const double Area()
  {
    return (PI * (radius * radius));
  }
  const double Perimeter()
  {
    return (2 * PI * radius);
  }
};

//LowerBoundedCorner class
class LowerBoundedCounter : public Counter
{
private:
  int counter;
  int minimum;

public:
  LowerBoundedCounter()
  {
    counter = 0;
    minimum = 0;
  }
  //copy constructor
  LowerBoundedCounter(const LowerBoundedCounter &p)
  {
    this->counter = p.counter;
    this->minimum = p.minimum;
  }
  //destructor
  ~LowerBoundedCounter(){};
  //GetCounter()
  int const GetCounter()
  {
    return counter;
  }
  //GetMinimum
  int const GetMinimum()
  {
    return minimum;
  }
  //SetCounter
  void SetCounter(int a)
  {
    if (a >= minimum)
    {
      a = counter;
    }
    else
    {
      return;
    }
  }
  //SetMinimum
  void SetMinimum(int b)
  {
    if (b < +counter)
    {
      b = minimum;
    }
    else
    {
      return;
    }
  }
  //Increment
  bool Increment()
  {
    counter += 1;
    return true;
  }
  //Decrement
  bool Decrement()
  {
    if (counter > minimum)
    {
      counter -= counter;
      return true;
    }
    else
    {
      return false;
    }
  }
};

//VectorCalculator class

class VectorCalculator : public NumberSystem
{
private:
  double firstOperant[2];
  double secondOperant[2];

public:
  VectorCalculator()
  {
    firstOperant[0] = 0;
    firstOperant[1] = 0;
    secondOperant[0] = 0;
    secondOperant[1] = 0;
  }
  VectorCalculator(const VectorCalculator &obj) {}
  VectorCalculator &operator=(const VectorCalculator &rhs) {}
  ~VectorCalculator() {}
  const double GetICoordinate(bool a)
  {
    if (a == true)
    {
      return firstOperant[0];
    }
    else
    {
      return secondOperant[0];
    }
  }
  const double GetJCoordinate(bool a)
  {
    if (a == true)
    {
      return firstOperant[1];
    }
    else
    {
      return secondOperant[1];
    }
  }
  void SetICoordinate(bool a, double b)
  {
    if (a == true)
    {
      firstOperant[0] = b;
    }
    else
    {
      secondOperant[0] = b;
    }
  }
  void SetJCoordinate(bool a, double b)
  {
    if (a == true)
    {
      firstOperant[1] = b;
    }
    else
    {
      secondOperant[1] = b;
    }
  }
  void Addition()
  {
    firstOperant[0] = firstOperant[0] + secondOperant[0];
    firstOperant[1] = firstOperant[1] + secondOperant[1];
  }
  void Subtraction()
  {
    firstOperant[0] = secondOperant[0] - firstOperant[0];
    firstOperant[1] = secondOperant[1] - firstOperant[1];
  }
};

int main()
{
}