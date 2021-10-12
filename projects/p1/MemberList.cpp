//
// Created by Duc Vo on 10/12/21.
//

#include "MemberList.h"

MemberList::MemberList(int cap) {
    memberList = new Member[cap];
    capacity = cap;
    numMembers = 0;
}

MemberList::MemberList() {
    memberList = new Member[DEFAULT_CAPACITY];
    capacity = DEFAULT_CAPACITY;
    numMembers = 0;
}

MemberList::~MemberList() {
    delete [] memberList;
}

void MemberList::add(string name) {
    if (numMembers >= capacity) resize();
    Member member = {rand(), name};
    memberList[numMembers++] = member;
}

int* MemberList::get(int index) {
    return &memberList[index].account;
}

int MemberList::size() const {
    return numMembers;
}

string MemberList::to_string() const {
    string memberResult = "";
    for (int i = 0; i < size(); i++) {
        memberResult += (memberList[i].name  + " - ID: " +        
        ::to_string(memberList[i].account) + "\n");
    }
    return memberResult;
}

void MemberList::resize() {
    capacity *= 2;
    Member* tempList = new Member[capacity];
    for (int i = 0; i < numMembers; i++)
        tempList[i] = memberList[i];
    delete [] memberList;
    memberList = tempList;
}