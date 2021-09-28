/**
 * Example: Struct and Struct Arrays
 */

// iostream is used to include cout, cin, etc...
// #include tells preprocessor to include these header files
#include <iostream>
using namespace std;

/**
 * A user defined structure to represent a Rectangle
 */
struct Rectangle {
	double width;
	double length;
};

/**
 * Special function called when the program is run
 * @return Exit code for the process. 0 indicates normal execution (ie no errors)
 */
int main() {
	const int SIZE = 3;
    // Declare a single Rectangle struct
	Rectangle r;
    // Declare a Rectangle struct array of size 3
    //ie, (rectArr = [Rectangle], [Rectangle], [Rectangle])
	Rectangle rectArr[SIZE];

	// set width and length using dot(.) operator
	r.width = 5;
	r.length = 7;

	// calculate area
	cout << "area: " << r.width * r.length << endl;

	// populate rectArray
	for (int i = 0; i < SIZE; i++) {
		rectArr[i].width = i + 1;
		rectArr[i].length = i + 3;
	}

	// print array contents
	for (int i = 0; i < SIZE; i++) {
		cout << "area of rectangle " << i + 1 << ": "
			  << rectArr[i].width * rectArr[i].length << endl;
	}

	return 0;
}
