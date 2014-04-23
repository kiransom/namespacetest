#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template<typename T>
void printVector(vector<T>& v) {
  for_each(v.begin(), v.end(), [](int i) {cout << i << " "; });
}

int mainCountIf() {
  vector<int> tempVector(10,10);
  cout << std::count_if(tempVector.begin(), tempVector.end(), std::bind2nd(std::greater_equal<int>(), 2)) << "done" << endl;
  vector<int> tempVector2(0);
  cout << std::count_if(tempVector2.begin(), tempVector2.end(), std::bind2nd(std::greater_equal<int>(), 2)) << "done" << endl;

  return 0;
}