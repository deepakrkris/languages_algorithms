/**
 * @file 05_weak_ptr_demo_circular_reference.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-11
 * 
 * 
 * Use of weak_ptr to break the circular reference, weak_ptr references do not keep a resource alive
 * 
 * Using a weak_ptr we cannot access the owned object. There are no * and -> operators defined for weak_ptr.
 * We have to get a shared_ptr to the owned object before using it. The lock() function of weak_ptr helps us do exactly that.
 * It returns a shared_ptr object with the information preserved bby the weak_ptr.
 * If the object has already been destroyed, lock() returns a shared_ptr object with default values.
 * 
 * Reference : https://www.codementor.io/@sandesh87/smart-pointers-in-c-part-5-1jdn6o4bcb
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
  std::weak_ptr<Bar> pBar;

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
  std::weak_ptr<Foo> pFoo;

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

  std::weak_ptr<Foo> & fref = bar_shared_ptr->pFoo;
  std::weak_ptr<Bar> & bref = foo_shared_ptr->pBar;

  cout << " use count of Foo after setting circular reference " << foo_shared_ptr.use_count() << endl;
  cout << " use count of Bar after setting circular reference " << bar_shared_ptr.use_count() << endl;

  cout << " use count of Foo weak ptr " << fref.use_count() << endl;
  cout << " use count of Bar weak ptr " << bref.use_count() << endl;
}

/**
 * @brief 
 * 
 * @return int 
 */
int main() {
    cout << endl << endl << " START " <<  " weak ptr demo circular reference " << endl;
    cout << std::string(20, '_') << endl;
 
    Foo *foo_object_ptr = new Foo();
    Bar *bar_object_ptr = new Bar();

    // create struct objects
    std::shared_ptr<Foo> foo_shared_ptr(foo_object_ptr);
    std::shared_ptr<Bar> bar_shared_ptr(bar_object_ptr);

    test_circular_reference(foo_shared_ptr, bar_shared_ptr);

    foo_shared_ptr.reset();
    bar_shared_ptr.reset();

    cout << " Foo object access after reset " << foo_object_ptr->foo_value << endl;
    cout << " Bar object access after reset " << bar_object_ptr->bar_value << endl;
    cout << std::string(20, '_') << endl;
}
