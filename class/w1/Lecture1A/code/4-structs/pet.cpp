#include <iostream>
using namespace std;

struct Pet {
  string name;
  int age;
  char type;
};

int main() {
  Pet myPet;
  cout << "Enter the name: ";
  getline(cin, myPet.name);
  cout << "Enter the age: ";
  cin >> myPet.age;
  cout << "Enter the type ('c' for cat, 'd' for dog, 'f' for fish): ";
  cin >> myPet.type;

  cout << "name: " << myPet.name << endl;
  cout << "age: " << myPet.age << endl;
  if (myPet.type == 'c')
    cout << "type: cat\n";
  else if (myPet.type == 'd')
    cout << "type: dog\n";
  else if (myPet.type == 'f')
    cout << "type: fish\n"; 
 
  return 0; 
}
