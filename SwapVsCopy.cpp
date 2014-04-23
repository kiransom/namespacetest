#include "MultipleDefOfClass.h"
#include <iostream>
#include <vector>
#include <ctime>
#define N 10000

class LargeClass {
  int a[1000];
};

int mainSwapVsCopy() {
  std::vector<LargeClass> temp(N);
  for(std::size_t i=0;i < N; ++i) {
    temp.push_back(LargeClass());
  }

  {
    std::time_t startTime = clock();
    std::vector<LargeClass> temp2(N);
    temp2=temp;
    std::time_t endTime = clock();
    std::cout << "Total time copying: " << (endTime-startTime) << std::endl;
  }

  {
    std::time_t startTime = clock();
    std::vector<LargeClass> temp2(N);
    std::swap(temp, temp2); // swap pointers and is there much quicker
    std::time_t endTime = clock();
    std::cout << "Total time copying: " << (endTime-startTime) << std::endl;
  }


  return 0;
}