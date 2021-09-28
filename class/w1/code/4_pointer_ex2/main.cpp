// Pointers
#include <iostream>
using namespace std;

int main() {
    //We set the pointer ptr to the memory address of 5
    int val = 5;
    int * ptr = &val;

    //Think of "&" as memory address of ...
    //Think of "*" as the contents of ... also known as dereference the pointer
    cout << "val: " << val << ", &val: " << &val << endl;
    cout << "ptr: " << ptr << ", *ptr: " << *ptr << endl;
    cout << "&ptr: " << &ptr << endl;

    cout << "\nupdate number to 12\n";
    *ptr = 12;
    cout << "val: " << val << ", &val: " << &val << endl;
    cout << "ptr: " << ptr << ", *ptr: " << *ptr << endl;
    cout << "(note: same address, different value)\n";

    cout << "\nEnter a number: ";
    cin >> *ptr;
    cout << "val: " << val << ", &val: " << &val << endl;
    cout << "ptr: " << ptr << ", *ptr: " << *ptr << endl;
    cout << "(note: same address, different value)\n";

    return 0;
}
