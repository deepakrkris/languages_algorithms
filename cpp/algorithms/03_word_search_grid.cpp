#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief 
 *  
 * Word Search in grid of characters
 *
 * @param grid 
 * @param s 
 * @param pos 
 * @param i 
 * @param j 
 * @return true 
 * @return false 
 *
 * Given an m×n 2-D grid of characters, we have to find a specific word in the grid by combining the adjacent characters.
 * ssume that only up, down, right, and left neighbors are considered adjacent.
 */
bool find(vector<vector<char>> grid, string s, int pos, int i, int j) {
    if (pos == s.length()) {
        return true;
    }

    if (i == grid.size() || j == grid[0].size() || i < 0 || j < 0) {
        return false;
    } 

    if (s[pos] == '*') {
        return false;
    }

    if (s[pos] != grid[i][j]) {
        return false;
    }

    char current_val = grid[i][j];

    grid[i][j] = '*';

    if (find(grid, s, pos + 1, i + 1, j)
       || find(grid, s, pos + 1, i, j + 1)
       || find(grid, s, pos + 1, i - 1, j)
       || find(grid, s, pos + 1, i, j - 1)) {
        return true;
    }

     grid[i][j] = current_val;

    return false;
}

bool word_search_grid(vector<vector<char>> grid, string s) {
    for (int i=0; i < grid.size(); i++) {
        for (int j=0; j < grid[0].size(); j++) {
            if (find(grid, s, 0, i, j)) {
                return true;
            }
        }
    }

    return false;
}

void print_grid(vector<vector<char>>& v) {
    for_each(v.begin(), v.end(), [](auto& r) {
        for (auto &e : r) {
            cout << e << " "; 
        }
        cout << endl;
    });
}

int main() {
    vector<vector<char>> test_data = {
        { 'A' , 'B', 'E' },
        { 'C' , 'A', 'L' },
        { 'L' , 'L', 'F' } 
    };

    vector<vector<char>> test_data2 = {
        { 'A' , 'B', 'E' },
        { 'C' , 'A', 'L' },
        { 'L' , 'L', 'F' },
        { 'O' , 'O', 'N'}
    };

    cout << endl << " Test data is " << endl;
    print_grid(test_data);
    cout << endl << (word_search_grid(test_data, "BALL") ? "Match Found" : "Not Found") << endl;

    cout << endl << " Test data is " << endl;
    print_grid(test_data2);
    cout << endl << (word_search_grid(test_data2, "BALLOON") ? "Match Found" : "Not Found") << endl;
}
