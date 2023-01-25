#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Movie {
    string _name;

public :
    Movie(const string& name) : _name(name) {}

    Movie(const Movie& m) : _name(m._name) {
        cout << "copy constructor called  :  " << m._name << endl;
    }
};

int main() {
    cout << endl << endl << " START " <<  " copy constructor " << endl;
    cout << std::string(20, '_') << endl;

    Movie new_movie("Gilli");
    Movie old_movie("Anbe Va");

    vector<Movie> list;
    //list.reserve(5);

    list.push_back(new_movie);
    list.push_back(old_movie);

    list.emplace_back("other guy");
    list.emplace_back("Ooty varai uravu");

    cout << endl << std::string(20, '_') << endl;
}
