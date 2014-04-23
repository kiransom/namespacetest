#include <iostream>
#include <vector>
#include <set>
#include <list>

/* Comparison for STL containers based on two mathematical concepts
  1. every element in container has an order
  2. there is an order in which elements are represented in the container
  3. lexicographic ordering to compare containers

  Comparison operators: The equality and relational operators, 
  ==, !=, <, <=, >, >= are defined for containers holding the same datatype as elements. 
  Two containers are equal if all elements are equal and in the same order. The relational 
  operators work by comparing the containers element by element, and if one container has 
  fewer elements it is ‘less than’ the other. Or if a container’s element value is less than 
  the value of that element at the same index in the other container, then this contain is 
  ‘less than’ the other one. If the comparison test runs through both containers and they 
  are of equal s size with identical elements in the same order, they are equal 
  and the relational operator returns false for whatever it is testing for.
*/
int mainContainerComparison() {
  int a[5]={1,2,3,4,5};
  int b[5]={1,2,3,4,4};
  int c[5]={5,4,3,2,1};
  std::vector<int> aVector(a, a+5);
  std::vector<int> a1Vector(a, a+4);
  std::vector<int> bVector(b, b+5);
  std::set<int> aSet(a, a+5);
  std::set<int> bSet(b, b+5);
  std::set<int> cSet(c, c+5);
  // vectors are compared in lexicographic order
  std::cout << "test: aVector < bVector:" << (aVector < bVector)  << std::endl;
  std::cout << "test: a1Vector < aVector:" << (a1Vector < aVector)  << std::endl;
  std::cout << "test: a1Vector < bVector:" << (a1Vector < bVector)  << std::endl;
  std::cout << "test: aSet == cSet:" << (aSet ==  cSet) << std::endl;
  std::cout << "test: bSet > aSet:" << (bSet > aSet) << std::endl;
  return 0;
}