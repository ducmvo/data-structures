// Rectangle.cpp
// Implementation file for the Rectangle class used to update the
// width and length and access the width, length, and area
#include "Rectangle.h"

Rectangle::Rectangle()
{
  width = 0.0;
  length = 0.0;
}

Rectangle::Rectangle(double w, double l)
{
  width = w;
  length = l;
}

void Rectangle::setWidth(double w)
{
  width = w;
}

void Rectangle::setLength(double l)
{
  length = l;
}

double Rectangle::getWidth() const
{
  return width;
}

double Rectangle::getLength() const
{
  return length;
}

double Rectangle::getArea() const
{
  return width * length;
}
