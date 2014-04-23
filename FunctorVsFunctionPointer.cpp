// FunctorVsFunctionPointer shows the template definition can work with either functor or function pointer seamlessly
// The code emphasizes that functions and functors can be used identically
// Author: skyrus@gmail.com

#include <iostream>
#include <algorithm>

using namespace std;


// The functor Functor wraps a function pointer
struct Functor {
  bool (*_localFP)(int);
  Functor(bool (*fp)(int)): _localFP(fp) {;}
  bool operator()(const int i) const {return _localFP(i);}
};

bool isOne(int i) {
  return (i==1);
}

template <class T>
void evaluateExpression(int i, T expression) {
  cout << expression(i) << endl;
}

int mainFunctorVsFunctionPointer(void) {
  evaluateExpression(1, Functor(&isOne));
  evaluateExpression(2, Functor(&isOne));

  evaluateExpression(1, &isOne);
  evaluateExpression(3, &isOne);
  return 1;
}
