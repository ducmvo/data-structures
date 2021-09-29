//
// Created by Duc Vo on 9/28/21.
//

#include "Date.h"
Date::Date() {

}
Date::Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

void Date::setDate(int year, int month, int day) {
    if (month <= 12 && month > 0 && day > 0 && year > 0) {
        this->year = year;
        this->month = month;
        this->day = day;
    }
}

string Date::getDate() const {
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}
//    First day of Winter: December 22
//    First day of Fall: September 23
//    First day of Summer: June 21
//    First day of Spring: March 21
string Date::getSeason() const {
    if (this->month == 12 && this->day >= 22)
        return "Winter";
    else if (this->month > 9 || this->month == 9 && this->day >= 23)
        return "Fall";
    else if (this->month > 6 || this->month == 6 && this->day >= 21)
        return "Summer";
    else if (this->month > 3 || this->month ==3 && this->day >= 21)
        return "Spring";
    else return "Winter";
};






