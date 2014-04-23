#include <iostream>
using namespace std;

struct FunctionalIncrement {
  int operator()(int a) {return (a+1);}
} F;

int mainFunctional(void) {
  cout << F(10) << " " << F(20) << endl << " " << sizeof(FunctionalIncrement) << endl;
  return 1;
}