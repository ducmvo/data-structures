// Sheila Oh
// File: IntList.cpp
// Goal of this to create our own Integer List

#include "IntList.h"
#include <sstream>

//Default Constructor
//Accepts capacity and creates new list on heap
IntList::IntList(int cap) {
    list = new int[cap];
    capacity = cap;
    numElements = 0;
}

// Destructor - called automatically at end of program by compiler to free up memory on heap
IntList::~IntList() {
    delete [] list;
}

//We will go over next week!
IntList::IntList(const IntList &obj) {
    // assign numElements and capacity (from obj)
    capacity = obj.capacity;
    numElements = obj.numElements;

    // allocate memory based on new capacity
    list = new int[capacity];

    // copy over elements (from obj)
    for (int i = 0; i < numElements; i++)
        list[i] = obj.list[i];
}

//We will go over next week!
// x = y is the same as x.operator = y 
// basically overide the = operator
IntList& IntList::operator=(const IntList &obj) {
    // check if you're assigning an object to itself
    if (this != &obj) {

        // deallocate memory
        delete [] this->list;

        // assign numElements and capacity (from obj)
        this->capacity = obj.capacity;
        this->numElements = obj.numElements;

        // allocate memory based on new capacity
        this->list = new int[this->capacity];

        // copy over elements (from obj)
        for (int i = 0; i < this->numElements; i++)
            this->list[i] = obj.list[i];
    }
    // return object
    return *this;
}

void IntList::add(int el) {
    // Check that we haven't reached capacity
    if (numElements >= capacity)
        resize();

    // Use numElements to access next free space in list
    list[numElements] = el;
    numElements++;
}

int IntList::get(int el) const {
    //Linear search looking for element el
    for (int i = 0; i < numElements; i++) {
        if (list[i] == el)
            return i;
    }
    return -1;
}

bool IntList::empty() const {
    return numElements == 0;
}

int IntList::size() const {
    return numElements;
}

//We will go over next week!
string IntList::to_string() const {
    stringstream ss;
    for (int i = 0; i < numElements; i++)
        ss << list[i];
    return ss.str();
}

void IntList::resize() {
    // update capacity to twice its current size
    capacity *= 2;

    // create new array based on updated capacity
    int * tempArr = new int[capacity];

    // copy old array values to new array
    for (int i = 0; i < numElements; i++)
        tempArr[i] = list[i];

    // delete old array
    delete [] list;

    // reassign old array to new array
    list = tempArr;
}