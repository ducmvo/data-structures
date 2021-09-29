//
// Created by Duc Vo on 9/28/21.
//

#ifndef ICE1_DATE_H
#define ICE1_DATE_H
#include <string>
using namespace std;

class Date {
public:
    Date();
    Date(int, int, int);

    void setDate(int, int, int);
    string getDate() const;
    string getSeason() const;

private:
    static const int DEFAULT_MONTH = 1;
    static const int DEFAULT_DAY = 1;
    static const int DEFAULT_YEAR = 1970; // default month, day, year

    static const int JAN = 1;
    static const int FEB = 2;
    static const int MAR = 3;
    static const int APR = 4;
    static const int MAY = 5;
    static const int JUN = 6;
    static const int JUL = 7;
    static const int AUG = 8;
    static const int SEP = 9;
    static const int OCT = 10;
    static const int NOV = 11;
    static const int DEC = 12; // numbers corresponding to months

    static const int MIN_DAY = 1; // smallest valid day value
    static const int MIN_MONTH = 1; // smallest valid  month value

    static const int FIRST_DAY_OF_SPRING = 21;
    static const int FIRST_DAY_OF_SUMMER = 21;
    static const int FIRST_DAY_OF_FALL = 23;
    static const int FIRST_DAY_OF_WINTER = 22; // first day of seasons

    static const string SPRING;
    static const string SUMMER;
    static const string FALL;
    static const string WINTER; // string seasons

    static const int MONTHS = 12; // number of months
    int DAYS[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // number of days in months

    int year;
    int month;
    int day;

    bool validateDate(int year, int month, int day);
};


#endif //ICE1_DATE_H
