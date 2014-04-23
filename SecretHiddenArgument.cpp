#include <iostream>
using namespace std;

class C {
private:
  int _i;
public:
  void foo(int i);
};

void C::foo(int i) {
  _i=i;
}


int mainSecretHiddenArgument(void) {
  C object;
  object.foo(10);
  return 0;
}