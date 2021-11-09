#include "Heap.h"
#include <iostream>
using namespace std;

int main() {
    Heap myHeap(10);

    cout << "creating heap...\n";
    cout << "heap is " << ((myHeap.empty()) ? "empty" : "not empty") << endl;
    cout << "max (peek): " << myHeap.peek() << endl;

    cout << "\nadding 50, 25, 40, 20, 10, 15, 30, 5...\n";
    myHeap.add(50);
    myHeap.add(25);
    myHeap.add(40);
    myHeap.add(20);
    myHeap.add(10);
    myHeap.add(15);
    myHeap.add(30);
    myHeap.add(5);

    cout << "traversal: " << myHeap.getLevelTraversal();
    cout << "heap is " << ((myHeap.empty()) ? "empty" : "not empty") << endl;
    cout << "max (peek): " << myHeap.peek() << endl;

    cout << "\nremoving max...\n";
    myHeap.remove();
    cout << "traversal: " << myHeap.getLevelTraversal();
}

