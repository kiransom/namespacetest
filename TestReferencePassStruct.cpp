#include <iostream>

using namespace std;

struct XY{
  int x;
  int y;
  XY() : x(0), y(0) {}
};

ostream& operator<<(ostream& o, const XY& xy) {
  o << "(" << xy.x << " " << xy.y << ")";
  return o;
}

void simpleFun(int& x, int& y) {
  ++x;
  ++y;
}

int mainTestReferencePassStruct() {
  XY xy;
  cout << xy << endl;
  simpleFun(xy.x, xy.y);
  cout << xy << endl;
  return 0;
}