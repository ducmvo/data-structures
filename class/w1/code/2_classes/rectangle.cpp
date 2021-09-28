// Sheila Oh
// File: rectangle.cpp
// Implementation file for the Rectangle class.

// To implement objects defined by a header in C++, you must include the .h file of the object.
#include "rectangle.h"

// Use the Scope Resolution Operator (<CLASS NAME>::) to define constructors/functions from the Rectangle header file.
Rectangle::Rectangle() {
    length = width = 1;
}

Rectangle::Rectangle(double width, double l) {
    this->width = width;
    length = l;
}

/*
 * You can rewrite the constructor (lines 13-16) that
 * takes in 2 arguments using an initializer list; note
 * that validation of the parameters is not possible when
 * you assign the class fields using an initializer list:

Rectangle::Rectangle(double w, double l)
        : width(w), length(l) { }
 */

void Rectangle::setWidth(double w) {
    width = w;
}

void Rectangle::setLength(double l) {
    length = l;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getLength() const {
    return length;
}

double Rectangle::getArea() const {
    return width * length;
}