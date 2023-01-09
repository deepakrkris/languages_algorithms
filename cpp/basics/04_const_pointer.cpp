#include <iostream>
#include <cstdio>

using namespace std;

void xstrcpy_modify (char *, char *);
char* xstrcpy_const (const char *, const char *, int size);

void xstrcpy_modify (char *t, char *s)
{
    while (*s != '\0') {
        char c = *t;
        *t = *s;
        *s = c;
        t++;
        s++;
    }
}

char* xstrcpy_const (const char *t, const char *s, int n) {
    char* result = new char[n];

    for (int i = 0; i < n; i++) {
        result[i * 2] = *s;
        result[i * 2 + 1] = *t;
        t++;
        s++;
    }

    return result;
}

int main()
{
  cout << endl << endl << " START " <<  " Const Pointer " << endl;
  cout << std::string(20, '_') << endl;

  char source[] = "ABCD";
  char target[] = "WXYZ";

  printf("value of source %s and target %s", source, target); 

  cout << endl ;

  xstrcpy_modify(target, source);

  cout << endl ;

  printf("after call to xstrcpy_modify source %s and target %s", source, target);

  cout << endl ;

  cout << xstrcpy_const(target, source, 8) << endl ;

  printf("after call to xstrcpy_modify source %s and target %s", source, target); 

  cout << endl << endl << std::string(20, '_') << endl;
}
