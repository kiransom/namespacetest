// equal_range example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int mainEqualRange () {
  int myints[] = {0,0,0,0,1,1,1,1,2,2,2,2};
  vector<int> v(myints,myints+12);          
  vector<int> v2;
  v2.assign(v.begin()+1, v.end()-1);
  for_each(v2.begin(), v2.end(), [](int n) {cout << n << " ";});
  pair<vector<int>::iterator,vector<int>::iterator> bounds;

  // using default comparison:
  bounds=equal_range (v.begin(), v.end(), 3);           
   int first_loc = bounds.first - v.begin();
   vector<int>::difference_type a = bounds.first - v.begin();
   vector<int>::difference_type b = bounds.second - v.begin();
   cout << "positions are at " << a << " " << b << endl;

  return 0;
}