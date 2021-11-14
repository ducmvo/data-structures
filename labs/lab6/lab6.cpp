#include "HashTable.h"
#include <iostream>
using namespace std;

int main() {
    HashTable table(4093);

    cout << "Welcome to the HashTable testing program." << endl;

    cout << "Creating a new HashTable with capacity 4093 and inserting \n"
            "4083 random key-value pairs with unique keys.. ";

    for (int i = 1; i < 4084; i++) {
        table.put(i, rand());
    }
    cout << "done.\n" << endl;

    int arr[] = {1179, 120, 9702, 121, 7183, 122, 50184, 123, 4235,
                 124, 644, 125, 77, 126, 3077, 127, 23477, 128, 90777, 129};
    cout << "Inserting 10 additional key-values..\n";
    for (int i = 0; i < 20; i+=2) {
        cout << "(" << arr[i] <<" , "<< arr[i+1] << ")" << endl;
        table.put(arr[i] ,arr[i+1]);
    }

    cout << "\nTesting contains.." << endl;
    int testArr[] = {50184, 77, 0, -1};
    for (int i : testArr) {
        cout << "contains("<< i << "): "
        << (table.contains(i) ? "true" : "false") << endl;
    }

    cout << "\nTesting get.." << endl;
    for (int i : testArr) {
        cout << "get("<< i << "): "
             << table.get(i) << endl;
    }

    cout << "\nThanks for using the HashTable testing program. Goodbye." << endl;

    return 0;
}