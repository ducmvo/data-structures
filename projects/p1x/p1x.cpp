

#include <iostream>
#include <fstream>
#include "BookList.h"
#include "MemberList.h"
#include "RatingList.h"
using namespace std;
/**
 * This function extract current members, books, and ratings data to files
 * @param members MemberList instance
 * @param books BookList instance
 * @param ratings RatingList instance
 * @param BOOK_FILE default save book file name
 * @param RATING_FILE default save rating file name
 */
void save(MemberList& members, BookList &books, RatingList &ratings,
          string const BOOK_FILE, string const RATING_FILE) {
    bool isComplete = false; // true if book loaded once
    int ratingIndex;
    ofstream ratingFile, bookFile;
    ratingFile.open(RATING_FILE);
    bookFile.open(BOOK_FILE);
    for (int i = 0; i < members.size(); i++) {
        ratingFile << members.getName(i) << endl;
        for (int j = 0; j < books.size(); j++) {
            ratingIndex = ratings.get(books.getIsbn(j), members.getAccount(i));
            if (ratingIndex != -1)
                ratingFile << ratings.getRating(ratingIndex) << " ";
            if (!isComplete) {
                bookFile << books.getAuthor(j) << ","
                         << books.getTitle(j) << ","
                         << books.getYear(j) << endl;
            }
        }
        if (!isComplete) isComplete = true; // Books saved
        ratingFile << endl;

    }
    ratingFile.close();
    bookFile.close();
}

/**
 * This function log user in using their account number of the index number
 * @param account user account number
 * @param userIndex logged-in user index
 * @param isLoggedIn login status
 * @param members memberList instance
 */
void login(int &account, int &userIndex, bool &isLoggedIn, MemberList &members) {
    int loginOption;
    loginOption = 1; // Disable if using both INDEX and Account # to log in
    if (loginOption != 1) {
        cout << "************** LOGIN **************" << endl;
        string logInMenu =
                "* 1. Using Member Index           *\n"
                "* 2. Using Account Number         *\n";
        cout << logInMenu
             << "***********************************" << endl << endl;
        cout << "Enter a LOGIN option: ";
        cin >> loginOption;
    }
    switch (loginOption) {
        case 1: {
            cout << "Enter member account INDEX: ";
            cin >> userIndex;
            userIndex -= 1;
            account = members.getAccount(userIndex);
            break;
        }
        case 2: {
            cout << "Enter member account: ";
            cin >> account; // Need to know user account number to log in
            userIndex = members.get(account);
            break;
        }
        default: {
            cout << "Invalid input option!";
            return;
        }
    }

    if (userIndex >= 0) {
        cout << members.getName(userIndex) << ", you are logged in!" << endl;
        isLoggedIn = true;
    } else
        cout << "User account not found! " << endl;
}

/**
 * Change login status to false
 * @param isLoggedIn login status control
 */
void logout(bool &isLoggedIn) {
    isLoggedIn = false;
}
/**
 * This function will load members' ratings into a dynamic 2D-array structure
 * where each row index is user index, and each column number is book rating index
 * and column value is book rating value.
 * @param memberRatingList 2D-array member list of book ratings
 * @param members MemberList instance
 * @param books BookList instance
 * @param ratings RatingList instance
 */

void loadMemberList(int** &memberRatingList, MemberList &members, BookList &books, RatingList &ratings) {
    int memAccount, isbn, bookIndex;
    // Load member book ratings into client 2D array
    memberRatingList = new int*[members.size()];
    for (int i = 0; i < members.size(); i++) {
        memberRatingList[i] = new int[books.size()];
    }
    for (int memIndex = 0; memIndex < members.size(); memIndex++) {
        memAccount = members.getAccount(memIndex);
        for (int i = 0; i < ratings.size(); i++) {
            if (ratings.getAccount(i) == memAccount) {
                isbn = ratings.getIsbn(i);
                bookIndex = books.get(isbn);
                memberRatingList[memIndex][bookIndex] = ratings.getRating(i);
            }
        }
    }
}
/**
 * This function add a new member in to the member list and
 * create default ratings for all books;
 * @param members MemberList instance
 * @param ratings RatingList instance
 * @param books BookLost instance
 * @param memberRatingList 2D-array member list of book ratings
 */
void addMember(MemberList &members, RatingList &ratings, BookList &books, int** &memberRatingList) {
    string name;
    int account;
    cout << "Enter the name of the new member: ";
    cin.ignore();
    getline(cin, name);
    account = members.add(name);
    cout << name <<" (account #: " << account << ") was added.";

    // Add default ratings for all books for new members
    for (int i = 0; i < books.size(); i++)
        ratings.add(books.getIsbn(i), account, 0);
    // Reload member ratings list
    loadMemberList(memberRatingList, members, books, ratings);
}

/**
 * This function add a new book into the book list and
 * set create default rating for all members for this book
 * @param members MemberList instance
 * @param ratings RatingList instance
 * @param books BookList instance
 * @param memberRatingList 2D-array member list of book ratings
 */
void addBook(MemberList &members, BookList &books, RatingList &ratings, int** &memberRatingList) {
    string author, title, year;
    int isbn;
    cin.ignore();

    cout << "Enter the author of the new book: ";
    getline(cin, author);

    cout << "Enter the title of the new book: ";
    getline(cin, title);  // Lil BUB's Lil Book: The Extraordinary Life of the Most Amazing Cat on the Planet

    cout << "Enter the year (or range of years) of the new book: ";
    getline(cin, year);  // 2013

    isbn = books.add(author, title, year);
    cout << books.size() << ". "
         << author << ", "
         << title << ", "
         << year << " | ISBN: "
         << isbn << " was added." << endl;

    // create all members default ratings for new book
    for (int i = 0; i < members.size(); i++) {
        ratings.add(isbn, members.getAccount(i), 0);
    }
    // Reload member ratings list
    loadMemberList(memberRatingList, members, books, ratings);
}

/**
 * This function will update rating for a selected book provided
 * book index or ISBN and new rating
 * @param account user account number
 * @param userIndex logged-in user index
 * @param books BookList instance
 * @param ratings RatingList instance
 * @param memberRatingList 2D-array member list of book ratings
 */
void rateBook(int &account, int &userIndex, BookList &books, RatingList &ratings, int** &memberRatingList) {
    int ratingValues[] = {-5, -3, 0, 1, 3, 5};
    int isbn, rating, bookIndex, ratingIndex;
    string logInMenu;
    char reRate = 'y';
    bool isValid = false;
    cin.ignore();

    int ratingOption;
    ratingOption = 1; // Disable if using both INDEX or ISBN to rate book
    if (ratingOption != 1) {
        cout << "*********** RATE A BOOK ***********" << endl;
        logInMenu =
                "* 1. Using Book Index             *\n"
                "* 2. Using ISBN                   *\n";
        cout << logInMenu
             << "***********************************" << endl << endl;
        cout << "Enter a Book Rating option: ";
        cin >> ratingOption;
    }
    switch (ratingOption) {
        case 1: {
            cout << "Enter the INDEX for the book you'd like to rate: ";
            cin >> bookIndex;
            bookIndex -= 1;
            isbn = books.getIsbn(bookIndex);
            break;
        }
        case 2: {
            do {
                cout <<  "Enter the ISBN for the book you'd like to rate: ";
                cin >> isbn;
                bookIndex = books.get(isbn);
                if (bookIndex == -1)
                    cout << "ISBN input not valid! Enter 0 to exit" << endl;

            } while (bookIndex == -1 && isbn != 0);
            break;
        }
        default: {
            cout << "Invalid input option!";
            return;
        }
    }

    if (memberRatingList[userIndex][bookIndex] != 0) {
        cout << "Your current rating for " << std::to_string(bookIndex + 1) << ", "
             << books.getAuthor(bookIndex) << ", "
             << books.getTitle(bookIndex) << ", "
             << books.getYear(bookIndex) <<
             "| ISBN: "<< isbn <<
             " => rating: " << memberRatingList[userIndex][bookIndex] << endl;
        cout << "Would you like to re-rate this book (y/n)? ";
        cin >> reRate;
    }

    while (!isValid && isbn != 0 && reRate == 'y') {
        cout << "Enter your rating: ";
        cin >> rating;
        for (int i = 0; i < 6; i++)
            if (ratingValues[i] == rating)
                isValid = true;
        if (!isValid) cout << "Rating input not valid! Enter value -5, -3, 0, 1, 3, or 5." << endl;
    }

    if (!isValid || isbn == 0) return;

    ratingIndex = ratings.get(isbn, account);
    if (ratingIndex >= 0)
        ratings.update(ratingIndex, rating);

    cout << "Your new rating for "
         << bookIndex + 1 << ", "
         << books.getAuthor(bookIndex) << ", "
         << books.getTitle(bookIndex) << ", "
         << books.getYear(bookIndex) <<
         "| ISBN: "<< isbn <<
         " => rating: " << rating << endl;

    // Update member rating list
    memberRatingList[userIndex][bookIndex] = rating;
}

/**
 * This function display rating for all books for current logged-in user
 * @param userIndex logged-in user index
 * @param members MemberList instance
 * @param books BookList instance
 * @param memberRatingList 2D-array member list of book ratings
 */
void viewRatings(int &userIndex, MemberList &members, BookList &books, int** &memberRatingList) {
    int rating;
    string bookInfo;
    cout << members.getName(userIndex) << "'s ratings..." << endl;
    for (int bookIndex = 0; bookIndex < books.size(); bookIndex++) {
        rating = memberRatingList[userIndex][bookIndex];
        bookInfo = std::to_string(bookIndex + 1) + ", " + books.getAuthor(bookIndex) + ", "
                   + books.getTitle(bookIndex) + ", "
                   + books.getYear(bookIndex)
                   +  " | ISBN: " + std::to_string(books.getIsbn(bookIndex));
        cout << bookInfo << " => rating: " + std::to_string(rating) << endl;
    }
}

/**
 * This function using algorithm to suggest current logged-in user
 * with other members' books that have similar book ratings. The suggested
 * books are not rated by current user
 * @param userIndex logged-in user index
 * @param members MemberList instance
 * @param books BookList instance
 * @param ratings RatingList instance
 * @param memberRatingList 2D-array member list of book ratings
 */
void seeRecommendations(int &userIndex,
                        MemberList &members, BookList &books,
                        RatingList &ratings, int** &memberRatingList) {
    int rating;
    int sum = 0, max = sum, mostSimilarMemberIndex;
    string likedBooks, reallyLikedBooks, str;

    // Calculate the maximum similarity between all members and the logged-in user
    for (int i = 0; i < members.size(); i++) {
        if (i != userIndex) {
            for (int j = 0; j < books.size(); j++) {
                sum += memberRatingList[i][j] * memberRatingList[userIndex][j];
            }
            if (sum > max) {
                mostSimilarMemberIndex = i;
                max = sum;
            }
            sum = 0;
        }
    }

    for (int j = 0; j < books.size(); j++) {
        if (memberRatingList[userIndex][j] == 0) {
            rating = memberRatingList[mostSimilarMemberIndex][j];
            str = ::to_string(j + 1) + ", "
                  + books.getAuthor(j) + ", " + books.getTitle(j) + ", " + books.getYear(j) + "\n";
            if (rating == 5) reallyLikedBooks += str;
            if (rating == 3) likedBooks += str;
        }
    }

    cout << "You have similar taste in books as "
         << members.getName(mostSimilarMemberIndex)
         << endl << endl
         << "Here are the books "
         << members.getName(mostSimilarMemberIndex)
         << " REALLY liked: " << endl
         << "_________________________________________\n"
         << reallyLikedBooks << endl
         << "Here are the books "
         << members.getName(mostSimilarMemberIndex)
         << " liked: " << endl
         << "__________________________________________\n"
         << likedBooks << endl;
}

/**
 * This function stop the current program
 * @param isQuit quit status controller
 */
void quit(bool &isQuit) {
    cout << "Thank you for using the Book Recommendation Program!"
         << endl;
    isQuit = true;
}

/**
 * This function display different menu for user
 * based on their login status
 * @param isLoggedIn login status
 * @param option user menu choice
 */
void displayMenu(bool isLoggedIn, int &option) {
    cout << "************** MENU **************" << endl;
    string menu = "* 1. Add a new member            *\n"
                  "* 2. Add a new book              *\n";
    if (isLoggedIn) {
        menu += "* 3. Rate book                   *\n"
                "* 4. View ratings                *\n"
                "* 5. See recommendations         *\n"
                "* 6. Logout                      *\n";
    } else {
        menu += "* 3. Login                       *\n"
                "* 4. Quit                        *\n";
    }
    cout << menu;
    cout << "**********************************" << endl << endl;
    cout << "Enter a menu option: ";
    if (cin >> option) {
        cout << endl;
    } else {
        cout << "Invalid menu choice!" << endl;
        cin.clear();
        cin.ignore();
    }
}

/**
 * This function handle the execution when a menu option is selected
 * @param option user menu option choice
 * @param userAccount logged-in user account number
 * @param userIndex logged-in user index
 * @param isLoggedIn login status
 * @param isQuit quit status
 * @param members MemberList instance
 * @param books BookList instance
 * @param ratings RatingList instance
 * @param memberRatingList 2D-array member list of book ratings
 */
void optionHandler(int &option, int &userAccount, int &userIndex,
                   bool &isLoggedIn, bool &isQuit,
                   MemberList &members, BookList &books, RatingList &ratings,
                   int** &memberRatingList) {
    switch(option) {
        case 1: {
            addMember(members, ratings, books, memberRatingList);
            break;
        }
        case 2: {
            addBook(members, books, ratings, memberRatingList);
            break;
        }
        case 3: {
            if (!isLoggedIn) login(userAccount, userIndex, isLoggedIn, members);
            else rateBook(userAccount, userIndex, books, ratings, memberRatingList);
            break;
        }
        case 4: {
            if (!isLoggedIn) quit(isQuit);
            else viewRatings(userIndex, members, books, memberRatingList);
            break;
        }
        case 5: {
            if (isLoggedIn)
                seeRecommendations(userIndex,members, books, ratings, memberRatingList);
            break;
        }
        case 6: {
            if (isLoggedIn) logout(isLoggedIn);
            break;
        }
        default: break;
    }
}
/**
 * This program allow user to create account and login.
 * Users can view current books in the system.
 * They can add, rate a book or view their current ratings.
 * The program also suggest users with books they have not read
 * from other members that have similar ratings.
 * @authors Duc Vo
 */
int main() {
    const string DEFAULT_BOOKS_FILE = "books-updated.txt";
    const string DEFAULT_RATINGS_FILE = "ratings-updated.txt";
    int userAccount, userIndex, option; // Logged-in user info and user menu option choice
    bool isLoggedIn = false, isQuit = false; // login and quit status controller
    string fileName;    // File path
    BookList books;     // BookList instance
    MemberList members; // MemberList instance
    RatingList ratings; // RatingList instance
    int** memberRatingList = nullptr; // Client 2D array hold members' ratings

    // Load books from file
    if(books.load(DEFAULT_BOOKS_FILE)) {
        // Enter book file path if no default file found
        cout << "Enter books file: ";
        getline(cin, fileName);
        if(books.load(fileName)) {
            cout << "Failed to load file" << endl;
            return -1;
        };
        cout << "books loaded successfully." << endl;
    }

    // Load members and ratings from file
    if(ratings.load(DEFAULT_RATINGS_FILE, members, books)) {
        // Enter ratings file path if no default file found
        cout << "Enter ratings file: ";
        getline(cin, fileName);
        if(ratings.load(fileName, members, books)) {
            cout << "Failed to load file" << endl;
            return -1;
        }
        cout << "members and ratings loaded successfully." << endl;
    }

    cout << "# of books: " + to_string(books.size()) << endl;
    cout << "# of memberList: " + to_string(members.size()) << endl << endl;

    // Display Menu
    do {
        // Display menu and take user option input
        displayMenu(isLoggedIn, option);
        // Load client member list when user log in
        if (isLoggedIn && memberRatingList == nullptr)
            loadMemberList(memberRatingList,
                           members, books, ratings);
        // Execute user option input
        optionHandler(option, userAccount, userIndex,
                      isLoggedIn, isQuit,members,
                      books, ratings, memberRatingList);

        // Clear memberRatingList when log out or quit program
        if ((!isLoggedIn || isQuit) && memberRatingList != nullptr) {
            for (int i = 0; i < members.size(); i++) {
                delete [] memberRatingList[i];
            }
            delete [] memberRatingList;
            memberRatingList = nullptr;
        }
        cout << endl;
    } while (!isQuit);
    // Save updated data to files
    save(members, books, ratings, DEFAULT_BOOKS_FILE, DEFAULT_RATINGS_FILE);

    return 0;
}