#include <iostream>
using namespace std;


void f2(int& x, int& y) {
  cout << x++ << ", " << y++ << endl;
}

void f1(int& x, int& y) {
  cout << ++x << ", " << ++y << endl; 
  f2(x,y);
  cout << x << ", " << y << endl;
}


int mainPassingReferencesExample(void) {
  int x=10;
  int y=20;
  f1(x,y);
  return 0;
}