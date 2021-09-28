#include <iostream>
using namespace std;

void getOrder(int &);

int main() 
{
	int jellyDonuts;

	// C++ automatically stores the address 
	// of jellyDonuts in the parameter donuts
	getOrder(jellyDonuts);

	cout << "You asked for " << jellyDonuts << " donuts.\n";
}

void getOrder(int &donuts) {
	cout << "How many donuts do you want? ";
	cin >> donuts;
}
