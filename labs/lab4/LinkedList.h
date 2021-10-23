//
// Created by Duc Vo on 10/23/21.
//

#ifndef PRACTICE_LINKEDLIST_H
#define PRACTICE_LINKEDLIST_H
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

template <typename T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void append(T);
    void insertNode(T);
    void deleteNode(T);
    string to_string() const;
    T getLastNegative();
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
    void getMinMax(T &, T &, Node *);
    T getLastNegative(T &, Node *);
};


template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node * curr;
    while (head != nullptr) {
        curr = head;
        head = head->next;
        delete curr;
    }
}

template <typename T>
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

template <typename T>
void LinkedList<T>::insertNode(T val) {
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

template <typename T>
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
            // only delete if val is in the list
            if (curr != nullptr) {
                prev->next = curr->next;
                delete curr;
            }
        }
    }
}

template <typename T>
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

template <typename T>
T LinkedList<T>::getLastNegative() {
    T lastNegative = 0; // return 0 if array have no negative number
    return getLastNegative(lastNegative, head);
}

template <typename T>
T LinkedList<T>::getLastNegative(T &lastNegative, Node* node) {
    if (node == nullptr) return lastNegative;
    if (node->data < 0) lastNegative = node->data;
    return getLastNegative(lastNegative, node->next);
}

#endif //PRACTICE_LINKEDLIST_H
