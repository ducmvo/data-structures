/**
 * Created on 10/12/21.
 * @author Duc Vo
 */

#include "RatingList.h"
#include <iostream>
#include <fstream>
#include <sstream>

RatingList::RatingList(int cap) {
    ratingList = new Rating[cap];
    capacity = cap;
    numRatings = 0;
}

RatingList::RatingList() {
    ratingList = new Rating[DEFAULT_CAPACITY];
    capacity = DEFAULT_CAPACITY;
    numRatings = 0;
}

RatingList::~RatingList() {
    delete [] ratingList;
}

int RatingList::add(int isbn, int account, int memberRating) {
    if (numRatings >= capacity) resize();
    Rating rating = {isbn, account, memberRating};
    ratingList[numRatings++] = rating;
    return numRatings - 1;
}

int RatingList::update(int index, int rating) {
    ratingList[index].rating = rating;
    return numRatings - 1;
}

int RatingList::get(int isbn, int account) {
    for (int i = 0; i < size(); i++) {
        if (ratingList[i].isbn == isbn && ratingList[i].account == account )
            return i;
    }
    return -1;
}

int RatingList::getAccount(int index) {
    if (0 <= index && index < numRatings)
        return ratingList[index].account;
    return -1;
}

int RatingList::getRating(int index) {
    if (0 <= index && index < numRatings)
        return ratingList[index].rating;
    return -1;
}

int RatingList::getIsbn(int index) {
    if (0 <= index && index < numRatings)
        return ratingList[index].isbn;
    return -1;
}

int RatingList::size() const {
    return numRatings;
}

string RatingList::to_string() const {
    string ratingResult = "";
    for (int i = 0; i < size(); i++) {
        ratingResult += (::to_string(i + 1) + ". " +
                ::to_string(ratingList[i].isbn) + ", " +
                ::to_string(ratingList[i].account) + ", " +
                ::to_string(ratingList[i].rating) + "\n");
    }
    return ratingResult;
}

void RatingList::resize() {
    capacity *= 2;
    Rating* tempList = new Rating[capacity];
    for (int i = 0; i < numRatings; i++)
        tempList[i] = ratingList[i];
    delete [] ratingList;
    ratingList = tempList;
}

int RatingList::load(string file, MemberList &members, BookList &books) {
    string line; // single line read from file
    string line2; // single line read from file
    ifstream inputFile;
    stringstream ss;
    int rating; // member rating for single book
    int memberSize = 0; // total number of members read from file
    int isbn; // book ISBN
    int account; // user account number
    inputFile.open(file);
    if(inputFile.is_open()) {
        while(getline(inputFile, line)) {
            members.add(line);
            getline(inputFile, line2);
            ss.str(line2);
            for (int bookIndex = 0; bookIndex < books.size(); bookIndex++) {
                ss >> rating;
                isbn = books.getIsbn(bookIndex);
                account = members.getAccount(memberSize);
                add(isbn, account, rating);
            } 
            memberSize++; 
        }
    } else {
        return -1;
    }
    inputFile.close();
    return 0;
}