// explore auto decltype and std::function wrapper

#include <iostream>
#include <functional>

using namespace std;

int toInt(double d) {
  return static_cast<int>(d);
}

class A {
  int toInt(double d) {
    return static_cast<int>(d);
  }
};

int mainTestFunctionWrapper() {

  auto fp = toInt;
  auto fp2 = &toInt;

  // note the subtle difference in defining, 
  // we need & to indicate that it is a pointer(reference) to the function toInt
  decltype(&toInt) fp3 = toInt; 

  // note the subtle difference, 
  // we should not have a & here, because we are specifying the type of the 
  // function toInt to std::function wrapper
  std::function<decltype(toInt)> func1 = toInt;

  cout << fp(100.2) << "\n"
       << fp2(9.9) <<  "\n"
       << fp3(1.1) << "\n"
       << func1(200.1) << "\n***************\n"
       << endl;

  
  
  auto lambdaHolder_toInt = [](double d){return static_cast<int>(d);};

  int sum = 0;
  auto lambdaHolder_sum = [&sum](int i) {sum+=i;};
  lambdaHolder_sum(100);
  lambdaHolder_sum(200);
  cout << sum << endl;
  std::function<void(int)> lambdaHolder_sum2 = lambdaHolder_sum; 
  lambdaHolder_sum2(100);
  lambdaHolder_sum2(300);
  cout << sum << endl;

  return 0;

}