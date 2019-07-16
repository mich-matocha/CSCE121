#include "Employee.h"
#include <stdio.h>
#include <sstream>
#include <string>
#include <iostream>
#include "SalariedEmployee.h"

using namespace std;

SalariedEmployee::SalariedEmployee() : Employee()
{
    annual_salary = 0;
}

SalariedEmployee::SalariedEmployee(string name, double salary) : Employee(name)
{
    set_name(name);
    annual_salary = salary;
}

double SalariedEmployee::get_salary()
{
    return annual_salary;
}

double SalariedEmployee::weekly_pay()
{
    double weekly_pay = annual_salary / 52;
    return weekly_pay;
}

string SalariedEmployee::to_str()
{
    stringstream c = stringstream();
    c << "Employee's Name: " << get_name() << endl;
    c << "Weekly Pay: " << weekly_pay() << endl;
    c << "Annual Salary: " << annual_salary << endl;

    return c.str();
}