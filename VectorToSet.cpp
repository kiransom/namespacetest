#include <iostream>
#include <vector>
#include <set>

using namespace std;

template <class T>
void printCollection(T collection) {
  for(T::iterator it=collection.begin(); it!=collection.end(); ++it) {
    cout << *it << ", ";
  }
  cout << endl;
}

int mainVectorToSet(void) {
  vector<int> v;
  v.reserve(5);
  for(int i=0;i<5;i++) {
    v.push_back(i);
  }
  printCollection(v);
  set<int> s(v.begin(), v.end());
  printCollection(s);
  printCollection(set<int>(v.begin(), v.end()));
  return 0;
}