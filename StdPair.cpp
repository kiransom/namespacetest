#include <iostream>

using namespace std;

int mainStdPair(void) {
  pair<int,int> temp(10,10);
  cout << temp.first << " " << temp.second << endl;
  return 0;
}