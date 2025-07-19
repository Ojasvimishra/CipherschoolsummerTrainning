#include <iostream>
using namespace std;

class Engine {
public:
    void start() {
        cout << "Engine started" << endl;
    }
};

class Car {
private:
    Engine engine;
public:
    void startCar() {
        engine.start();
        cout << "Car is ready to go" << endl;
    }
};

class Printer {
public:
    void printDocument() {
        cout << "Printing document" << endl;
    }
};

class SmartPrinter : public Printer {
public:
    void scanDocument() {
        cout << "Scanning document" << endl;
    }
};

int main() {
    Car myCar;
    myCar.startCar();

    SmartPrinter sp;
    sp.printDocument();
    sp.scanDocument();

    return 0;
}
