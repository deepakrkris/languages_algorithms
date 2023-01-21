#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    cout << endl << endl << " START " <<  " for each " << endl;
    cout << string(30, '_') << endl;
    vector<int> a { 1, 3, 4, 5, 7, 9 };
    std::for_each(a.begin(), a.end(), [](int& num) { cout << num << "   ";  });

    cout << endl;

    std::list<int> b { 1 , 2 , 3 };

    std::for_each(b.begin(), b.end(), [](int& name) { cout << name << "   "; });

    cout << endl;
    cout << string(30, '_') << endl;
}
