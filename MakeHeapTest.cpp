// range heap example
#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector

template<typename T>
void printStlVector(std::vector<T>& v) {
  for(auto vIt = v.begin(); vIt != v.end(); ++vIt) {
    std::cout << *vIt << " ";
  }
  std::cout << "\n";
}

/*
http://www.sgi.com/tech/stl/make_heap.html
A heap is a particular way of ordering 
the elements in a range of Random Access Iterators [f, l). 
The reason heaps are useful (especially for sorting, or as priority queues) 
is that they satisfy two important properties:

First, *f is the largest element in the heap. 
Second, it is possible to add an element to a heap (using push_heap), or to remove *f, 
in logarithmic time. 

Internally, a heap is simply a tree represented as a sequential range. 
The tree is constructed so that that each node is less than or equal to its parent node. 

*/

int mainMakeHeapTest() {
  int myints[] = {10,20,30,5,15};
  std::vector<int> v(myints,myints+5);

  std::make_heap (v.begin(),v.end());
  printStlVector(v); // 30 20 10 5 15 - note not fully sorted
  // heap has the property that the first element is the largest

  std::pop_heap (v.begin(),v.end()); 
  printStlVector(v); // 20 15 10 5 30
  v.pop_back();
  printStlVector(v); // 20 15 10 5

  v.push_back(99); 
  printStlVector(v); // 20 15 10 5 99
  std::push_heap (v.begin(),v.end());
  printStlVector(v); // 99 20 10 5 15

  std::sort_heap (v.begin(),v.end());
  printStlVector(v); // 5 10 15 20 99

  return 0;
}