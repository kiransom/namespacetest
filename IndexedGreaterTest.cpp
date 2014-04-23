#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

#define STRINGIFY(X) #X
#define PRINTEXPR(X) cout << STRINGIFY(X) << " = " << X << endl

template<class T>
class IndexedLess
{
 protected:
  const vector<T>& _t;
 public:
  IndexedLess(const vector<T>& t) : _t(t) {}
  bool operator()(const int a, const int b) const
    { return _t[a] < _t[b]; }
};

template<class T>
class IndexedGreater
{
 protected:
  const vector<T>& _t;
 public:
  IndexedGreater(const vector<T>& t) : _t(t) {;}
  bool operator()(const int a, const int b) const
    { return _t[a] > _t[b]; }
};


class IntSequence {
private:
  int _value;
public:
  IntSequence(int value) : _value(value) {}
  int operator()(){ return _value++; }
};


template <class T>
void printVector(const vector<T>& vectorToPrint) {
  cout << "{" ;
  for(vector<T>::const_iterator it=vectorToPrint.begin(); it != vectorToPrint.end(); ++it) {
    cout << *it << ", ";
  }
  cout << "}" << endl;
}




int testIndexedGreater() {
  double dd[4]={220.0,100.0,2.0,5.0};
  //vector<double> a(dd, dd+4);
  vector<double> a;
  /*
  a.push_back(2.0);
  a.push_back(1.0);
  a.push_back(4.0);
  a.push_back(1.5);
  a.push_back(0.1); */
  cout << "given vector ";
  printVector(a);
  vector<double>::iterator min_location = min_element(a.begin(), a.end());
  cout << ((min_location==a.end())? (std::numeric_limits<double>::max()) : *min_location)  <<  endl; 

  /*vector<int> b;
  generate_n(inserter(b, b.end()), static_cast<unsigned int>(a.size()), IntSequence(0));
  printVector(b);
  sort(b.begin(), b.end(), IndexedGreater<double>(a)); 
  cout << "IndexedGreater " ;
  printVector(b);

  vector<int> c;
  generate_n(inserter(c, c.end()), static_cast<unsigned int>(a.size()), IntSequence(0));
  printVector(c);
  sort(c.begin(), c.end(), IndexedLess<double>(a)); 
  cout << "IndexedLess " ;
  printVector(c); */
  return 0;
}