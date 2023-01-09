#include <iostream>
using namespace std;

int main()
{
  cout << endl << endl << " START " <<  " Bool " << endl;
  cout << std::string(20, '_') << endl;  

  bool b = 10;
  int i = b;

  cout << endl <<  " bool init with int value ,   bool b  :  " <<  b << endl;
  cout << endl <<  " int init with bool value ,   int i :  " <<  i << endl;

  int j = true;
  bool k = j;

  cout << endl <<  " int assigned with bool addition    ,  int j : " <<  j << endl;
  cout << endl <<  " bool assigned with bool addition   ,  bool k :  " <<  k << endl;
  cout << std::string(20, '_') << endl;
}
