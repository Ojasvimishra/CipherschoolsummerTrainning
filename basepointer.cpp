#include <iostream>
using namespace std;

class Graphic {
public:
    virtual void render() {
        cout << "Rendering Graphic" << endl;
    }
    void info() {
        cout << "General Graphic Info" << endl;
    }
};

class Ellipse : public Graphic {
public:
    void render() override {
        cout << "Rendering Ellipse" << endl;
    }
};

class Square : public Graphic {
public:
    void render() override {
        cout << "Rendering Square" << endl;
    }
};

int main() {
    Graphic* gptr;

    Ellipse e;
    Square s;

    gptr = &e;
    gptr->render();
    gptr->info();

    gptr = &s;
    gptr->render();
    gptr->info();

    return 0;
}
