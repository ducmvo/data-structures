// This program demonstrates the Rectangle class.
#include <iostream>
#include "Rectangle.h"
using namespace std;

int main()
{
  // Define a Rectangle pointer
  Rectangle * rectPtr = nullptr;

  // Dynamically allocate a Rectangle object
  int num;
  cout << "How many rectangles? ";
  cin >> num;
  rectPtr = new Rectangle[num];

  // Store values in the object's width and length
  for (int i = 0; i < num; i++)
  {   
    rectPtr[i].setWidth(10.0);  //*(rectPtr + i).setWidth(10.0)
    rectPtr[i].setLength(15.0);
  }
  
  // Print results
  for (int i = 0; i < num; i++)
  {
    cout << "rectangle " << i + 1 << endl;
    cout << "width: " << rectPtr[i].getWidth() << endl;
    cout << "length: " << rectPtr[i].getLength() << endl;
  }
  
  // Delete the object from memory
  delete [] rectPtr;
  rectPtr = nullptr;
}
