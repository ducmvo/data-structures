#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList<int> intList;
    LinkedList<double> doubleList;
    int arr1[] = {3, -2, 5, 12, -2, -4, 5};
    double arr2[] = {-3.2, 2.14, -5.7, -12.01, -2.99, 4.6, 5.2};

    for (int num : arr1) {
        intList.append(num);
    }
    cout << "Last Negative Number: " << intList.getLastNegative()  << endl;
    cout << "Linked List Values: " << intList.to_string() << endl;

    for (double num : arr2) {
        doubleList.append(num);
    }
    cout << "Last Negative Number: " << doubleList.getLastNegative()  << endl;
    cout << "Linked List Values: " << doubleList.to_string() << endl;
}