#include <iostream>
using namespace std;

int main() {
  string name, city, name2;
  int age;

  cout << "Enter your name: ";
  getline(cin, name);
  cout << "Enter your age: ";
  cin >> age;
  cout << "Enter your city: ";
  cin.ignore();
  getline(cin, city);

  cout << "Name: " << name << endl;
  cout << "Age: " << age << endl;
  cout << "City: " << city << endl;

  // getline(cin, name); // include space
  cin >> name >> name2; // separated by space
  cout << name + " -- " + name2 << endl;
  
  return 0;
}
