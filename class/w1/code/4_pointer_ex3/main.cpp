// Pointer arrays
#include <iostream>
using namespace std;

int main() {
    const int SIZE = 3;
    int arr[SIZE];

    // populate array
    for (int i = 0; i < SIZE; i++)
        arr[i] = i;

    // print array (array notation)
    cout << "print array with array notation:\n";
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << ' ';
    cout << endl;

    // print array (pointer notation)
    cout << "\nprint array with pointer notation (each element):\n";
    cout << "arr: " << arr << endl;
    cout << "&arr[0]: " << &arr[0]
         << ", *arr: " << *(arr + 0) << endl; // (arr + 0) <-> (memory address arr + 0 integer sizes away) <-> (arr)
    cout << "&arr[1]: " << &arr[1]
         << ", *arr: " << *(arr + 1) << endl; // (arr + 1) <-> (memory address arr + 1 integer size away)
    cout << "&arr[2]: " << &arr[2]
         << ", *arr: " << *(arr + 2) << endl; // (arr + 2) <-> (memory address arr + 2 integer sizes away)

    // print array (pointer notation) again but in for loop
    cout << "\nprint array with pointer notation (using loop):\n";
    for (int i = 0; i < SIZE; i++)
        cout << &arr[i] << ", " << *(arr + i) << endl;


    // lines 37 and 38 do the same thing - assign second element
    // of array to value 5
    *(arr + 1) = 5;
    arr[1] = 5;

    // lines 43 and 44 do the same thing, however, index 3 is out
    // of bounds and would result in an error (which is why it's
    // commented out)
    // *(arr + 3) = 12;
    // arr[3] = 12;

    return 0;
}
