#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
using namespace std;

template< class C1, class C2 > 
vector<pair<typename C1::value_type,typename C2::value_type> > cartesianProduct(const C1& c1, const C2& c2) {
  vector< pair<typename C1::value_type,typename C2::value_type> > cartesianProductVector;
  for(typename C2::const_iterator it2=c2.begin(); it2 != c2.end(); ++it2) {
    for(typename C1::const_iterator it1=c1.begin(); it1 != c1.end(); ++it1) {
      pair<typename C1::value_type, typename C2::value_type> currPair(*it1, *it2);
      cartesianProductVector.push_back(currPair);
    }
  }
  return cartesianProductVector;
}



template<typename U1, typename U2>
void printCart(vector<pair<U1, U2 > >& cart) {
  for_each(cart.begin(), cart.end(), 
    [](pair<U1,U2>& p) { cout << "(" << p.first << "," << p.second << ") ";  } 
    );
  cout << std::endl;
}


// template template

template< template<class, class> class V, class T>
void printContainer(V<T, std::allocator<T> >& v) {
  for(typename V<T, std::allocator<T> >::const_iterator it = v.begin(); it!=v.end() ; ++it) {
    const T i = *it;
    cout << i << " ";
  }
  cout << endl;
}

int mainGeneralizedCartersianProductAndTemplateTemplate() {
  int a[3] = {0,1,2};
  double b[3] = {10.0,20.0,30.0};
  vector<int> aVector(a, a+3);
  vector<double> bVector(b, b+3);
  set<double> bSet(b, b+3);
  list<int> aList(a, a+3);
  vector<pair<int, double > > cart1 = cartesianProduct(aVector, bVector);
  vector<pair<int, double > > cart2 = cartesianProduct(aVector, bSet);
  vector<pair<int, double > > cart3 = cartesianProduct(aList, bSet);
  cout << "cartesianProduct(aVector, bVector) ";
  printCart(cart1);
  cout << "cartesianProduct(aVector, bSet) ";
  printCart(cart2);
  cout << "cartesianProduct(aList, bSet) ";
  printCart(cart3);
  
  // template template
  printContainer<std::vector, int>(aVector);

  return 0;
}