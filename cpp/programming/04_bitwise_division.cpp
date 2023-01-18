#include <iostream>
using namespace std;

int divide(unsigned int a, unsigned int b) {
    int quotient = 0;

    for (int i = 31; i >= 0; i--) {
        if ( b << i <= a) {
            a -= (b << i);
            quotient += (1 << i);
        }
    }
    return quotient;
}

int main() {
    cout << endl << endl << " START " <<  " math operator " << endl;
    cout << "------------------------------------------------------- " << endl;
 
    cout << " 45/3  = " << divide(45, 3) << endl;

    cout << endl << "------------------------------------------------------- " << endl << endl ;
    cout << endl << "------------------------------------------------------- " << endl << endl ;
    return 0;
}
