#include <iostream>
using namespace std;


class X; // forward declaration
class Y {
public:
  /*void foo(X &x) {cout << x._secret << endl;} // note this will be in error because at this point the compiler does not
                                              // that X containts a member state _secret
                                              // So we must push the definition outside, after X is declared
  */
  void foo(X &);
};


class X {
public:
  X(int secret) : _secret(secret) {;}
private:
  int _secret;
  friend void Y::foo(X &x);
};

void Y::foo(X &x) {
  cout << x._secret << endl;
}


int mainFriendClassAndFunctions(void ) {
  X x(100);
  Y y;
  y.foo(x);
  return 0;
}
