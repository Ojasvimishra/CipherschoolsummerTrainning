#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    void setDetails(string n, int a) {
        name = n;
        age = a;
    }
};

class Student : public Person {
private:
    int rollNumber;
public:
    void setStudent(string n, int a, int r) {
        setDetails(n, a);
        rollNumber = r;
    }
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll Number: " << rollNumber << endl;
    }
};

class Vehicle {
protected:
    int speed;
public:
    virtual void displaySpeed() = 0;
};

class Car : public Vehicle {
public:
    Car() {
        speed = 180;
    }
    void displaySpeed() {
        cout << "Car Speed: " << speed << " km/h" << endl;
    }
};

class Bike : public Vehicle {
public:
    Bike() {
        speed = 120;
    }
    void displaySpeed() {
        cout << "Bike Speed: " << speed << " km/h" << endl;
    }
};

int main() {
    Student s;
    s.setStudent("Ojasvi", 20, 101);
    s.display();

    Car c;
    Bike b;
    c.displaySpeed();
    b.displaySpeed();

    return 0;
}
