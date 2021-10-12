//
// Created by Duc Vo on 10/12/21.
//

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

void RatingList::add(int* book, int* memberAccount, int memberRating) {
    if (numRatings >= capacity) resize();
    Rating rating = {book, memberAccount, memberRating};
    ratingList[numRatings++] = rating;
}

int RatingList::size() const {
    return numRatings;
}

string RatingList::to_string() const {
    string ratingResult = "";
    for (int i = 0; i < size(); i++) {
        ratingResult += (::to_string(i + 1) + ". " +
                ::to_string(*ratingList[i].book) + ", " +
                ::to_string(*ratingList[i].account) + ", " +
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
    int* account;
    int *book;
    inputFile.open(file);
    if(inputFile.is_open()) {
        while(getline(inputFile, line)) {
            members.add(line);
            getline(inputFile, line2);
            ss.str(line2);
            account = members.get(memberSize);
            for (int j = 0; j < books.size(); j++) {
                ss >> rating;
                if (rating != 0) {
                    book = books.get(j);
                    add(book, account, rating);
                }
            } 
            memberSize++; 
        }
    } else {
        // cout << "Failed to open file " << file << endl;
        return -1;
    }
    inputFile.close();
    return 0;
}