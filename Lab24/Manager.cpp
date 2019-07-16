#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include "Manager.h"

using namespace std;

Manager::Manager() : SalariedEmployee()
{}

Manager::Manager(string name, double salary, double bonus) : SalariedEmployee(name, salary)
{
    weekly_bonus = bonus;
}

double Manager::weekly_pay()
{
    return SalariedEmployee::weekly_pay() + weekly_bonus; 
}

string Manager::to_str()
{
    stringstream c = stringstream();
    c << "Employee's Name: " << get_name() << endl;
    c << "Weekly Pay: " << weekly_pay() << endl;
    c << "Weekly Bonus: " << weekly_bonus << endl;
    c << "Annual Salary: " << annual_salary << endl;

    return c.str();
}