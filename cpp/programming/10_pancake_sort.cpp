/**
 * @file 10_pancake_sort.cpp
 * 
 * 
 * 
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-21
 * 
 * @copyright Copyright (c) 2023
 * 
 * 
 * 1 3 4 2 6 5
 * 
 *  1. can only flip (reverse) from 0...K at any time
 *      0 <= K <= N , N size of list  
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

void pretty_print(vector<int>& lst) {
    for_each(lst.begin(), lst.end(), [](int e) { cout << e << "  " ;});
    cout << endl;
}

void flip(vector<int>& arr, int K) {
    auto it = arr.begin();
    reverse(it, it + K);
}

vector<int> pancakeSort(vector<int>& lst ) 
{
    for (int i = lst.size() - 1; i > 0; i--) {
        auto it = lst.begin();
        int max = *max_element(it, it + i + 1);
        cout << max << endl;
        auto pos = find(it, it + i + 1, max);
        if (pos - it > 0 )
            flip(lst, pos - it + 1);
        flip(lst, i + 1);
    }

    return lst;
}

int main() {
    cout << endl << endl << " START " <<  " Pancake Sort !!! " << endl;
    cout << "------------------------------------------------------- " << endl;

    vector<int> array = { 34, 2, 24, 12, 33 };

    pretty_print(array);

    pancakeSort(array);

    cout << endl << endl << " After Pancake Sort : " << endl;

    pretty_print(array);

    cout << "------------------------------------------------------- " << endl << endl ; 
    cout << "------------------------------------------------------- " << endl << endl ;
    return 0;
}
