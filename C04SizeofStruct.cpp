//: C04: SizeOfStruct
// Sizes of structs and classes
// EMPTY CLASS HAS NON-ZERO SIZE

#include <iostream>

using namespace std;

struct A {
  int i[100];
  int j[200];
};

struct B {
  void f();
};

void B::f() {}

class AClass {
public:
  int i[100];
  int j[200];
  void f();
};

void AClass::f() { }

class BClass {
public:
  void f();
};

void BClass::f() { }

class CClass {
};

int mainSizeOfStruct() {
  cout << "size of struct A = " << sizeof(A) << " bytes" << endl;
  cout << "size of struct B = " << sizeof(B) << " bytes" << endl;
  cout << "size of class AClass = " << sizeof(AClass) << " bytes" << endl;
  cout << "size of class BClass = " << sizeof(BClass) << " bytes" << endl;
  cout << "size of class CClass = " << sizeof(CClass) << " bytes" << endl;
  return 0;
}