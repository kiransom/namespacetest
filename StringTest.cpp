#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void printString(string s) {
  cout << s << endl;
}

int mainStringTest(void) {
  stringstream asd;
  asd << string("temp") << "teadasdasd " << 2;
  cout << asd.str().c_str() << endl;
  printString("blah blah");
  return 0;
}