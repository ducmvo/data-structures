// Sheila Oh
// File: IntList.h

/**
 * IntList Definition and Implementation
 * 3 files in this project:
 * 1. main.cpp - Entry point, where code begins execution when the program is run.
 * 2. IntList.h - Header (aka specification) file. Contains class definitions and functions.
 * 3. IntList.cpp - Class implementation file. Contains implementation of functions defined in header file.
 *
 * Goal- Create our own implementation of an Integer List
 * Future- We would just use C++ vectors which are the equivalent
 */


#ifndef WEEK1_INTLIST_H
#define WEEK1_INTLIST_H

#include <string>
using namespace std;

class IntList {
public:
    IntList(int);           // Constructor accepts initial capacity of list
    ~IntList();             // Destructor - Used to free up memory on heap

    //We will cover this in more detail next week!
    IntList(const IntList &);               // Copy constructor
    IntList& operator=(const IntList &);    // Overloaded = operator

    void add(int);          // add element to array
    int get(int) const;     // find element in array; return index
                            // where found or -1 if not found
    bool empty() const;     // determines if list is empty or not
    int size() const;       // number of elements in array
    string to_string() const;   // returns string representation of
                                // of the IntList class
private:
    int * list;             // Pointer to the array
    int capacity;           // capacity of array
    int numElements;        // Number of elements
    void resize();          // resize array (when full)
};

#endif //WEEK1_INTLIST_H
