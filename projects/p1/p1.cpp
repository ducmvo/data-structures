#include <iostream>
#include "BookList.h"
#include "MemberList.h"
#include "RatingList.h"
using namespace std;

int login(int account, MemberList members) {
    return members.get(account);
}

void logout() {

}

void addMember() {

}

void addNewBook() {

}

void rateBook(int isbn, int account) {

}

void viewRatings(int account) {

}

void seeRecommendations(int account) {

}

void quitProgram() {

}

void displayMenu(bool isAuthenticated) {

}

void executeOption(string option, MemberList &members, BookList &bookList) {
    const string ADD_BOOK = '1';
    const string ADD_MEMBER = "2";
//    const string RATE_BOOK = "3";
//    const string VIEW_RATINGS = "4";
//    const string SEE_RECOMMENDATIONS = "5";
//    const string LOGIN = "6";
//    const string LOGOUT = "7";
//    const string QUIT = "8";

    switch (option) {
        case (ADD_BOOK):
            addNewBook();
            break;
        case (ADD_MEMBER):
            addMember();
            break;
        default: break;
    }
}

int main() {
    BookList books(100);
    MemberList members(100);
    RatingList ratings(100);
    string fileName;
    const string DEFAULT_BOOKS_FILE = "books.txt";
    const string DEFAULT_RATINGS_FILE = "ratings.txt";

    string option;
    cout << "Enter a menu option: ";
    getline(cin, option);
    executeOption(option, members, books);

    // display menu here

    // Load books from file
    if(books.load(DEFAULT_BOOKS_FILE)) {
        // Input book file path
        cout << "Enter books file: ";
        getline(cin, fileName);
        if(books.load(fileName)) {
            cout << "Failed to load file" << endl;
            return -1;
        };
    };

    // Load members and ratings from file
    if(ratings.load(DEFAULT_RATINGS_FILE, members, books)) {
        // Input book file path
        cout << "Enter ratings file: ";
        getline(cin, fileName);
        if(books.load(fileName)) {
            cout << "Failed to load file" << endl;
            return -1;
        };
    };

    // Log in user
    int userAccount = members.getAccount(5);
    int userIndex = login(userAccount, members);
    if  (userIndex != -1) {
        cout << "User found at userIndex: " << userIndex << endl;
    } else
        cout << "User not found!" << endl;




    // Print loaded books
    /*
    cout << "# of books: " + to_string(books.size()) << endl;
    cout << books.to_string() << endl << endl;
    cout << "# of members: " + to_string(members.size()) << endl;
    cout << members.to_string() << endl << endl;
    cout << "# of ratings: " + to_string(ratings.size()) << endl;
    */
    cout << ratings.to_string() << endl << endl;

    // Add a new book
    // books.add("Invest in crypto", "Duc Vo", "2021");
    return 0;
}