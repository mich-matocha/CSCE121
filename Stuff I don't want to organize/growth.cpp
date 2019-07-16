#include <iostream>
#include <string>
using namespace std;

int main()
{
int currentYear = 2018;
cout << "First name: ";
string firstName;
cin >> firstName;

cout << "Last name: ";
string lastName;
cin >> lastName;

cout << "Birth year: ";
int birthYear;
cin >> birthYear;

cout << "Height in feet (do not include inches): ";
int heightFeet;
cin >> heightFeet;

cout << "Height in inches (do not include feet): ";
int heightInch;
cin >> heightInch;

int age = currentYear - birthYear;
double heightCent = heightFeet * 12 * 2.54 + heightInch * 2.54;
double avgGrowth = (heightCent - 51) / age;

cout << "Hello " << firstName << " " << lastName << "." << endl;
cout << "You are " << age << " years old in " << currentYear << "." << endl;
cout << "Your height is " << heightCent << " cm." << endl;
cout << "You grew an average of " << avgGrowth << " cm per year (assuming you were 51 cm at birth)." << endl;
}