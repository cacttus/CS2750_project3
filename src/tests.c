#include "calc.h"
#define TEST_TUPLE(fn, a, b, res)          \
  do {                                     \
    if ((int)fn(a, b) != (int)res) {                 \
        fprintf(stderr, "%s failed the test.\n", #fn); \
        exit(1);                           \
    }                                      \
    else {                                 \
      printf("%s passed the test.\n", #fn);  \
    }                                      \
  } while (0);
void runTests() {
  multiplyTest();
  divideTest();
  addTest();
  subtractTest();
  modulusTest();
}
void multiplyTest() {
  TEST_TUPLE(multiply, 10, 20, 200);
}
void divideTest() {
  TEST_TUPLE(divide, 20, 10, 2);
}
void addTest() {
  TEST_TUPLE(add, 10, 20, 30);
}
void subtractTest() {
  TEST_TUPLE(subtract, 20, 10, 10);
}
void modulusTest() {
  TEST_TUPLE(modulus, 20, 6, 2);
}