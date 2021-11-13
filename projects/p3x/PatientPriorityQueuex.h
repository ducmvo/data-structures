//
// Created by Duc Vo on 11/7/21.
//

#ifndef P3_PATIENTPRIORITYQUEUEX_H
#define P3_PATIENTPRIORITYQUEUEX_H
#include "Patient.h"
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class PatientPriorityQueuex {
public:
    PatientPriorityQueuex();
    ~PatientPriorityQueuex();
    PatientPriorityQueuex(PatientPriorityQueuex &);  // Copy Constructor
    const PatientPriorityQueuex &operator=(PatientPriorityQueuex &);
                                // Overload = constructor

    int size();                 // Returns the number of patients still waiting.
    void add(string, int);      // Adds the patient to the priority queue.
    string change(int, int);    // Change a patient priority
    string peek();              // Returns the highest priority patient without removing it.
    string remove();            // Removes the highest priority patient from the queue and returns it. This function needs to maintain heap order.
    string to_string();         // Returns the string representation of the object in heap (or level) order.
                                // Use a ss object to capture the string traversal.
private:
    vector<Patient> patients;   // Store the patients in heap order
    int nextPatientNumber;      // Keep track of the last patient inserted into the heap, so that as patients arrive, they will get assigned proper arrivalOrder (start numbering at 1).

    void shiftUp(int);
    void shiftDown(int);
    void swap(int, int);
    void add(string, int, int);
    string remove(int);
    string getPriorityStatus(int);
};


// CONSTRUCTOR

PatientPriorityQueuex::PatientPriorityQueuex() {
    nextPatientNumber = 0;
}

PatientPriorityQueuex::~PatientPriorityQueuex() {
    patients.clear();
    nextPatientNumber = 0;
}

PatientPriorityQueuex::PatientPriorityQueuex(PatientPriorityQueuex &obj) {
    this->patients = obj.patients;
    this->nextPatientNumber = obj.nextPatientNumber;
}

const PatientPriorityQueuex
&PatientPriorityQueuex::operator=(PatientPriorityQueuex &obj) {
    this->patients = obj.patients;
    this->nextPatientNumber = obj.nextPatientNumber;
    return *this;
}

// PUBLIC METHODS

int PatientPriorityQueuex::size() {
    return patients.size();
}

string PatientPriorityQueuex::peek() {
    if (size() == 0) return "";
    return patients.front().to_string();
}

void PatientPriorityQueuex::add(string name, int priorityCode) {
    add(name, priorityCode, ++nextPatientNumber);
}

string PatientPriorityQueuex::change(int arrivalOrder, int priorityCode) {
    // look up patient index;
    int index = -1;
    for (vector<Patient>::iterator patientIt = patients.begin() ;
         patientIt != patients.end(); ++patientIt) {
        if (patientIt->getArrivalOrder() == arrivalOrder) {
            index = patientIt - patients.begin();
        }
    }
    // end if patient not found
    if(index == -1) {
        return "";
    }

    // create a copy of patient
    Patient patient(patients.at(index));

    // remove patient at index
    remove(index);

    // create and add a copied patient with new priority value
    // to the list and move to the correct position
    add(patient.getName(), priorityCode, patient.getArrivalOrder());

    return patient.to_string();
}

string PatientPriorityQueuex::remove() {
    return remove(0);
}

// PRIVATE METHODS

void PatientPriorityQueuex::add(string name, int priorityCode, int arrivalOrder)
{
    // create new patient;
    Patient patient(name, priorityCode, arrivalOrder);
    patients.push_back(patient);  // insert Patient at end of patients list
    shiftUp(size() - 1);    // move patient to correct position
}

string PatientPriorityQueuex::remove(int index) {
    if (size() == 0) return "";
    Patient patient = patients.at(index);
    // Swap index patient (to be removed) and last patient (the lowest priority)
    if (size() > 1) {
        swap(index, size() - 1);
    }
    // remove last patient (the highest priority just swapped)
    patients.pop_back();
    // Shift down first patient (the lowest priority just swapped)
    shiftDown(index);

    return patient.to_string();
}

void PatientPriorityQueuex::shiftUp(int index) {
    if (index <= 0) return;
    int parentIndex = (index - 1) / 2;
    if (patients.at(index) < patients.at(parentIndex)) {
        swap(index, parentIndex);
        shiftUp(parentIndex);
    }
}

void PatientPriorityQueuex::shiftDown(int index) {
    int leftChildIdx = 2 * index + 1;
    int rightChildIdx = 2 * index + 2;
    int swapIndex;

    // Find index of the patient with the higher priority next to index patient
    // higher priority means lower priorityCode
    if (rightChildIdx < size())
        swapIndex = patients.at(leftChildIdx) < patients.at(rightChildIdx)
                ? leftChildIdx : rightChildIdx;
    else if (leftChildIdx < size())
        swapIndex = leftChildIdx;
    else return;

    // swap patients based on priority
    if (patients.at(index) > patients.at(swapIndex)) {
        swap(index, swapIndex);
        shiftDown(swapIndex);
    }
}

void PatientPriorityQueuex::swap(int idx1, int idx2) {
    Patient temp(patients.at(idx1));
    patients.at(idx1) = patients.at(idx2);
    patients.at(idx2) = temp;
}

string PatientPriorityQueuex::to_string() {
    stringstream ss;
    string priorityStatus;
    for (vector<Patient>::iterator patientIt = patients.begin() ;
        patientIt != patients.end(); ++patientIt) {
        priorityStatus = getPriorityStatus(patientIt->getPriorityCode());
        ss
        << setw(7) << right << patientIt->getArrivalOrder()
        << setw(7) << left << " "
        << setw(16) << left << priorityStatus
        << patientIt->to_string()
        << endl;
    }
    return ss.str();
}

string PatientPriorityQueuex::getPriorityStatus(int priorityCode) {
    switch(priorityCode) {
        case 1: return "immediate";
        case 2: return "emergency";
        case 3: return "urgent";
        case 4: return "minimal";
        default: return "";
    }
}


#endif //P3_PATIENTPRIORITYQUEUEX_H
