/**
 * Created on 10/12/21.
 * @author Duc Vo
 */

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

int MemberList::add(string name) {
    if (numMembers >= capacity) resize();
    Member member = {rand(), name};
    memberList[numMembers++] = member;
    return member.account;
}

int MemberList::get(int account) {
    for (int i = 0; i < size(); i++) {
        if (memberList[i].account == account)
            return i;
    }
    return -1;
}

int MemberList::getAccount(int index) {
    if (0 <= index && index < size()) {
        return memberList[index].account;
    }
    return -1;
}

string MemberList::getName(int index) {
    if (0 <= index && index < size()) {
        return memberList[index].name;
    }
    return "";
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