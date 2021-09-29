//
// Created by Duc Vo on 9/28/21.
//

#include "Date.h"
#include <iostream>
using namespace std;


const string Date::SPRING = "Spring";
const string Date::SUMMER = "Summer";
const string Date::FALL = "Fall";
const string Date::WINTER = "Winter";

Date::Date() {
    setDate(DEFAULT_YEAR, DEFAULT_MONTH, DEFAULT_DAY);
}

Date::Date(int year, int month, int day) {
    setDate(year, month, day);
}

void Date::setDate(int year, int month, int day) {
    if (validateDate(year, month, day)) {
        this->year = year;
        this->month = month;
        this->day = day;
    } else 
        setDate(DEFAULT_YEAR, DEFAULT_MONTH, DEFAULT_DAY);
}

string Date::getDate() const {
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}

string Date::getSeason() const {
//    First day of Winter: December 22
//    First day of Fall: September 23
//    First day of Summer: June 21
//    First day of Spring: March 21
    if (month == DEC && day >= FIRST_DAY_OF_WINTER)
        return WINTER;
    else if ((month > SEP)
        || (month == SEP && day >= FIRST_DAY_OF_FALL))
        return FALL;
    else if ((month > JUN)
        || (month == JUN && day >= FIRST_DAY_OF_SUMMER))
        return SUMMER;
    else if ((month > MAR)
        || (month == MAR && day >= FIRST_DAY_OF_SPRING))
        return SPRING;
    else return WINTER;
}

bool Date::validateDate(int year, int month, int day){
    if (
        (year < DEFAULT_YEAR) ||
       ( month < MIN_MONTH) || (month > MONTHS) ||
        (day < MIN_DAY) || (day > DAYS[month])
    ) return false;
    return true;
}
