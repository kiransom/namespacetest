#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int mainTestRemoveIf() {
  int myints[] = {1,2,3,4,5,6,7,8,9}; 
  vector<int> myvector(myints, myints+9);
  vector<int>::iterator itEnd = std::remove_if(myvector.begin(), myvector.end(), 
    std::bind2nd(std::greater<int>(),3));
  for(vector<int>::iterator it = myvector.begin(); it != itEnd; ++it) {
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}