// Sheila Oh
// File: rectangle.cpp
// Date: 9/15/20

#include "rectangle.h"

Rectangle::Rectangle() {
    length = width = 1;
}

Rectangle::Rectangle(double w, double l) {
    width = w;
    length = l;
}

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