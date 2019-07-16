#ifndef MANAGER_H
#define MANAGER_H

#include <stdio.h>
#include <string>
#include "SalariedEmployee.h"


class Manager : public SalariedEmployee {
    public:
    Manager();
    Manager(std::string name, double salary, double bonus);
    double weekly_pay();
    std::string to_str();

    private:
    double weekly_bonus;

};

#endif