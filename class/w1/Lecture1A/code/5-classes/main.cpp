// main.cpp  = test file for Counter class

#include "counter.h"

#include <iostream>
using namespace std;

int main() {
  Counter c;
  cout << "Create object, count = " << c.getCount() << endl;
  c.increment();
  cout << "increment, count = " << c.getCount() << endl;
  c.increment();
  cout << "increment, count = " << c.getCount() << endl;
  c.increment();
  cout << "increment, count = " << c.getCount() << endl;

  c.decrement();
  cout << "decrement, count = " << c.getCount() << endl;
  c.decrement();
  cout << "decrement, count = " << c.getCount() << endl;
  c.decrement();
  cout << "decrement, count = " << c.getCount() << endl;

  return 0;
}
