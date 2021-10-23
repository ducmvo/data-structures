//
// Created by Duc Vo on 10/23/21.
//
#include "List.h"
#include <iostream>
using namespace std;

template <class T>
List<T>::List(int cap) {
    size = 0;
    capacity = cap;
    aPtr = new T[cap];
}

template <class T>
List<T>::~List() {
    delete [] aPtr;
}

template <class T>
void List<T>::insert(T val) {
    if (size < capacity)
        aPtr[size++] = val;
}

template <class T>
bool List<T>::contains(T val) {
    for (int i = 0; i < size; i++)
        if(aPtr[i] == val)
            return true;
    return false;
}