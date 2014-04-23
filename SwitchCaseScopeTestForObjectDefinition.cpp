/* Though C++ allow you to define objects/built-in-types on the fly anywhere
 in the body, it probably allocates memory in the start of the block, so
 it prevents the object definition (point of call of the constructor) within
 any conditional flow. See the example, where the object definition within the
 conditional switch case is caught by the compiler
*/
#include<iostream>

using namespace std;

int mainSwitchCaseScopeControlTest() {
  int i=1;
  switch (i) {
  case 0: 
    // int j=10;  // This will cases error because j  is defined within a conditional pass, but appears to be visible to other cases
    break;
  case 1: {
            int jj=10;  // This is valid, as the scope is limited to this case
            break;
          }
  default: cout << "Error" << endl;
  }
  return 0;
}