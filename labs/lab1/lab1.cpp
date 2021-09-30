#include <iostream>
#include <fstream>
using namespace std;
/**
 * This main method opens and read file contain
 * member, book info and book ratings of a book club,
 * then loads the info into dynamic arrays in memory.
 * @author Duc Vo
 * @version 1.0
 */
int main() {
    const string BOOK_FILE = "books.txt";
    const string RATING_FILE = "ratings.txt";
    const int CAPACITY = 100; // Initial array capacity
    int memberSize = 0; // total number of members read from file
    int bookSize = 0; // total number of books read from file
    // dynamically allocate memory
    string* members = new string[CAPACITY];
    int** ratings = new int*[CAPACITY];
    int rating; // member rating for single book
    string line; // single line read from file
    ifstream inputFile;

    // find total number of books reading from file
    inputFile.open(BOOK_FILE);
    if(inputFile.is_open())
        while (getline(inputFile, line)) bookSize++;
    else {
        cout << "Failed to open file " << BOOK_FILE << endl;
        return -1;
    }
    inputFile.close();

    // open and save member names and ratings to arrays
    inputFile.open(RATING_FILE);
    if(inputFile.is_open()) {
        for (int i = 1; getline(inputFile, line); i++) { // line start at 1
            if (i % 2 == 0) { // if line number is even, save current member's ratings
                ratings[i / 2 - 1] = new int[bookSize];
                for (int j = 0; j < bookSize; j++) {
                    rating = stoi(line.substr(0, line.find(" ")));
                    ratings[i / 2 - 1][j] = rating;
                    line = line.substr(line.find(" ") + 1, line.length());
                }
            } else // if line number is odd, save current member's name
                members[memberSize++] = line.substr(0, line.find(","));
        }
    } else {
        cout << "Failed to open file " << RATING_FILE << endl;
        return -1;
    }
    inputFile.close();

    // print member names and ratings
    for (int i = 0; i < memberSize; i++) {
        cout << members[i] << endl;
        for (int j = 0; j < bookSize; j++) {
            cout << ratings[i][j] << " ";
        }
        cout << endl;
    }

    // deallocate memory
    for (int i = 0; i < CAPACITY; i++)
        delete [] ratings[i];
    delete [] ratings;
    delete [] members;

    return 0;
}

