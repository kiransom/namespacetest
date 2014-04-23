#pragma once

class TestClass {
public:
  static int i;
  TestClass() {++i;} 
};

int TestClass::i=0;