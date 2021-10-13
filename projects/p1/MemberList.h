//
// Created by Duc Vo on 10/12/21.
//

#ifndef P1_MEMBERLIST_H
#define P1_MEMBERLIST_H
#include <string>
using namespace std;

class MemberList {
public:
    MemberList(int);              // Constructor
    MemberList();                 // Empty constructor
    ~MemberList();                // Destructor

    int add(string);            // add a member to array return member account number
    int get(int account);       // return index of member in the list from account number
    int getAccount(int index);  // return member account number
    int size() const;           // number of members in array
    string to_string() const;   // return string representation
                                // of MemberList class
private:
    struct Member {
        int account;
        string name;
    };
    static const int DEFAULT_CAPACITY = 100;
    Member* memberList;             // pointer to members array
    int capacity;               // array capacity
    int numMembers;               // number of members
    void resize();              // resize array when full

};

#endif //P1_MEMBERLIST_H
