#include <iostream>
using namespace std;

// Part 1: Bank Account Hierarchy

class Account {
public:
    virtual void displayBalance() {
        cout << "Account balance display" << endl;
    }
};

class SavingAccount : public Account {
public:
    void displayBalance() override {
        cout << "Saving Account balance: $5000" << endl;
    }
};

class CurrentAccount : public Account {
public:
    void displayBalance() override {
        cout << "Current Account balance: $12000" << endl;
    }
};

// Part 2: Animal Hierarchy

class Animal {
public:
    virtual void speak() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    // Part 1: Using base class pointer
    Account* acc;

    SavingAccount sa;
    CurrentAccount ca;

    acc = &sa;
    acc->displayBalance();

    acc = &ca;
    acc->displayBalance();

    // Part 2: Demonstrating dynamic dispatch
    Animal* animal;

    Dog d;
    Cat c;

    animal = &d;
    animal->speak();

    animal = &c;
    animal->speak();

    return 0;
}
