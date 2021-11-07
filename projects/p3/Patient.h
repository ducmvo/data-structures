//
// Created by Duc Vo on 11/7/21.
//

#ifndef P3_PATIENT_H
#define P3_PATIENT_H
#include "PatientPriorityQueue.h"
#include <string>
using namespace std;

class Patient {
public:
    Patient();
    ~Patient();
    Patient(Patient &);                     // Copy Constructor
    const Patient &operator=(Patient &);    // Overload = constructor

    string to_string();     // String representation of the patient

private:
    string name;            // Patient's full name
    int priorityCode;       // Patient's assigned priority
    int arrivalOrder;       // Assigned arrival number
};
#endif //P3_PATIENT_H
