#include <iostream>
#include <vector>

std::vector<int> globalVector(100,2);

std::vector<int> getVector() {
  std::vector<int> rtrn_vctr(1000,-1);
  return rtrn_vctr;
}

int mainMoveSemantics() {
  int i=10;
  std::vector<int> testVector =  std::vector<int>(getVector()); // calls the move constructor of vector because getVector returns a rvalue - temporary object // step-and-see
  std::vector<int> testVector2 = std::vector<int>(globalVector); // call the copy constructor of vector
  std::vector<int> testVector3 = getVector(); // again move constructor
  return 0;
}