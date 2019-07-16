#include <stdio.h>
#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

Employee::Employee()
{
    name = "";
}

Employee::Employee(string n)
{
    name = n;
}

void Employee::set_name(string newName)
{
    name = newName;
}

string Employee::get_name()
{
    return name;
}
