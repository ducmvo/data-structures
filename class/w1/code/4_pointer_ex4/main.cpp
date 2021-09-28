// Pointers and arrays
// Do on whiteboard!
#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int arr[SIZE] = {4, 7, 11, 3, 19};
    int * arrPtr = arr;

    cout << "arrPtr: " << arrPtr << endl << endl;

    cout << "printing arr\n";
    for (int i = 0; i < SIZE; i++)
        cout << arrPtr[i] << " ";
    cout << endl << endl;

    if (arrPtr == arr)
        cout << "these are the same!\n";
    else
        cout << "these are not the same :(\n";

    arrPtr++;
    arrPtr[2] = 10000;

    cout << "\narrPtr: " << arrPtr << endl;

    cout << "printing arr\n";
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    cout << endl << endl;

    cout << "printing arrPtr\n";
    for (int i = 0; i < SIZE; i++)
        cout << arrPtr[i] << " ";
    cout << endl << endl;

    if (arrPtr == arr)
        cout << "these are the same!\n";
    else
        cout << "these are not the same :(\n";

    return 0;
}
