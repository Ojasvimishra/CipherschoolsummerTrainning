#include <iostream>
using namespace std;

class Animal {
public:
    Animal(string name) {
        cout << "Animal constructor called for " << name << endl;
    }
    ~Animal() {
        cout << "Animal destructor called" << endl;
    }
};

class Dog : public Animal {
public:
    Dog(string name) : Animal(name) {
        cout << "Dog constructor called for " << name << endl;
    }
    ~Dog() {
        cout << "Dog destructor called" << endl;
    }
};

int main() {
    Dog d("Buddy");
    return 0;
}
