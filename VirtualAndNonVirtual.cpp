#include <iostream>
using namespace std;

class Animal {
public:
  void virtual whoAmI() { cout << "I am a virtual Animal" << endl;}
  void whoAmINonVirtual() { cout << "I am a non-virtual Animal" << endl;}
};

class Bird : public Animal {
public:
  void virtual whoAmI() { cout << "I am a virtual Bird" << endl;}
  void whoAmINonVirtual() { cout << "I am a non-virtual Bird" << endl;} // simple overriding
};

class Fox : public Animal {
public:
  void virtual whoAmI() { cout << "I am a virtual Fox" << endl;}
  void whoAmINonVirtual() { cout << "I am a non-virtual Fox" << endl;} // simple overriding
};

void genericWhoAmI(Animal* animal) {
  animal->whoAmI();
  animal->whoAmINonVirtual();
}

int mainVirtualNonVirtual() {
  Bird* bird = new Bird();
  bird->whoAmI();
  bird->whoAmINonVirtual();
  Fox* fox = new Fox();
  fox->whoAmI();
  fox->whoAmINonVirtual();
  cout << "Upcasting" << endl;
  Animal* animalPointer = bird; // Upcasting
  genericWhoAmI(animalPointer);
  animalPointer = fox;  // Upcasting
  genericWhoAmI(animalPointer);

  return 0;
}