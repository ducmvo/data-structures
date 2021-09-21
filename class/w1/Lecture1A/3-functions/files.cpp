#include <iostream>
#include <fstream>
using namespace std; 

// function prototypes
void populateNumArray(int [], int, int &);
void getFileName(string &);
void printArr(int [], int);

int main() { 
  const int SIZE = 100;
  int arr[SIZE], count = 0;

  // populate and print array 
  populateNumArray(arr, SIZE, count);
  if (count > 0)
    printArr(arr, count); 
  else
    cout << "No numbers!" << endl;

  return 0;	
}

void populateNumArray(int arr[], int size, int &count) {
  ifstream inputFile;  
  string filename;

  // get the name of file   
  getFileName(filename);

  // open file, read numbers, store in array
  inputFile.open(filename);
  if (inputFile.is_open()) {
    while (inputFile >> arr[count])
      count++;
  }
  inputFile.close(); 
}

void getFileName(string &filename) {
  cout << "Enter the file name: ";
  getline(cin, filename); 
}

void printArr(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << "arr[" << i << "] = " << arr[i] << endl;
}
