#include <iostream>
#include <string>
#include "Array.h"
#include "Node.h" //singly linked node in sn namespace
using namespace std;
using namespace ds;

//Problem 1
/* 
Acending
InsertionSort
1. [7,4,5,1,2,6,3] 
2. [4,7,5,1,2,6,3]
3. [4,5,7,1,2,6,3]
4. [1,4,5,7,2,6,3]
5. [1,2,4,5,7,6,3]
6. [1,2,4,5,6,7,3]
7. [1,2,3,4,5,6,7]
Decending
SelectionSort
1. [7,4,5,1,2,6,3]
2. [7,6,5,1,2,4,3]
3. [7,6,5,4,2,1,3]
4. [7,6,5,4,3,1,2]
5. [7,6,5,4,3,2,1]
*/
// Problem 2
template <typename T>
void BackAppend(Node<T>*& data,Node<T>& addon){
  int n = data.Length();
  int m = addon.Length();
  ds::Array<T> tmp = data;
  data.Resize(n+m);
  for(int i = 0;i < n; i++){
    data[i] = tmp[i];
  }
  for(int i=0;i < m;i++){
    data[n+i] = addon[i];
  }
}

//Problem 3
template <typename T>
int NthOccurrence(Array <T>& data, const T& value, int n){
  int compared=0;
  if(data.Length()==0||n==0){
    return -1;
  }
  for(int i=0;i<data.Length;i++){
    if(value==data[i]){
      compared++;
      if(compared==n){
        return i;
      }
    }
  }
  return -1;
}

//Problem 4
bool IsSet(Array<int>& data){
  if(data.Length()==0){
    return true;
  }
  else{
    return false;
  }
}
int main()
{
	return 0;
}
