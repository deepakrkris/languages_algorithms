#include <iostream>
#include <algorithm>

using namespace std;

int main() {    
    cout << endl << endl << " START " <<  " Lambda Function " << endl;
    cout << "------------------------------------------------------- " << endl;

    int lastc = 0;
    char s[] = "i am going on a long ride to the moon";

    auto first_letter_cap_words = [&lastc](char c) {
        char return_char = c;
        if (lastc == 0 || lastc == ' ') {
            return_char = toupper(c);
        }
        lastc = c;
        return return_char;
    };

    transform(s , s + strlen(s), s, first_letter_cap_words);

    cout << "tranformed string with lambda :  " << s;

    cout << endl << "------------------------------------------------------- " << endl << endl ;
    cout << endl << "------------------------------------------------------- " << endl << endl ;
    return 0;
}
