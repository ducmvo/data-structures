#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string filename;
	vector<int> v;
	vector<int>::iterator it;
	ifstream infile;
	int val;

	// ask filename
	cout << "Enter filename: ";
	cin >> filename;

	// open & read from file
	infile.open(filename);
	if (infile) {
		while(infile >> val)
			v.push_back(val);

		// print using array notation
		cout << "\nprint using array notation\n";
		for (unsigned i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;

		// print in reverse
		cout << "\nprint reverse\n";
		for (int i = v.size() - 1; i >= 0; i--)
			cout << v[i] << " ";
		cout << endl;

		// test vector functionality
		cout << "\nsize: " << v.size() << endl;
		cout << "first element: " << v[0] << endl;
		cout << "first element again: " << v.at(0) << endl;
		cout << "first element yet again: " << v.front() << endl;
		cout << "last element: " << v[v.size() - 1] << endl;
		cout << "last element again: " << v.at(v.size() - 1) << endl;
		cout << "last element yet again: " << v.back() << endl;

		// print with iterator
		cout << "\nprint with iterator\n";
		for (it = v.begin(); it < v.end(); it++)
			cout << *it << " ";
		cout << endl;

		// print in reverse with iterator
		cout << "\nprint reverse\n";   
		for (it = v.end() - 1; it >= v.begin(); it--)
			cout << *it << " "; 
		cout << endl;

		// sort and print
		cout << "\nsort vector\n";
		sort(v.begin(), v.end());
		for (int x : v)
			cout << x << " ";
		cout << endl;

		// find max element
		it = max_element(v.begin(), v.end());
		cout << "\nmax element: " << *it << endl;

		// find key
		cout << "\nfind elements:\n";
		for (unsigned i = 0; i < v.size(); i++) {
			it = find(v.begin(), v.end(), v[i]);
			if (it != v.end())
				cout << "value " << *it << " found at index "
					  << it - v.begin() << ".\n";
			else
				cout << "value " << v[i] << " not found.\n";		
		}

		// delete
		cout << "\ndeleting 13\n";
		v.erase(v.begin() + 3);
		for (int x : v)
			cout << x << " ";
		cout << endl;

	} else 
		cout << "Error opening file...\n";

	// close file
	infile.close();

	return 0;
}
