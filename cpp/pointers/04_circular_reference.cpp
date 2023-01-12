/**
 * @file 04_circular_reference.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-11
 * 
 * 
 * Circular reference is a series of references such that each object i references the object i+1 and the last object references the first,
 * thus forming a reference loop. To find out what's wrong with a circular reference, let's consider an example.
 * 
 * Ref : https://www.codementor.io/@sandesh87/smart-pointers-in-c-part-5-1jdn6o4bcb
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <memory>

using namespace std;

struct Bar;

/**
 * @brief 
 * 
 */
struct Foo {
  int foo_value = 10;
  std::shared_ptr<Bar> pBar;

  ~Foo() {
    cout << " Destructor called for Foo object with value " << foo_value << endl;
    cout << endl << std::string(8, '_') << endl;
  }
};

/**
 * @brief 
 * 
 * 
 */
struct Bar {
  int bar_value = 10;
  std::shared_ptr<Foo> pFoo;

  ~Bar() {
    cout << " Destructor called for Bar object with value " << bar_value << endl;
    cout << endl << std::string(8, '_') << endl;
  }
};

void setting_circulare_reference(std::shared_ptr<Foo>& f, std::shared_ptr<Bar>& b) {
  // circular reference
  f->pBar = b;
  b->pFoo = f;
}

/**
 * @brief 
 * 
 * @param foo_shared_ptr 
 * @param bar_shared_ptr 
 */
void test_circular_reference(std::shared_ptr<Foo> &foo_shared_ptr, std::shared_ptr<Bar> &bar_shared_ptr) {
  cout << " use count of Foo " << foo_shared_ptr.use_count() << endl;
  cout << " use count of Bar " << bar_shared_ptr.use_count() << endl;

  setting_circulare_reference(foo_shared_ptr, bar_shared_ptr);

  std::shared_ptr<Foo> & fref = bar_shared_ptr->pFoo;
  std::shared_ptr<Bar> & bref = foo_shared_ptr->pBar;

  cout << " use count of Foo after setting circular reference " << foo_shared_ptr.use_count() << endl;
  cout << " use count of Bar after setting circular reference " << bar_shared_ptr.use_count() << endl;

  foo_shared_ptr.reset();
  bar_shared_ptr.reset();

  cout << " use count of Foo after reset " << fref.use_count() << endl;
  cout << " use count of Bar after reset " << bref.use_count() << endl;
}

/**
 * @brief 
 * 
 * @return int 
 */
int main() {
    cout << endl << endl << " START " <<  " circular reference " << endl;
    cout << std::string(20, '_') << endl;
 
    Foo *foo_object_ptr = new Foo();
    Bar *bar_object_ptr = new Bar();

    // create struct objects
    std::shared_ptr<Foo> foo_shared_ptr(foo_object_ptr);
    std::shared_ptr<Bar> bar_shared_ptr(bar_object_ptr);

    test_circular_reference(foo_shared_ptr, bar_shared_ptr);

    cout << " Foo object access after reset " << foo_object_ptr->foo_value << endl;
    cout << " Bar object access after reset " << bar_object_ptr->bar_value << endl;
    cout << std::string(20, '_') << endl;
}
