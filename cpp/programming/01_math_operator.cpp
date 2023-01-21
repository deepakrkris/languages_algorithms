#include <iostream>
#include <string>
using namespace std;

class Math {
    int num = 0;
  public :
    Math(int value) : num(value) {}

    Math(const Math& math) : num(math.num) {}

    std::string string() const;
    std::string raw_string() const;

    int get_value() const {
        return num;
    }
};

std::string Math::string() const {
    return std::to_string(get_value());
}

std::string Math::raw_string() const {
    return std::to_string(get_value());
}

Math operator * (const Math& ls , const Math rs) {
    return ls.get_value() * rs.get_value();
}

Math operator + (const Math ls, const Math rs) {
    return ls.get_value() + rs.get_value();
}

Math operator - (const Math ls, const Math rs) {
    return ls.get_value() - rs.get_value();
}

Math operator / (const Math ls, const Math rs) {
    return ls.get_value() / ls.get_value();
}

ostream& operator << (ostream& o, const Math m) {
    return o << m.string();
}

int main() {
    cout << endl << endl << " START " <<  " math operator " << endl;
    cout << "------------------------------------------------------- " << endl;

    Math a(20);

    cout <<  " a times 10 is "  <<  a * 10 << endl; 
    cout <<  " a divided by 10 is  " << a / 10 << endl;
    cout <<  " a + 10 is " << a + 10 << endl;

    cout <<  " 10 times a is "  <<  10 * a << endl; 
    cout <<  " 10 divided by a is  " << 10 / a << endl;
    cout <<  " 10 + a is " << 10 + a << endl;
    cout <<  " 10 - a is " << 10 - a << endl;

    Math b(10);

    cout << " a times b is " << a * b << endl;
}
