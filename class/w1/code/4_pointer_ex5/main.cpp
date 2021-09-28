// Dynamic memory
#include <iostream>
using namespace std;

int main() {
    const int SIZE = 3;
    int val = 5;
    int * ptr = &val;
    cout << "val: " << val << ", *ptr: " << *ptr << endl;
    cout << "&val: " << &val << ", ptr: " << ptr << endl;

    // allocate memory on the heap which delays allocation of memory until runtime
    // ptr2 points to a portion of memory on heap
    int * ptr2 = new int;
    // we will set the contents of ptr2 to val which is 5 thus storing the value on the heap
    *ptr2 = val;
    cout << "ptr2: " << ptr2 << ", *ptr2: " << *ptr2 << endl;

    // when you use new, always delete when finished with variable : essentially garbage collector for heap
    delete ptr2;

    // allocate memory on the heap
    ptr2 = new int[SIZE];
    for (int i = 0; i < SIZE; i++)
        ptr2[i] = i + 5;
    for (int i = 0; i < SIZE; i++)
        cout << ptr2[i] << " ";
    cout << endl;

    // deallocate memory associated with an array is a little different need ([])
    delete [] ptr2;

    return 0;
}
