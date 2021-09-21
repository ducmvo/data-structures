#include <iostream>
#include <fstream>
using namespace std; 

int main() { 
  ifstream inputFile; 
  const int SIZE = 100;
  int number, arr[SIZE], count = 0; 
  string filename;

  // Get the file name 
  cout << "Enter the file name: ";
  getline(cin, filename);

  // Open the file & read numbers. Store in array. 
  inputFile.open(filename); 
  if (inputFile.is_open()) {
    while (inputFile >> number) {
      arr[count] = number;
      count++;
    }
  } else
    cout << "Cannot open the file" << endl;

  // Close the file 
  inputFile.close(); 

  // print results 
  for (int i = 0; i < count; i++)
    cout << "arr[" << i << "] = " << arr[i] << endl;

  return 0;
}
