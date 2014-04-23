#include <iostream>
#include <string>
using namespace std;

struct Functor {
  const int _i;
  Functor(int i) : _i(i) {;}
  bool operator()(int j) const {return (_i==j);}
};

int mainFunctor(void) {
  cout << Functor(1)(100) << string("blah") + string(" blah") << endl;
  return 0;
}