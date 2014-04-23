#include <memory>
#include <iostream>

using namespace std;

void incrementBy1_ver1(shared_ptr<int> sp) { 
  // copy happens here, and ownership is shared with the copy
  cout << "inside incrementBy1_ver1\n";
  cout << sp.use_count() << endl;
  ++(*sp);
  cout << sp.use_count() << endl;
}

void incrementBy1_ver2(shared_ptr<int>& spRef) { 
  // no copy happens here, this pattern is used if you want to change the smart pointer, 
  //i.e., change what it is pointing to
  cout << "inside incrementBy1_ver2\n";
  cout << spRef.use_count() << endl;
  ++(*spRef);
  cout << spRef.use_count() << endl;
}

void assignToAnotherSharedPtr(const shared_ptr<int>& spConstRef) { 
  // const ref means no copy and no modification to the passed smart pointer. 
  // However, the ownership can be shared with another object
  cout << "inside assignToAnotherSharedPtr\n";
  cout << spConstRef.use_count() << endl;
  shared_ptr<int> anotherSharedOwner = spConstRef;
  cout << spConstRef.use_count() << endl;
}

int mainSharedPtrMystery() {
  shared_ptr<int> sp = make_shared<int>(10);
  cout << sp.use_count() << endl;
  incrementBy1_ver1(sp);
  cout << sp.use_count() << endl;
  incrementBy1_ver2(sp);
  cout << sp.use_count() << endl;
  assignToAnotherSharedPtr(sp);
  cout << sp.use_count() << endl;
  return 0;
}