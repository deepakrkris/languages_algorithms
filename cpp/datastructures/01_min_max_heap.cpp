#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector

using namespace std;

void print_heap(std::vector<int>& v) {
    for_each(v.begin(), v.end(), [](int& e){ cout << " " << e; });
    cout << endl;
}

int main() {
    cout << endl << string(20, '_') << endl;
    cout << endl << "min max heap " << endl;
    std::vector<int> v = {10,20,30,5,15};

    make_heap(v.begin(), v.end());
    cout << "initial max : " << v.front() << '\n';

    pop_heap(v.begin(), v.end());
    cout << "max after pop : " << v.front() << '\n';

    v.pop_back();

    v.push_back(99);

    make_heap(v.begin(), v.end());
    cout << "max after push : " << v.front() << '\n';

    cout << "heap state :";
    print_heap(v);

    sort_heap(v.begin(),v.end());
    cout << "after sorting vector :";

    print_heap(v);

    cout << endl << string(20, '_') << endl;
}
