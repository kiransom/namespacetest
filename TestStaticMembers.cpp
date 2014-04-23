#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

#define PRINTEXPR(X) cout << #X << " = " << X << endl

class TestStatic {
public:
  static void displayX();
protected:
    static int x;
    // static int y=0; // Error  you cannot define an in-class member, unless it is a constant
};

int TestStatic::x=0;  // This is actual definition - where memory is allocated

// this is the actual definition where memory is allocated
void TestStatic::displayX() {
  static int i=0; // Another static varible within a function
  cout << ++i << " " << ++(TestStatic::x) << endl;
}

int mainTestStatic() {
  TestStatic::displayX();
  TestStatic::displayX();
  TestStatic::displayX();
  TestStatic::displayX();
  TestStatic::displayX();
  TestStatic::displayX();
  return 0;
}