#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

template <class T>
void printVector(const vector<T>& vectorToPrint) {
  cout << "{" ;
  for(vector<T>::const_iterator it=vectorToPrint.begin(); it != vectorToPrint.end(); ++it) {
    cout << *it << ", ";
  }
  cout << "}" << endl;
}

int incrementByOne(int x) {return x+1;}

/////// TESTING
int callFunctionPointer(int (*fp)(int x)) {
  assert( (*fp)(100) == fp(100) ); // Note that de-referencing is not required for function pointers
  return (*fp)(100);
}

struct IncrementByX {
  const int _x;
  IncrementByX(const int x) : _x(x) {;}
  int operator()(const int y) {return _x + y;}
};

int mainFunctorTransform(void) {
  vector<int> first;
  vector<int> second;
  vector<int> third;
  
  for(int i=0;i<6;++i) {
    first.push_back(i);
  }
  second.resize(first.size());
  third.resize(first.size());

  transform(first.begin(), first.end(), second.begin(), incrementByOne);
  transform(first.begin(), first.end(), third.begin(), IncrementByX(100));

  printVector(first);
  printVector(second);
  printVector(third);

  cout << "Call function pointer - " << callFunctionPointer(&incrementByOne) << endl;
  return 1;

}
