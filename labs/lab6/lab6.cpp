#include "HashTable.h"
#include <iostream>
using namespace std;

void testContains(int*, int, HashTable &);
void testGet(int*, int, HashTable &);
void testPut(int*, int, HashTable &);

int main() {
    const int CAPACITY = 4093;
    int arr[] = {1179, 9702, 7183, 50184, 4235, 644, 77, 3077, 23477, 90777};
    int testArr[] = {50184, 77, 0, -1};

    cout
    << "Welcome to the HashTable testing program.\n"
    << "==============================================\n"
    << "Creating a new HashTable with capacity 4093 and inserting \n"
    << "4083 random key-value pairs with unique keys.. "
    << "done.\n" << endl;

    HashTable table(CAPACITY); // Create new hash table
    for (int i = 0; i < 4083; i++) {
        table.put(i, rand());
    }

    testPut(arr, 10, table);
    testContains(testArr, 4, table);
    testGet(testArr, 4, table);

    cout
    << "\n================================================\n"
    << "Thanks for using the HashTable testing program. \nGoodbye." << endl;

    return 0;
}

void testContains(int* testArr, int size, HashTable &table) {
    cout << "\nTESTING CONTAINS.." << endl;
    for (int i = 0; i < size; i++) {
        cout << "contains("<< i << "): "
        << (table.contains(testArr[i]) ? "true" : "false") << endl;
    }
}
void testGet(int* testArr, int size, HashTable &table) {
    cout << "\nTESTING GET.." << endl;
    for (int i = 0; i < size; i++) {
        cout << "get("<< i << "): " << table.get(testArr[i]) << endl;
    }
}

void testPut(int* testArr, int size, HashTable &table) {
    int value = 120;
    cout << "INSERT/UPDATE 10 ADDITIONAL KEY-VALUES..\n";
    for (int i = 0; i < size; i++) {
        cout << "(" << testArr[i] << ", " << value << ")"
        << (table.contains(testArr[i]) ? " update" : " insert")
        << " @["<< table.put(testArr[i] , value) << "]" << endl;
        value++;
    }
}