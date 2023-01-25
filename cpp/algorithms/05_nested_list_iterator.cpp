/*
# Given a list of integers or list of integers, develop a iterator that can flattens a list
# [ 0, [ 0 ] ]
# [ [ [ 1 , 2, 3 ]  ]
# hasNext()
# next()
# [ 0, [0], 1]
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Element {
    virtual bool isInteger() = 0;
};

struct IntElement : public Element {
    int num;

    bool isInteger() {
        return true;
    }
};

struct NestedList : public Element {
    vector<Element*> list;

    bool isInteger() {
        return false;
    }

    int size() {
        return list.size();
    }

    void push_back(Element *e) {
        list.push_back(e);
    }

    void push_back(int a) {
        IntElement e;
        e.num = a;
        list.push_back(&e);
    }

    NestedList push_back(vector<int> lst = {}) {
        NestedList element_list;
        for (auto i : lst) {
            IntElement e;
            e.num = i;
            element_list.push_back(&e);
        }
        list.push_back(&element_list);
        return element_list;
    }

    void push_back(NestedList *lst) {
        list.push_back(lst);   
    }
};

class Iterator {
    NestedList list;
    stack<Element*> stack;

    public:
    Iterator(NestedList& params) : list(params) {
        auto vec_of_num = list.list;
        for(auto it = vec_of_num.rbegin(); it != vec_of_num.rend(); it++) {
            stack.push(*it);
        }
    }

    bool has_next() {
        if (stack.size() > 0) {
            return true;
        }
        return false;
    }

    int next() {
        while (stack.size() > 0 && !stack.top()->isInteger()) {
            NestedList *e = static_cast<NestedList*>(stack.top());
            stack.pop();
            auto vec_of_num = e->list;
            for(auto it = vec_of_num.rbegin(); it != vec_of_num.rend(); it++) {
                stack.push(*it);
            }
        }
        if (has_next()) {
            IntElement* intE = static_cast<IntElement*>(stack.top());
            return intE->num;
        }
        return -1;
    } 
};

NestedList add_nesting(NestedList& lst, vector<int> inner_list) {
    return lst.push_back(inner_list);
}

int main() {
    NestedList root_list;
    vector<int> test_data = {1, 2, 3};
    for (auto e : test_data) {
        root_list.push_back(e);
    }

    NestedList list2 = add_nesting(root_list, {3, 4, 5});
    NestedList list3 = add_nesting(list2, {6, 7});
    NestedList list4 = add_nesting(list3, {9});

    cout << " size of root " << root_list.size() << endl;
    cout << " size of list2 " << list2.size() << endl;
    cout << " size of list3 " << list3.size() << endl;
    cout << " size of list4 " << list4.size() << endl;

    Iterator it(root_list);
    while(it.has_next()) {
        cout << it.next() << endl;
    }
}
