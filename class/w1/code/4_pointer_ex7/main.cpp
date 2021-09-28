// passing in pointer as parameter, return pointer from function
#include <iostream>
using namespace std;

double * getArray(int);
void printArray(double *, int);

int main() {
    // declare variables
    int size;
    double * arr = nullptr;

    // print address (should be 0)
    cout << "address of array: " << arr << endl;

    // ask user for array size
    cout << "Enter the array size: ";
    cin >> size;

    // get array, passing in size
    arr = getArray(size);

    // print array
    cout << "\nprinting array values...\n";
    printArray(arr, size);

    // deallocate memory
    cout << "\ndeallocating array memory...\n";
    delete [] arr;

    arr = nullptr;
    cout << "address of array: " << arr << endl;
    // printArray(arr, size); // this results in segmentation fault!

    return 0;
}

double * getArray(int size) {
    double * arr = new double[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter double " << i + 1 << " of " << size << ": ";
        cin >> arr[i];
    }
    return arr;
}

void printArray(double * arr, int size) {
    for (int i = 0; i < size; i++)
        cout << "arr[" << i << "] = " << arr[i] << endl;
}
