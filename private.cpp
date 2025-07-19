#include <iostream>
using namespace std;

struct Book {
    string title;
    string author;
    float price;
};

class Rectangle {
    float length;
    float breadth;
public:
    void setDimensions(float l, float b) {
        length = l;
        breadth = b;
    }
    float area() {
        return length * breadth;
    }
};

int main() {
    Book b;
    cout << "Enter book title: ";
    getline(cin, b.title);
    cout << "Enter author name: ";
    getline(cin, b.author);
    cout << "Enter price: ";
    cin >> b.price;

    cout << "\nBook Details:\n";
    cout << "Title: " << b.title << endl;
    cout << "Author: " << b.author << endl;
    cout << "Price: $" << b.price << endl;

    Rectangle r;
    float l, br;
    cout << "\nEnter length and breadth of rectangle: ";
    cin >> l >> br;
    r.setDimensions(l, br);
    cout << "Area of Rectangle: " << r.area() << endl;

    return 0;
}
