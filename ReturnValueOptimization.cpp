// Example illustrates why it is a bad practice to pass objects be value. 
// Instead use Walter's brights idea of passing a pointer or reference to an object

#include <iostream>
using namespace std;

class Test {
public:
  int i;
  Test() : i(10) {cout << "original object constructed" << endl;}
  Test(Test& copyTest): i(copyTest.i) {cout << "Test Copied and value of i that is copied is " << i << endl; }
};

void f1(Test t) {
  cout << "In function i=" << t.i << endl; 
}

void f2(Test& t) {
  cout << "In function 2 i=" << t.i << endl;
}

struct C {
  C() {}
  C(const C&) { std::cout << "A copy was made.\n"; }
};
 
C f() {
  return C(); // returns an object - which is possible copied to the return variable
}

int mainRvo(void) {
  Test t;
  t.i=100;
  f1(t);
  t.i=200;
  f2(t); // This version does not create copies of objects - when objects are huge use this

  std::cout << "Hello World!\n";
  C obj = f(); // Interesting the VS2012 compiler does no copy
              // In theory, there can be 2 copies without the optimization
              // the return value is first copied to a tempory object
              // the temporary object is copied to lvalue obj
  return 0;
}