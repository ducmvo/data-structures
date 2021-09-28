// Sheila Oh
// File: rectangle.h
// Specification file for the Rectangle class.

// Header guards - prevents this file from being included multiple times by the compiler.
#ifndef WEEK1_RECTANGLE_H
#define WEEK1_RECTANGLE_H

class Rectangle {
public:
    Rectangle();                // default constructor
    Rectangle(double, double);  // overloaded constructor

    /*
     * You can get rid of the default constructor by setting
     * default values for width and length (remember to remove
     * or comment out the implementation of the default
     * constructor in the implementation file):

    Rectangle(double = 1, double = 1);
     */

    void setWidth(double);
    void setLength(double);

    /* const represents that no changes to private fields
     * (width and length) will be made by these functions.
     */
    double getWidth() const;
    double getLength() const;
    double getArea() const;

private:
    double width;
    double length;
};


#endif //WEEK1_RECTANGLE_H
