#include <iostream>
#include <fstream>

void myPrint(std::ostream& o) {
  o << "test \n";
}

int mainOfStreamInheritsOstream() {
  std::ofstream tempFile("test.txt", std::ios::out);
  myPrint(tempFile);
  myPrint(std::cout);
  return 0;
}