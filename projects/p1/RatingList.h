/**
 * Created on 10/12/21.
 * @author Duc Vo
 */
#ifndef P1_RATINGLIST_H
#define P1_RATINGLIST_H
#include "MemberList.h"
#include "BookList.h"
#include <string>
using namespace std;
class RatingList {
public:
    RatingList(int);                            // Constructor
    RatingList();                               // Empty constructor
    ~RatingList();                              // Destructor

    int add(int, int, int);                     // add a rating to array, return index
    int update(int, int);                       // update current rating with new rating
    int size() const;                           // number of ratings in array
    int get(int, int);                          // get index from book isbn and member account
    int getAccount(int index);                  // get member account from rating index
    int getIsbn(int index);                     // get book isbn from rating index
    int getRating(int index);                   // get rating from rating index
    string to_string() const;                   // return string representation of RatingList class
    int load(string, MemberList &, BookList &); // load ratings from file
private:
    struct Rating {
        int isbn;
        int account;
        int rating;
    };
    static const int DEFAULT_CAPACITY = 1100;
    Rating* ratingList;                         // pointer to ratings array
    int capacity;                               // array capacity
    int numRatings;                             // number of ratings
    void resize();                              // resize array when full
};


#endif //P1_RATINGLIST_H
