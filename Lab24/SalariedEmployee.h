#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <stdio.h>
#include <string>
#include "Employee.h"

class SalariedEmployee: public Employee{
    public:
    SalariedEmployee();
    SalariedEmployee(std::string name, double annual_salary);
    virtual double weekly_pay();
    double get_salary();
    std::string to_str();

    protected:
    double annual_salary;

};

#endif