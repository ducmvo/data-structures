#include <iostream>
using namespace std;

void swap(int *, int *);

int main()
{
  int x, y;
  cout << "Enter two integers, separated by a space: ";
  cin >> x >> y;
  cout << "Your numbers: " << x << " " << y << endl;
  swap(&x, &y);
  cout << "Your swapped numbers: " << x << " " << y << endl;
}

void swap(int *xPtr, int *yPtr)
{
  int temp;
  temp = *xPtr;
  *xPtr = *yPtr;
  *yPtr = temp;
}
