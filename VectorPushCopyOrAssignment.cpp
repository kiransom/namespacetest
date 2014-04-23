#include <iostream>
#include <algorithm>
#include <vector>

/* Why immutable objects cannot be populated into STL containers */

class A {
public:
  int i;
  //const int i; 
                /* This cannot be const because the assignment operator= cannot 
                   be defined correctly see ref1 */
  A(int i_arg): i(i_arg) {std::cout << "A::A() called i=" << i << " " << std::endl;}
  A(const A& aCopy): i(aCopy.i) {std::cout << "A::A(const A& aCopy) called i=" << i << " "  << std::endl;}
  A& operator=(const A& rhs)  {
    std::cout << "A::operator= called i=" << i << " other_i=" << rhs.i << " "  << std::endl; 
    i=rhs.i;  /* ref1 */
    return *this;}
};

int mainVectorPushCopyOrAssignment() {
  std::cout << "A a1;" << std::endl;
  A a1(1);
  std::cout << "A a2=a1;" << std::endl;
  A a2=a1;
  std::cout << "A a3;" << std::endl;
  A a3(3);
  std::cout << "a3=a1;" << std::endl;
  a3=a1;
  std::cout << "std::vector<A> aVector;" << std::endl;   
  std::vector<A> aVector;
  std::cout << "aVector.push_back(A());" << std::endl;
  aVector.push_back(A(100));
  aVector.push_back(A(200));
  aVector.push_back(A(300));
  aVector.push_back(A(400));
  std::cout << "aVector.erase(aVector.begin()); " << std::endl;
  aVector.erase(aVector.begin());
  std::for_each(aVector.begin(), aVector.end(), [](A a){std::cout << a.i << "," << std::endl;});
  return 0;
}
