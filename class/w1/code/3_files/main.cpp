/**
 * File Reading and Writing (Relevant for Lab1: P1 file reading)
 * 3 files in this project:
 * 1. main.cpp - Entry point, where code begins execution when the program is run.
 * 2. names.txt - contains a list of numbers 1 on each line
 * 3. numbers.txt - contains a list of names one name per line
 */

//fstream: create files, write information to files, and read information from files
#include <fstream>
#include <iostream>
//string: needed for string types
#include <string>
using namespace std;

int main() {
    // declare variables
	int num;
	string name;
    //ifstream: input from a file that is to be read
    //Note: ofstream: writing out to a file
	ifstream inFile;

    // open and read from file (integers)
	cout << "reading numbers...\n";
	inFile.open("../3_files/numbers.txt");

    //This is used to test if file has been read
	if (inFile) {
        //(>>) is used to get each item in the file stored in inFile and delimit by space
		while (inFile >> num)
			cout << num << " ";
		cout << endl;
	} else {
		cout << "ERROR: cannot open file.\n";
	}
    //Any time you open a file you must clost it
	inFile.close();

    // now open and read from file (strings)
	cout << "\nreading names...\n";
	inFile.open("../3_files/names.txt");
	if (inFile) {
        //We want to specify that we want to delimit by line(getline)
		while (getline(inFile, name))
			cout << name << "\n";
		cout << endl;
	} else {
		cout << "ERROR: cannot open file.\n";
	}
	inFile.close();

	return 0;
}
