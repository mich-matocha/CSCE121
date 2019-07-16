#ifndef HOURLY_EMPLOYEE
#define HOURLY_EMPLOYEE
#include <stdio.h>
#include <string>
#include "Employee.h"

class HourlyEmployee : public Employee {
    public:
    HourlyEmployee();
    HourlyEmployee(std::string name, double hourly_wage, double hours_worked);
    void set_hours_worked(double hours);
    double get_hours_worked();
    double weekly_pay();
    double get_hourly_wage();
    std::string to_str();

    private:
    double hourly_wage;
    double hours_worked;
};

#endif