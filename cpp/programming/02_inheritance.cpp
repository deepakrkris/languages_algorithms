#include <iostream>
#include <string>
#include <list>
using namespace std;

class Animal {
    std::string _name;
    std::string _type;
    // private constructor
    Animal() {};

    protected :
    Animal(const string& name, const string& type) : _name(name) , _type(type) {
        cout << " pet name is " << _name << " which is a " << _type << endl ;
    }

    public:
    virtual std::string speak() = 0;

    std::string getName() {
        return _name;
    }

    std::string move() {
        if (_type == "Bird")
           return "FLIES";
        else if (_type == "Fish")
           return "SWIMS";
        else
           return "WALKS";
    }
};

class Dog : public Animal {
    public :
      Dog(const string& name) : Animal(name, "Mammal") {
      }

      std::string speak() {
        return " BOW BOW ";
      }
};

class Piranha : public Animal {
    public :
      Piranha(const string& name) : Animal(name, "Fish") {
      }

      std::string speak() {
        return " KREEEECH ";
      }
};

class Cuckoo : public Animal {
    public :
      Cuckoo(const string& name) : Animal(name, "Bird") {
      }

      std::string speak() {
        return " Koo KOO ";
      }
};

int main() {
    cout << endl << endl << " START " <<  " inheritance " << endl;
    cout << "------------------------------------------------------- " << endl;

    std::list<Animal*> pets;
    Piranha peter("peter");
    Dog bob("bob");
    Cuckoo sofia("sofia");
    pets.push_back(&peter);
    pets.push_back(&bob);
    pets.push_back(&sofia);

    for (auto ptr : pets) {
        cout << ptr->getName() << " says " << ptr->speak() << " and " << ptr->move() << endl;
    }

    cout << endl << std::string(20, '_') << endl;
    return 0;
}
