#include <iostream>
#include <string>
using namespace std;

bool HasDuplicates(double data[])
{
  int len = sizeof(data)/sizeof(data[0]);
  for (int i = 0; i < len; i += 1)
  {
    for (int j = i + 1; j < len; j += 1)
    {
      if (data[i] == data[j])
      {
        return true;
      }
    }
  }
  return false;
}

int LetterCount(const a, char b)
{
  int count;
  for (int i = 0; i < a.length(); i++)
  {
    if (a[i] == b)
    {
      count++;
    }
  }
  return count;
}

int main()
{
}