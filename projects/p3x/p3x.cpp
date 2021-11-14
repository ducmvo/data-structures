#include "PatientPriorityQueuex.h"
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;


void welcome();
// Prints welcome message.

void goodbye();
// Prints goodbye message.

void help();
// Prints help menu.

bool processLine(string, PatientPriorityQueuex &);
// Process the line entered from the user or read from the file.

void addPatientCmd(string, PatientPriorityQueuex &);
// Adds the patient to the waiting room.

void changePatientCmd(string, PatientPriorityQueuex &);
// Change the priority of the patient in the waiting room.

void peekNextCmd(PatientPriorityQueuex &);
// Displays the next patient in the waiting room that will be called.

void removePatientCmd(PatientPriorityQueuex &);
// Removes a patient from the waiting room and displays the name on the screen.

void showPatientListCmd(PatientPriorityQueuex &);
// Displays the list of patients in the waiting room.

void savePatientListCmd(string, PatientPriorityQueuex &);
// Save patient to database

void execCommandsFromFileCmd(string, PatientPriorityQueuex &);
// Reads a text file with each command on a separate line and executes the
// lines as if they were typed into the command prompt.

string delimitBySpace(string &);
// Delimits (by space) the string from user or file input.

string trim(const string&);

int getPriorityCode(string);
// translate priority input to priority code

int main() {
	// declare variables
	string line;

	// welcome message
	welcome();

	// process commands
	PatientPriorityQueuex priQueue;

	do {
		cout << "\ntriage> ";
		getline(cin, line);
	} while (processLine(line, priQueue));

	// goodbye message
	goodbye();
}

bool processLine(string line, PatientPriorityQueuex &priQueue) {
	// get command
	string cmd = delimitBySpace(line);
	if (cmd.length() == 0) {
		cout << "Error: no command given.\n";
		return false;
	}
	
	// process user input
	if (cmd == "help")
		help();
	else if (cmd == "add")
		addPatientCmd(line, priQueue);
    else if (cmd == "change")
        changePatientCmd(line, priQueue);
	else if (cmd == "peek")
		peekNextCmd(priQueue);
	else if (cmd == "next")
		removePatientCmd(priQueue);
	else if (cmd == "list")
		showPatientListCmd(priQueue);
    else if (cmd == "save")
        savePatientListCmd(line, priQueue);
	else if (cmd == "load")
		execCommandsFromFileCmd(line, priQueue);
	else if (cmd == "quit")
		return false;
	else
		cout << "Error: unrecognized command: " << cmd << endl;

	return true;
}

void addPatientCmd(string line, PatientPriorityQueuex &priQueue) {
	string priority, patientName;
    int priorityCode;

	// get priority and patient name
	priority = delimitBySpace(line);
	if (priority.length() == 0) {
		cout << "Error: no priority code given.\n";
		return;
	}
	patientName = line;
	if (patientName.length() == 0) {
		cout << "Error: no patient name given.\n";
		return;
	}

    patientName = trim(patientName);

    priorityCode = getPriorityCode(priority);
    if (priorityCode == -1) {
        cout << "Error: invalid priority level code.\n";
        return;
    }

    priQueue.add(patientName, priorityCode);
    cout << "Added patient \"" << patientName << "\" to the priority system."
    << endl;
}

void changePatientCmd(string line, PatientPriorityQueuex &priQueue) {
    string priority, arrival, patientName;
    int priorityCode, arrivalOrder;

    // get arrivalOrder number and priority
    arrival = delimitBySpace(line);
    if (arrival.length() == 0 || line == "change") {
        cout << "Error: No patient id provided.\n";
        return;
    }
    // convert (string) arrival to number
    try {
        arrivalOrder = stoi(arrival);
    } catch (const invalid_argument &ia) {
        cout << "Error: invalid arrival order number input.\n";
        return;
    }
    // trim spaces
    priority = trim(line);
    if (priority.length() == 0) {
        cout << "Error: No priority code given.\n";
        return;
    }

    priorityCode = getPriorityCode(priority);
    if (priorityCode == -1) {
        cout << "Error: invalid priority level code.\n";
        return;
    }

    patientName = priQueue.change(arrivalOrder, priorityCode);
    if (patientName == "") {
        cout << "Error: no patient with the given id was found.\n";
        return;
    }

    cout << "Changed patient \"" << patientName << "\"'s priority to "
    << priority << endl;

}

void peekNextCmd(PatientPriorityQueuex &priQueue) {
    if (priQueue.size() == 0)
        cout << "There are no patients in the waiting area." << endl;
    else
        cout << "Highest priority patient to be called next: "
        << priQueue.peek();
}

void removePatientCmd(PatientPriorityQueuex &priQueue) {
    if (priQueue.size() == 0)
        cout << "There are no patients in the waiting area." << endl;
    else
        cout << "This patient will now be seen: " << priQueue.remove() << endl;
}

void showPatientListCmd(PatientPriorityQueuex &priQueue) {
	cout << "# patients waiting: " << priQueue.size() << endl;
	cout << "  Arrival #   Priority Code   Patient Name\n"
		  << "+-----------+---------------+--------------+\n";
    cout << priQueue.to_string();
}

void savePatientListCmd(string line, PatientPriorityQueuex &priQueue) {
    int count;
    string fileName;

    // get saved filename
    fileName = delimitBySpace(line);
    if (fileName.length() == 0 || line == "save") {
        cout << "Error: No file name provided.\n";
        return;
    }

    count = priQueue.save(fileName);
    cout << "Saved " << count << " patients to file "<< fileName << endl;
}

void execCommandsFromFileCmd(string filename, PatientPriorityQueuex &priQueue) {
	ifstream infile;
	string line;

	// open and read from file
	infile.open(filename);
	if (infile) {
		while (getline(infile, line)) {
			cout << "\ntriage> " << line << endl;
			// process file input 
			processLine(line, priQueue);
		} 
	} else {
		cout << "Error: could not open file.\n";
	}
	// close file
	infile.close();
}

string delimitBySpace(string &s) {
	unsigned pos = 0;
	char delimiter = ' ';
	string result = ""; 

	pos = s.find(delimiter);
	if (pos != string::npos) {
		result = s.substr(0, pos);
		s.erase(0, pos + 1);
	}
	return result;
}

int getPriorityCode(string priority) {
    if (priority == "immediate"){
        return 1;
    } else if (priority == "emergency"){
        return 2;
    } else if (priority == "urgent"){
        return 3;
    } else if (priority == "minimal"){
        return 4;
    } else {
        return -1;
    }
}

void welcome() {
    cout << "            WELCOME TO TRIAGE EMERGENCY ROOM              " << endl
         << "==========================================================="<< endl;
}

void goodbye() {
	cout << "GOODBYE, THANK YOU FOR USING TRIAGE EMERGENCY ROOM PROGRAM" << endl
         << "==========================================================" << endl;
}	

void help() {
	cout
<< "add <priority-code> <patient-name>\n"
<< "            Adds the patient to the triage system.\n"
<< "change <arrival-id> <priority-code>\n"
<< "            Change an existing patient priority in the triage system.\n"
<< "            <priority-code> must be one of the 4 accepted priority codes:\n"
<< "                1. immediate 2. emergency 3. urgent 4. minimal\n"
<< "            <patient-name>: patient's full legal name (may contain spaces)\n"
<< "            <arrival-id>: patient's arrival number listed\n"
<< "next        Announces the patient to be seen next. Takes into account the\n"
<< "            type of emergency and the patient's arrival order.\n"
<< "peek        Displays the patient that is next in line, but keeps in queue\n"
<< "list        Displays the list of all patients that are still waiting\n"
<< "            in the order that they have arrived.\n"
<< "save        Save the list of all patients that are still waiting\n"
<< "            in the order that they have arrived.\n"
<< "load <file> Reads the file and executes the command on each line\n"
<< "help        Displays this menu\n"
<< "quit        Exits the program\n";
}

string trim(const string& line){
    const char* WhiteSpace = " \t\v\r\n";
    std::size_t start = line.find_first_not_of(WhiteSpace);
    std::size_t end = line.find_last_not_of(WhiteSpace);
    return start == end ? std::string() : line.substr(start, end - start + 1);
}