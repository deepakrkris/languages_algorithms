#include <iostream>
#include <array>
#include <iterator>
#include <vector>

using namespace std;

void pretty_print (vector<int> input) {
    std::for_each(input.begin(), input.end(), [](int num) { cout << num << "  "; });
    cout << endl;
}

void merge(vector<int>& numbers, int const begin, int const mid, int const end) {
    vector<int> left_v;
    vector<int> right_v;

    for (int i = begin; i <= mid; i++)
       left_v.push_back(numbers.at(i));

    for (int i = mid + 1; i <= end; i++)
       right_v.push_back(numbers.at(i));

    int left = 0;
    int right = 0;
    int i = begin;
    for ( ; i <= end && left < left_v.size() && right < right_v.size() ; i++) {
        if (left_v[left] < right_v[right])
           numbers[i] = left_v[left++];
        else
           numbers[i] = right_v[right++];
    }

    while (left < left_v.size()) {
        numbers[i++] = left_v[left++];
    }

    while (right < right_v.size()) {
        numbers[i++] = right_v[right++];
    }
}

void mergeSort(vector<int>& numbers, int const begin, int const end) {
    if (end - begin <= 0) {
        return;
    }
 
    int mid = (begin + end) / 2;

    mergeSort(numbers, begin, mid);
    mergeSort(numbers, mid + 1, end);

    merge(numbers, begin, mid, end);
}

int main()
{
    cout << endl << endl << " START " <<  " Merge Sort !!! " << endl;
    cout << "------------------------------------------------------- " << endl;

    vector<int> numbers { 33, 12, 24, 34, 2 };

    pretty_print(numbers);

    mergeSort(numbers, 0, numbers.size() - 1);

    cout << endl << endl << " After Sort :  " << endl;

    pretty_print(numbers);

    cout << "------------------------------------------------------- " << endl << endl ; 
    cout << "------------------------------------------------------- " << endl << endl ;
    return 0;
}
