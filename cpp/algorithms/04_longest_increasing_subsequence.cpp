/**
 * @file 04_longest_increasing_subsequence.cpp
 * 
 * Given an integer array, nums, return the length of the longest strictly increasing subsequence.

Constraints:

1 \leq
1≤
 nums.length \leq 2500
≤2500
-10^4 \leq
−10 
4
 ≤
 nums[i] \leq 10^4
≤10 
4

[ 7, 12, 3, 8, 9, 4, 5, 6 ]

  7
  7 - 8
  7 - 8 - 9 

*
*/

#include <iostream>
#include <vector>

using namespace std;

int longest_increasing_subsequence(vector<int> & v) {
    vector<int> result(v.size(), 1);
    int max_len = 0;

    for (int j = 0; j < v.size(); j++) {
        auto curr = v[j];
        for (int i = 0; i < j; i++) {
            if (v[i] <= curr) {
                result[j] = max(result[j], result[i] + 1);
            }
        }
        max_len = max(max_len, result[j]);
    }

    return max_len;
}

int main() {
    vector<vector<int>> test_data = {
        { 7, 12, 3, 8, 9, 4, 5, 6 },
        { 2, 4, 5, 2, 3, 4, 7, 9, 8, 10}
    };
    for (auto v : test_data) {
        cout << "test data is : ";
        for_each(v.begin(), v.end(), [](int& e) { cout <<  e << "  ";});
        cout << endl;
        cout << endl << " result is " << longest_increasing_subsequence(v) << endl;
    }
}
