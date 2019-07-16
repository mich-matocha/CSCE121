#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include "HourlyEmployee.h"

using namespace std;

HourlyEmployee::HourlyEmployee() : Employee()
{
    hourly_wage = 0;
}

HourlyEmployee::HourlyEmployee(string name, double hourlyWage, double hours) : Employee(name)
{
    set_name(name);
    hourly_wage = hourlyWage;
    set_hours_worked(hours);
}

void HourlyEmployee::set_hours_worked(double hours)
{
    hours_worked = hours;
}

double HourlyEmployee::get_hours_worked()
{
    return hours_worked;
}

double HourlyEmployee::get_hourly_wage()
{
    return hourly_wage;
}

double HourlyEmployee::weekly_pay()
{
    double payHours = hours_worked * hourly_wage;

    if (hours_worked > 40)
    {
        payHours += ((hours_worked - 40) * hourly_wage * 0.5);
    }

    return payHours;
}

string HourlyEmployee::to_str()
{
    stringstream c = stringstream();
    c << "Employee's Name: " << get_name() << endl;
    c << "Weekly Pay: " << weekly_pay() << endl;
    c << "Hours Worked: " << get_hours_worked() << endl;
    c << "Hourly Wage: " << get_hourly_wage() << endl;

    return c.str();
}
