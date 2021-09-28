#include <iostream>
using namespace std;

int main()
{
  int x = 5, y = 5;
  int * ptrX = &x;
  int * ptrY = &y;

  if (ptrX == ptrY)
    cout << "addresses are the same\n";
  else
    cout << "addresses are not the same\n";

  if (*ptrX == *ptrY)
	 cout << "values are the same\n";
  else
    cout << "values are not the same\n";
}
