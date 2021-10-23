//
// Created by Duc Vo on 10/23/21.
//

#ifndef PRACTICE_LINKEDLIST_H
#define PRACTICE_LINKEDLIST_H
#include <string>
using namespace std;

template <class T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void append(T);
    void insert(T);
    void deleteNode(T);
    string to_string() const;
    void getMinMax(T &, T &);
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


#endif //PRACTICE_LINKEDLIST_H
