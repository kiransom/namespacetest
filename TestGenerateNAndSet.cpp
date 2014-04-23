#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <functional>

using namespace std;
int current = 0;
int UniqueNumber () { return ++current; }

int mainTestGenerateNAndSet() {
  /* ERROR: doesnt compile
  set<int> test; 
  */
  vector<int> test(10);
  generate_n(test.begin(), 10, UniqueNumber);
  std::for_each(test.begin(), test.end(), [](int n){cout << n << " ";});
  return 0;
}