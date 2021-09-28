// Sheila Oh
// File: rectangle.h
// Date: 9/15/20

#ifndef WEEK1_RECTANGLE_H
#define WEEK1_RECTANGLE_H

class Rectangle {
public:
    Rectangle();
    Rectangle(double, double);
    void setWidth(double);
    void setLength(double);
    double getWidth() const;
    double getLength() const;
    double getArea() const;
private:
    double width;
    double length;
};


#endif //WEEK1_RECTANGLE_H
