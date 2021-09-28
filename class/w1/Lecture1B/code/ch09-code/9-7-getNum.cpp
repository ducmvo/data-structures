#include <iostream>
using namespace std;

void getNum(int *);

int main()
{
  int num;
  getNum(&num);
  cout << "num: " << num << endl;  
}

void getNum(int *num)
{
  cout << "Enter a number: ";
  cin >> *num;
}
