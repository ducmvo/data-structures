//
// Created by Duc Vo on 10/23/21.
//
#include "LinkedList.h"
#include <iostream>
#include <sstream>
using namespace std;

template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {
    Node * curr;
    while (head != nullptr) {
        curr = head;
        head = head->next;
        delete curr;
    }
}

template <class T>
void LinkedList<T>::append(T val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    Node* curr = head;
    if (head == nullptr) {
        head = newNode;
    } else {
        while (curr->next != nullptr)
            curr = curr->next;
        curr->next = newNode ;
    }
}

template <class T>
void LinkedList<T>::insert(T val) {
    Node * curr;
    Node * prev;
    Node * newNode = new Node;
    newNode->data = val;

    if (head == nullptr) {
        head = newNode;
        newNode->next = nullptr;
    } else {
        prev = nullptr;
        curr = head;
        while (curr != nullptr && curr->data < val) {
            prev = curr;
            curr = curr->next;
        }
        // add to beginning of list; otherwise, end or between nodes
        if (prev == nullptr) {
            head = newNode;
            newNode->next = curr;
        } else {
            prev->next = newNode;
            newNode->next = curr;
        }
    }
}

template <class T>
void LinkedList<T>::deleteNode(T val) {
    Node * curr;
    Node * prev;
    if (head != nullptr) {
        if (head->data == val) {
            curr = head;
            head = head->next;
            delete curr;
        } else {
            curr = head;
            while (curr != nullptr && curr->data != val) {
                prev = curr;
                curr = curr->next;
            }
            // only delete if d is in the list
            if (curr != nullptr) {
                prev->next = curr->next;
                delete curr;
            }
        }
    }
}

template <class T>
string LinkedList<T>::to_string() const {
    stringstream ss;
    Node * curr = head;
    while (curr != nullptr) {
        ss << curr->data << " ";
        curr = curr->next;
    }
    ss << "\n";
    return ss.str();
}

template <class T>
void LinkedList<T>::getMinMax(T &min, T &max) {
    if (head == nullptr) return;
    min = head->data;
    max = head->data;
    getMinMax(min, max, head->next);
}

template <class T>
void LinkedList<T>::getMinMax(T &min, T &max, Node* node) {
    if (node == nullptr) return;
    if (min > node->data) min = node->data;
    if (max < node->data) max = node->data;
    getMinMax(min, max, node->next);
}


template <class T>
T LinkedList<T>::getLastNegative() {
    T lastNegative = 0; // return 0 if array have no negative number
    return getLastNegative(lastNegative, head);
}

template <class T>
T LinkedList<T>::getLastNegative(T &lastNegative, Node* node) {
    if (node == nullptr) return lastNegative;
    if (node->data < 0) lastNegative = node->data;
    return getLastNegative(lastNegative, node->next);
}






