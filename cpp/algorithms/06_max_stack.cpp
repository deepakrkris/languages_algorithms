#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class MaxStack {
    vector<int> nums;
    stack<int> maxSession;
    int current_size;

    public :
    MaxStack() {
        current_size = 0;
    }

    void push(int n) {
        if (current_size > 0) {
            nums.push_back(n);
            current_size ++;
            if ( nums[maxSession.top() - 1] < n ) {
                maxSession.push(current_size);
            }
        } else {
            current_size ++;
            nums.push_back(n);
            maxSession.push(current_size);
        }
    }

    void pop() {
        if (current_size > 0) {
            //cout << " popping, max now " << nums[maxSession.top() - 1] << endl;
            /*for_each(nums.begin(), nums.end(), [](int& e) {
                cout << e << "  ";
            });*/
            cout << endl;
            if (maxSession.top() == current_size) {
                maxSession.pop();
            }
            nums.pop_back();
            current_size --;
        }
    }

    int top() {
        if (current_size > 0) {
            return nums[current_size - 1];
        }
        return -1;
    }

    int getMax() {
        if (current_size > 0) {
            // cout << " get max() " << maxSession.top() << endl;
            return nums[maxSession.top() - 1];
        }
        return -1;
    }

    int getSize() {
        return current_size;
    }
};

int main() {
    vector<int> test_data = { 2, 7, 3, 8, 1 };
    MaxStack maxStack;
    for (auto i : test_data) {
        maxStack.push(i);
        cout << " max value is " << maxStack.getMax() << endl;
    }

    while (maxStack.getSize() > 0) {
        cout << "  max value is " << maxStack.getMax() << endl;
        maxStack.pop();
    }
}
