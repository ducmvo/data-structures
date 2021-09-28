// Rectangle.h
// Specification file for the Rectangle class used to update the
// width and length and access the width, length, and area
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
  // Default constructor
  Rectangle();

  // Constructor that takes in width and length values
  Rectangle(double, double);

  // Updates the width attribute
  void setWidth(double);

  // Updates the length attribute
  void setLength(double);

  // Accesses and returns the width attribute
  double getWidth() const;

  // Accesses and returns the length attribute
  double getLength() const;

  // Calculates and returns the area
  double getArea() const;

private:
  double width;
  double length;
};

#endif
