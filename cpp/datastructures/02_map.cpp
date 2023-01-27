#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef std::map<char, char> AlphaMap;

std::vector<char> alpha {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main()
{
    cout << endl << endl << " START " <<  " Datastructures : map " << endl;
    cout << "------------------------------------------------------- " << endl;

    AlphaMap m;
    for (auto it = alpha.begin(); it - alpha.begin() <= 13; ++it) {
        char c = *it;
        m[c] = *(it + 13);
        m[*(it + 13)] = c;
    }

    std::cout << "A:" << m['A'] << std::endl;
    std::cout << "T:" << m['T'] << std::endl;
    std::cout << "C:" << m['C'] << std::endl;
    std::cout << "G:" << m['G'] << std::endl;
    std::cout << "Z:" << m['Z'] << std::endl;

    cout << endl << "------------------------------------------------------- " << endl << endl ;
    cout << endl << "------------------------------------------------------- " << endl << endl ;
    return 0;
}
