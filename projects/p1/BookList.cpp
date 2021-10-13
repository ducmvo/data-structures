//
// Created by Duc Vo on 10/12/21.
//

#include "BookList.h"
#include <iostream>
#include <fstream>
#include <sstream>

BookList::BookList(int cap) {
    bookList = new Book[cap];
    capacity = cap;
    numBooks = 0;
}

BookList::BookList() {
    bookList = new Book[DEFAULT_CAPACITY];
    capacity = DEFAULT_CAPACITY;
    numBooks = 0;
}

BookList::~BookList() {
    delete [] bookList;
}

void BookList::add(string author, string title, string year) {
    if (numBooks >= capacity) resize();
    Book book = {rand(), author, title, year};
    bookList[numBooks++] = book;
}

int BookList::get(int isbn) {
    for (int i = 0; i < size(); i++) {
        if (bookList[i].isbn == isbn)
            return i;
    }
    return -1;
}

int BookList::getIsbn(int index) {
    if (0 <= index && index < size()) {
        return bookList[index].isbn;
    }
    return -1;
}

int BookList::size() const {
    return numBooks;
}

string BookList::to_string() const {
    string bookResult = "";
    for (int i = 0; i < numBooks; i++) {
        bookResult += (::to_string(i + 1) + ". " +
                bookList[i].author + ", " +
                bookList[i].title + ", " +
                bookList[i].year + "\n");
    }
    return bookResult;
}

void BookList::resize() {
    capacity *= 2;
    Book* tempList = new Book[capacity];
    for (int i = 0; i < numBooks; i++)
        tempList[i] = bookList[i];
    delete [] bookList;
    bookList = tempList;
}

int BookList::load(string file) {
    string line; // single line read from file
    ifstream inputFile;

    inputFile.open(file);
    if(inputFile.is_open()) {
        while(getline(inputFile, line)) {
            Book book;
            stringstream lineStream(line);
            for (int i = 0; getline(lineStream, line, ','); i++) {
                if (i==0) book.author = line;
                if (i==1) book.title = line;
                if (i==2) book.year = line;
            }
            add(book.author, book.title, book.year);
        }
        inputFile.close();
        return 0;
    }
    inputFile.close();
    return -1;
}