#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
	string filename;
	vector<int> v;
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
		cout << "print using array notation\n";
		for (unsigned i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;

		// multiply by 2
		cout << "\nmultiply by 2\n";
		for (unsigned i = 0; i < v.size(); i++)
			v[i] *= 2;
		for (unsigned i = 0; i < v.size(); i++)
			cout << v[i] << " ";
        cout << endl;

		// range-based to multiply by 2
		cout << "\nmultiply by 2 again\n";
		for (int &x : v)
			x *= 2;
		for (int x : v)
			cout << x << " ";
        cout << endl;

	} else 
		cout << "Error opening file...\n";

	// close file
	infile.close();

	return 0;
}
