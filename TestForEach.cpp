#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mainTestForEach() {
  int myarray[]={5, 4, 3, 2, 1};
  vector<int> myvector(myarray,myarray+5);

  for_each(myvector.begin(), myvector.end(),  [](int i){cout << i << " ";});
  
  int countOfVector=0;
  for_each(myvector.begin(), myvector.end(), [&countOfVector](int i) {cout << i << " "; ++countOfVector;});
  cout << "Num elements " << countOfVector << endl;

  return 0;
}