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

class NestedList;

struct Element {
    union {
        int integer;
        NestedList* list;
    } element;
    bool isInteger;
};

class NestedList {
  private:
    vector<Element> elements;

  public:
    NestedList() {}
    void push_back(int value) {
        elements.push_back({ value, true });        
    }

    Element push_back(NestedList& list) {
        Element e;
        e.isInteger = false;
        e.element.list = &list;
        elements.push_back(e);
        return e;
    }

    int getInteger(int index) {
        if (elements[index].isInteger) {
            return elements[index].element.integer;
        }
        throw std::runtime_error("Element is not an integer");
    }

    int size() {
        return elements.size();
    }

    Element get(int index) {
        return elements[index];
    }

    NestedList* getList(int index) {
        if (!elements[index].isInteger) {
            return elements[index].element.list;
        }
        throw std::runtime_error("Element is not a list");
    }
};

class Iterator {
    NestedList list;
    stack<Element> it;

    public:
    Iterator(NestedList& params) : list(params) {
        for (int i = list.size() - 1; i >= 0; i--) {
            it.push(list.get(i));
        }
    }

    bool has_next() {
        if (it.size() > 0) {
            return true;
        }
        return false;
    }

    int next() {
        while (it.size() > 0 && !it.top().isInteger) {
            auto list = *it.top().element.list;
            it.pop();
            for (int i = list.size() - 1; i >= 0; i--) {
                it.push(list.get(i));
            }
        }
        if (it.size() > 0) {
            auto e = it.top().element.integer;
            it.pop();
            return e;
        }
        return -1;
    } 
};

NestedList add_nesting(NestedList& lst, vector<int> inner_list) {
    NestedList new_lst;
    for_each(inner_list.begin(), inner_list.end(), [&new_lst](int& i) {
        new_lst.push_back(i);
    });
    lst.push_back(new_lst);
    return new_lst;
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

    root_list.push_back(98); 
    list2.push_back(99);
    list3.push_back(100);

    cout << " size of root " << root_list.size() << endl;
    cout << " size of list2 " << list2.size() << endl;
    cout << " size of list3 " << list3.size() << endl;
    cout << " size of list4 " << list4.size() << endl;

    Iterator it(root_list);
    while(it.has_next()) {
        cout << it.next() << " ,  ";
    }

    cout << endl;
}
