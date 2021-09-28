#include <iostream>
using namespace std;


struct Student
{
  int suid;
  string name;
  int credits;
  double gpa;
};

void getData(Student *);

int main()
{
  Student s;
  getData(&s);

  cout << "\nStudent info...\n";
  cout << "SUID: " << s.suid << endl;
  cout << "Name: " << s.name << endl;
  cout << "Credits: " << s.credits << endl;
  cout << "GPA: " << s.gpa << endl; 
}

void getData(Student *s)
{
  cout << "SUID: ";
  //cin >> (*s).suid;
  cin >> s->suid;
  cin.ignore();

  cout << "Name: ";
  getline(cin, s->name);
  
  cout << "Credits: ";
  cin >> s->credits;

  cout << "GPA: ";
  cin >> s->gpa;
}


