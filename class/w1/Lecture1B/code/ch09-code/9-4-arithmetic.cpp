#include <iostream>
using namespace std;

int main()
{
  int vals[] = {4, 7, 11};
  int * valptr = vals;

  valptr++;
  cout << "valptr++: " << valptr << endl;
  valptr--;
  cout << "valptr--: " << valptr << endl;

  cout << "*(valptr + 2): " << *(valptr + 2) << endl;

  cout << "assign to first element...\n";
  valptr = vals;
  valptr += 3;
  cout << "valptr += 3: " << valptr << endl;
  cout << *valptr << endl; 
  cout << "valptr–val: " << valptr-vals << endl;
}
