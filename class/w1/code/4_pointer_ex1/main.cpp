// Value & address of variables/arrays
#include <iostream>
using namespace std;

void print(int &);
void showValues(int [], int);

int main() {
    const int SIZE = 3;
    int num = -99;
    int arr[SIZE];

    // print integer
    //Notice printing integer in main and passing integer by reference to print() produce same output
    cout << "\nprint integer in main...\n";
    cout << "num: "<< num << ", &num: " << &num << endl;
    cout << "\nprint integer in function...\n";
    print(num);

    // testing array
    cout << "arr: " << arr << endl;
    for (int i = 0; i < SIZE; i++)
        arr[i] = i;

    // print array contents
    cout << "\nprint array in main...\n";
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << ' ' << &arr[i] << endl;
    cout << "\nprint array from function...\n";
    showValues(arr, SIZE);

    return 0;
}

//print accepts reference of an int type
//outputs the integer and the memory address of that integer
void print(int &num) {
    cout << "num: " << num << ", &num: " << &num << endl;
}

//showValues accepts an arr and its size
//outputs the element store in the arr and the memory address where the element is stored
void showValues(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ' << &arr[i] << endl;
}