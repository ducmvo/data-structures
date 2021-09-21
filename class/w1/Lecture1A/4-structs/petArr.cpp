#include <iostream>
using namespace std;

struct Pet {
  string name;
  int age;
  char type;
};

int main() {
  const int SIZE = 5;
  Pet myPets[SIZE];
  char repeat = 'y';
  int count = 0;  

  while (repeat == 'y' && count < SIZE) {
    cout << "\nWould you like to enter a pet (y/n)? ";
    cin >> repeat;
    cin.ignore();
    if (repeat == 'y') {
      cout << "Enter the name: ";
      getline(cin, myPets[count].name);
      cout << "Enter the age: ";
      cin >> myPets[count].age;
      cout << "Enter the type ('c' for cat, 'd' for dog, 'f' for fish): ";
      cin >> myPets[count].type;
      count++;
    }
  }

  cout << "\nHere are your pets...\n";
  for (int i = 0; i < count; i++) {
    cout << "name: " << myPets[i].name << ", ";
    cout << "age: " << myPets[i].age << ", ";
    if (myPets[i].type == 'c')
      cout << "type: cat\n";
    else if (myPets[i].type == 'd')
      cout << "type: dog\n";
    else if (myPets[i].type == 'f')
      cout << "type: fish\n"; 
  }
  cout << endl;

  return 0; 
}
