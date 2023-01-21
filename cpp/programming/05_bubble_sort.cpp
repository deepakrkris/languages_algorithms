#include <iostream>
#include <vector>

using namespace std;
 
auto pretty_print = [](vector<int>& nums) { std::for_each(nums.begin(), nums.end(), [](int& n) { std::cout << n << " "; }); std::cout << std::endl;};

void bubbleSort(vector<int>& numbers) {
    for (int j = numbers.size() - 1; j >= 0; j--) {
        for (int i = 0; i < j; i++) {
            if (numbers[i] > numbers[i + 1]) {
                swap(numbers[i], numbers[i + 1]);
            }
        }
    }
}

int main()
{
    cout << endl << endl << " START " <<  " Bubble sort " << endl;
    cout << "------------------------------------------------------- " << endl;

    vector<int> numbers = { 33, 12, 24, 34, 2 };

    pretty_print(numbers);

    bubbleSort(numbers);
  
    cout << endl << endl << " After Sort :  " << endl;
  
    pretty_print(numbers);

    cout << std::string(20, '_') << endl << endl ; 
    cout << std::string(20, '_') << endl << endl ;
    return 0;
}
