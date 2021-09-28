/**
 * Classes and Objects
 * 3 files in this project:
 * 1. main.cpp - Entry point, where code begins execution when the program is run.
 * 2. rectangle.h - Header (aka specification) file. Contains class definitions and functions.
 * 3. rectangle.cpp - Class implementation file. Contains implementation of functions defined in header file.
 */

// To instantiate objects defined by a class in C++, you must include the .h file of the object you wish to instantiate.
// Note - do not include the implementation (.cpp) file.
#include "rectangle.h"

#include <iostream>
using namespace std;

// Functions in C++ must be defined BEFORE they are used.
// We will be using this method in the main, but implementing underneath the main method, so it must be declared first.
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

    return 0;
}

void print(Rectangle r) {
    cout << "width: " << r.getWidth() << ", ";
    cout << "length: " << r.getLength() << ", ";
    cout << "area: " << r.getArea() << endl;
}