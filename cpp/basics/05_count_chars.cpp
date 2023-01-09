#include <iostream>
using namespace std;

int main() {
    cout << endl << endl << " START " <<  " Count chars " << endl;
    cout << string(20, '_') << endl;

    std::string s;
    cout << endl << " ** input string to count characters : ";
    getline(cin, s);
    int count = 0;

    for (char c : s) {
        count ++;
    }

    cout << "length of input string is " << count << endl;
    cout << string(20, '_') << endl;
}
