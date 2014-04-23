// comma operator 
#include <iostream>

int mainSimpleTestCommaOperator() {
  int x = 10;
  const bool iLoveC_plus_plus = ( ++x , true ); 
  std::cout << iLoveC_plus_plus << " " << x <<  std::endl;
  return 0;
}