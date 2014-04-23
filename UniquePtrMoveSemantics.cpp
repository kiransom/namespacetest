#include <iostream>
#include <vector>
#include <memory>

class C {
public:
  std::vector<int> v;
  C(): v(std::vector<int>(5)) {}
  void print() {
    for(auto i : v) { 
      std::cout << i << ",";
    }
    std::cout << std::endl;
  }
};

int mainUniquePtrMoveSemantics() {
  std::unique_ptr<C> p1 = std::unique_ptr<C>(new C());
  p1->print();
  //std::unique_ptr<C> p2 = p1; // compile error because unique_ptr is not copyable
  std::unique_ptr<C> p2(std::move(p1)); // p2 owns the object now
  p2->print();
  if(p1==NULL) {
    std::cout << "p1 is NULL" << std::endl;
  }
  return 0;
}