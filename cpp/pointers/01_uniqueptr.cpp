#include <iostream>
#include <memory>

using namespace std;

int main() {
    cout << endl << endl << " START " <<  " array iterator " << endl;
    cout << std::string(20, '_') << endl;

    int* i = new int(10);
    unique_ptr<int> bar(i);

    unique_ptr<int> foo = std::move(bar);

    if (foo) std::cout << "foo points to " << *foo << '\n';
    else std::cout << "foo is empty\n";

    if (bar) std::cout << "bar points to " << *bar << '\n';
    else std::cout << "bar is empty\n";

    cout << endl << std::string(20, '_') << endl;
}
