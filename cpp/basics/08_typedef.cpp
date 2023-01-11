#include <iostream>
#include <array>

using namespace std;

typedef unsigned short points;
typedef unsigned short player_rank;

struct scorecard {
    unsigned short p;
    unsigned short r;
};


ostream& operator << (ostream& o, scorecard scorecard) {
    return o << scorecard.p << " with rank " << scorecard.r << endl;
}

int main() {
    cout << endl << endl << " START " <<  " array iterator " << endl;
    cout << std::string(20, '_') << endl;

    scorecard score = {300, 2};

    cout << "score is : " << score;

    cout << endl << std::string(20, '_') << endl;
}
