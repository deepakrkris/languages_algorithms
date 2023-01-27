#include <iostream>
#include <map>
#include <vector>

using namespace std;

int unique_substr_kchars(string s, int k) {
    int max_len = 0;
    int left = 0;
    int right = 0;
    int unique_count = 0;
    map<char, int> unique_char_set;

    for (int right = 0; right < s.length(); right++) {
        if (unique_char_set.find(s[right]) == unique_char_set.end()) {
            unique_count += 1;
        }
        unique_char_set[s[right]] = right;

        if (unique_count > k) {
            int new_left = unique_char_set[s[left]] + 1;
            while (left < new_left) {
                if ( unique_char_set[s[left]] <= new_left ) {
                    unique_char_set.erase(s[left]);
                }
                left ++;
            }
            unique_count -= 1;
        }

        if (unique_count == k) {
            max_len = max(max_len, right - left + 1);
        }
    }

    return max_len;
}

int main() {
    cout << endl << endl << " START " <<  " Unique Substring !!! " << endl;
    cout << string(20, '_') << endl << endl ; 
    
    struct test_data {
        string s;
        int k;
        test_data(string _s, int _k) : s(_s), k(_k) {}
    };

    vector<test_data> data = { test_data("abcba", 2) , test_data("aaabcccc", 2) };

    for (auto t : data) {
        cout << " test data S : " << t.s << " K : " << t.k << "  Result :  ";
        cout << unique_substr_kchars(t.s, t.k) << endl;
    }
    

    cout << string(20, '_') << endl << endl ; 
    return 0;
}
