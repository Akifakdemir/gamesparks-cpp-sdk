== Structure of the tests

The tests are defined in the folder "tests" and then in their projects. Within each projects are the test groups irganized into folders. Those folders have at least three files:

1. unittest.cc - This is where all the test functions are written
2. unittest_implementation.cc - This is where all functions used by the tests are written
3. unittest_definition.h - This is the definition for the implementation file and is included in "unittest.cc" and "unittest_implementation.cc".

