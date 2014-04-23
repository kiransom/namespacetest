#include <iostream>

using namespace std;


struct IsAlwaysTrue {
  bool operator()(const int i) {return true;}
};

template <class T>
bool testPredicate(int i, T t = IsAlwaysTrue()) {
  return t(10);
}

int mainTemplateFunctionDefaultArg() {
  cout << testPredicate(10, IsAlwaysTrue()) << endl;
  // cout << testPredicate(20) << endl; // error - C++ cannot deduce the type
  return 0;
}