#include <cstdio>

#define f(a,b) printf("yes")
#define g(a)   #a
#define h(a) g(a)

int mainPreprocessorMacroExpansion()
{
  printf("%s\n",h(f(1,2)));
  printf("%s\n",g(f(1,2)));
  return 0;
}