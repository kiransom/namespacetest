#include <iostream>
#include <cmath>

using namespace std;

int mainLogTest(void) {
  cout << std::log10(1.0) << " " << log10(10.0) << " " << log10(0.0) << " " << (log10(0.0) >  100) << endl;  
  return 0;
}