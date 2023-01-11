#include <iostream>
using namespace std;

int main()
{
    cout << endl << endl << " START " <<  " auto keyword " << endl;
    cout << string(30, '_') << endl;
    int arr[] = {10, 20, 30, 40, 50};

    for (auto i : arr) {
        cout << i << ' ';
    }
    
    cout << endl << string(30, '_') << endl;
}
