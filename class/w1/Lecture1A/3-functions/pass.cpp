#include <iostream>
using namespace std;

int multiply(int, int);
void getInput(int &, int &);

int main() {
  int x, y;
  getInput(x, y);
  cout << "product: " << multiply(x, y) << endl;
  return 0;
}

int multiply(int num1, int num2) {
  return num1 * num2;
}

void getInput(int &val1, int &val2) {
  cout << "Please supply two integers: ";
  cin >> val1 >> val2;
}
