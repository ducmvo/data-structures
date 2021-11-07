//
// Created by Duc Vo on 11/7/21.
//

#ifndef P3_PATIENTPRIORITYQUEUE_H
#define P3_PATIENTPRIORITYQUEUE_H
#include "Patient.h"
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class PatientPriorityQueue {
public:
    PatientPriorityQueue();
    ~PatientPriorityQueue();
    PatientPriorityQueue(PatientPriorityQueue &);  // Copy Constructor
    const PatientPriorityQueue &operator=(PatientPriorityQueue &);  // Overload = constructor

    void add(Patient &);        // Adds the patient to the priority queue. Heap order is defined as the order that patients must be seen, so this function needs to maintain heap order.
    Patient peek();             // Returns the highest priority patient without removing it.
    Patient remove();           // Removes the highest priority patient from the queue and returns it. This function needs to maintain heap order.
    int size();                 // Returns the number of patients still waiting.
    string to_string();         // Returns the string representation of the object in heap (or level) order.
                                // Use a ss object to capture the string traversal.
private:
    vector<Patient> patients;   // Store the patients in heap order
    int nextPatientNumber;      // Keep track of the last patient inserted into the heap, so that as patients arrive, they will get assigned proper arrivalOrder (start numbering at 1).
};

#endif //P3_PATIENTPRIORITYQUEUE_H
