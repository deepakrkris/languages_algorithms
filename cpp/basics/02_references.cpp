#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

bool testCallByReference() {
  int a =10, b = 20;
  swap (a, b); // call by reference
  cout << endl << " call by reference " << a << "\t" << b << endl;
  return b < a;
}

int main()
{
  cout << endl << endl << std::string(20, '_') << endl;

  assert( testCallByReference() == true );

  cout << endl << std::string(20, '_') << endl;
}
