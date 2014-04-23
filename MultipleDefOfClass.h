#pragma once


/*

// Linker wont complain even though we may have multiple definitions
// Think of it as class declaration

*/

class A {
public:
  int foo() {
    return 10;
  }
};

/*

// You cannot have a namepace with defintions because the linker will complain

namespace X {
  int foo() {
    return -10;
  }
}
*/