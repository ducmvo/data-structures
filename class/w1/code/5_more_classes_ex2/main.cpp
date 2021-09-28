// Sheila Oh
// File: main.cpp
// Date: 9/15/20

#include "rectangle.h"
#include <iostream>
using namespace std;

void print(Rectangle);

int main() {
    // create Rectangle objects
    cout << "\n** create two Rectangle objects ** \n";
    Rectangle r;
    Rectangle r2(5, 7);

    // set width and length
    r.setWidth(6);
    r.setLength(8);

    // print
    cout << "printing first Rectangle => ";
    print(r);
    cout << "printing second Rectangle => ";
    print(r2);

    // create and assign Rectangle pointer
    cout << "\n** create Rectangle pointer object **\n";
    Rectangle * rPtr = &r;
    rPtr->setWidth(12);
    rPtr->setLength(15);

    // print again
    cout << "printing first Rectangle again => ";
    print(r);
    cout << "printing Rectangle pointer => ";
    print(*rPtr);

    return 0;
}

void print(Rectangle r) {
    cout << "width: " << r.getWidth() << ", ";
    cout << "length: " << r.getLength() << ", ";
    cout << "area: " << r.getArea() << endl;
}