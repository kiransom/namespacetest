#include <iostream>

using namespace std;

int mainPostIncrement() {
  int a=10;
  cout << 10 + a++ + 20; // there postfix just returns the old value of a. increment can happen before, after, who cares
  return 0;
}