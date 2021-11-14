//
// Created by Duc Vo on 11/7/21.
//

#ifndef P3_PATIENT_H
#define P3_PATIENT_H
#include <string>
#include <sstream>
using namespace std;

class Patient {
public:
    Patient(string, int, int);
    ~Patient();
    Patient(const Patient &);                   // Copy Constructor
    const Patient &operator=(const Patient &);  // Overload = constructor

    bool operator<(const Patient &);            // Overload comparison operators
    bool operator>(const Patient &);            // to compare patient priority

    int getArrivalOrder();
    int getPriorityCode();
    string getName();
    string to_string();                  // String representation of the patient

private:
    string name;                         // Patient's full name
    int priorityCode;                    // Patient's assigned priority
    int arrivalOrder;                    // Assigned arrival number
};

Patient::Patient(string name, int priorityCode, int arrivalOrder) {
    this->name = name;
    this->priorityCode = priorityCode;
    this->arrivalOrder = arrivalOrder;
}

Patient::~Patient() { }

Patient::Patient(const Patient &obj) {
    this->name = obj.name;
    this->priorityCode = obj.priorityCode;
    this->arrivalOrder = obj.arrivalOrder;
}

const Patient &Patient::operator=(const Patient &obj) {
    this->name = obj.name;
    this->priorityCode = obj.priorityCode;
    this->arrivalOrder = obj.arrivalOrder;
    return *this;
}

bool Patient::operator<(const Patient &obj) {
    return this->priorityCode < obj.priorityCode ||
        (this->priorityCode == obj.priorityCode
        && this->arrivalOrder < obj.arrivalOrder);
}

bool Patient::operator>(const Patient &obj) {
    return !(*this < obj);
}

string Patient::to_string() {
    return getName();
}

int Patient::getArrivalOrder() {
    return arrivalOrder;
}

int Patient::getPriorityCode() {
    return priorityCode;
}

string Patient::getName() {
    return this->name;
}

#endif //P3_PATIENT_H
