#include <iostream>

int mainTestBitwiseOperator() {
  int a=2;
  int b=0xF0;
  std::cout <<  (a & 2) << " " << (b & 256) << " " << (b & 128) << std::endl;
  return 0;
}