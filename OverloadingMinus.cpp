#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// Transform and substracting a constant from a vector
// bind2nd

using namespace std;

struct XYZPoint {
    double x;
    double y;
    double z;
    XYZPoint(): x(0.0), y(0.0), z(0.0) {}
    XYZPoint(double x_arg, double y_arg, double z_arg): x(x_arg), y(y_arg), z(z_arg) {}
    double getL2Norm() {return sqrt(pow(x,2)+pow(y,2)+pow(z,2));}
    XYZPoint operator-(const XYZPoint& rightXYZPoint) const {
      XYZPoint leftXYZPoint;
      leftXYZPoint.x = x - rightXYZPoint.x;
      leftXYZPoint.y = y - rightXYZPoint.y;
      leftXYZPoint.z = z - rightXYZPoint.z;
      return leftXYZPoint;
    }
};

ostream& operator<<(ostream& o, const XYZPoint& xyzPoint) {
  o << "(" << xyzPoint.x << "," << xyzPoint.y << "," << xyzPoint.z << ")";
  return o;
}

int mainOverloadingMinus() {
  XYZPoint zero(0, 1, 2);
  XYZPoint one(10,20,30);
  XYZPoint two(5,14,23);
  XYZPoint three(1,2,3);
  vector<XYZPoint> vectorOfPoints(3);
  vectorOfPoints[0] = zero;
  vectorOfPoints[1] = one;
  vectorOfPoints[2] = two;
  std::for_each(vectorOfPoints.begin(), vectorOfPoints.end(), [](const XYZPoint& xyzPoint) { cout << xyzPoint << " "; });
  cout << endl;
  std::transform(vectorOfPoints.begin(), vectorOfPoints.end(), vectorOfPoints.begin(), std::bind2nd(std::minus<XYZPoint>(), three));
  std::for_each(vectorOfPoints.begin(), vectorOfPoints.end(), [](const XYZPoint& xyzPoint) { cout << xyzPoint << " "; });
  cout << endl;
  cout << one << " " << two << endl;
  XYZPoint four = two-one;
  cout << four << " " << (two-one).getL2Norm() <<  endl;
  cout << one << " " << two << endl;
  return 0;
}