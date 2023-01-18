#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void pretty_print(vector<int> input) {
    std::for_each(input.begin(), input.end(), [](int num){  cout << num << "  "; });
    cout << endl;
}

void quick_sort(vector<int>& numbers, int begin, int end) {

    if (begin >= end) {
        return;
    }

    int p_num = numbers[end];

    int left = begin;
    int right = end - 1;

    while (left <= right) {
        if (numbers[right] < p_num) {
            swap(numbers[right], numbers[left]);
            left ++;
        } else {
            right --;
        }
    }

    swap(numbers[left], numbers[end]);

    quick_sort(numbers, begin, left - 1);
    quick_sort(numbers, left + 1, end);
}

int main()
{
    cout << endl << endl << " START " <<  " Quick Sort !!! " << endl;
    cout << "------------------------------------------------------- " << endl;

    vector<int> array = { 34, 2, 24, 12, 33 };

    pretty_print(array);

    quick_sort(array, 0, array.size() - 1);

    cout << endl << endl << " After Quick Sort :  " << endl;

    pretty_print(array);

    cout << "------------------------------------------------------- " << endl << endl ; 
    cout << "------------------------------------------------------- " << endl << endl ;
    return 0;
}
