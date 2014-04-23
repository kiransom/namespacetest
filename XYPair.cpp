#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

#define PRINTEXPR(X) cout << #X << " = " << X << endl

template <class T>
void printVector(const vector<T>& vectorToPrint) {
  cout << "{" ;
  for(vector<T>::const_iterator it=vectorToPrint.begin(); it != vectorToPrint.end(); ++it) {
    cout << *it << ", ";
  }
  cout << "}" << endl;
}

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

class XYPair {
private:
  int x;
  double y;
public:
  XYPair(int xarg, double yarg): x(xarg), y(yarg) {;}
  int getX() const {return x;}
  double getY() const {return y;}
  // Define Lexicographic total order
  bool operator> (const XYPair &otherXyPair) const{
    if( x > otherXyPair.getX()) {
      return true;
    } 
    else if (x==otherXyPair.getX() && y > otherXyPair.getY()) {
      return true;
    } 
    else {
      return false;
    }
  }



};

  ostream& operator<< (ostream& o, const XYPair xyPair) {
    o << "{" << xyPair.getX() << ", " << xyPair.getY() << "}";
    return o;
  }

int testerMain() {
  vector<XYPair> xyVector;
  xyVector.push_back(XYPair(100,0.9));
  xyVector.push_back(XYPair(200,0.8));
  xyVector.push_back(XYPair(200,0.85));

  vector<int> indices;
  indices.push_back(0);
  indices.push_back(1);
  indices.push_back(2);

  cout << xyVector[0] << xyVector[1] << xyVector[2];  
  cout << "\n";
  sort(indices.begin(), indices.end(), IndexedGreater<XYPair>(xyVector));
  copy(indices.begin(), indices.end(), ostream_iterator<int>(cout, ","));  
  cout << "\n";
  return 0;
}