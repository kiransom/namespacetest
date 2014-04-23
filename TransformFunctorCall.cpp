#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

// Establishes that the functor - function object is created only once and its operator() is called several times
// this is obvious, but test was done just for sanity
using namespace std;

struct FunctorTest {
  int _i;
  FunctorTest(const int i): _i(i) {cout << "Functor created with i=" << i << endl;}
  int operator()(const int j) {return _i+j;}
};

int mainTransformFunctorTest() {
  int myarray[5]={0, 1, 2, 3, 4};
  vector<int> myvector(myarray, myarray+5);
  vector<int> myvectorPlus10(5, -1);
  transform(myvector.begin(), myvector.end(), myvectorPlus10.begin(), FunctorTest(10));
  for_each(myvectorPlus10.begin(), myvectorPlus10.end(), [](int i){cout << i << ", ";});
  return 0;
}