#include <iostream>

using namespace std;

/* effect of using shadowed defintion 
   within scope of the shadowed declaration, the shadowed declaration takes over
   but when it comes outside the scope, the previous declaration comes into 
   effect
*/
int mainScopeOfVariable() {
  int i=10;
  cout << "i=" << i << endl;
  cout << "For loop: " << endl;
  for(int i=0; i<5; i++) { 
    cout << "i= " << i << endl;
  }
  cout << "outside for loop " << endl;
  cout << "i = " << i << endl;
  return 0;
}