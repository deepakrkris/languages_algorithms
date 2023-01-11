#include <iostream>
#include <array>

using namespace std;

int main() {
    cout << endl << endl << " START " <<  " array iterator " << endl;
    cout << string(30, '_') << endl;
    array<int, 4> arr = {1 , 2, 5, 8};

    for (array<int, 4>::iterator it = arr.begin(); it != arr.end(); it++) {
        cout << *it << ",";
    }

    cout << endl << string(30, '_') << endl;
}
