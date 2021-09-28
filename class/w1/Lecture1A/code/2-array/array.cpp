#include <iostream>
using namespace std;

int main() {
  const int SIZE = 5;

  // initialize to zero, print array
  cout << "\ninitialize array to zero...\n";
  int zeroArr[SIZE] = {0};
  for (int i = 0; i < SIZE; i++)
    cout << zeroArr[i] << ' ';
  cout << endl << endl;

  // initialization list, print array
  cout << "initialize array, using initialization list...\n";
  int initArr[] = { 4, 1, -5, 3, 8 };
  for (int i = 0; i < SIZE; i++)
    cout << initArr[i] << ' ';
  cout << endl << endl;

  // iniialize from input, print array
  cout << "initialize array from input...\n";
  int inputArr[SIZE];
  for (int i = 0; i < SIZE; i++) {
    cout << "Enter num " << (i + 1) << ": ";
    cin >> inputArr[i];
  }
  cout << "\nPrint results...\n";
  for (int num : inputArr)
    cout << num << " ";
  cout << endl << endl;
  
  return 0;
}
