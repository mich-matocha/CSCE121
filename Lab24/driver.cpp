#include <stdio.h>
#include <vector>
#include <iostream>
#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "Manager.h"

using namespace std;

ostream& operator<<(ostream& os, Employee& e)
{
    os << e.to_str();
    return os;
}

int main() {
    vector <Employee*> e;
    e.push_back(new HourlyEmployee("Aramis",25.0,45.0));
    e.push_back(new SalariedEmployee("Porthos", 100000));
    e.push_back(new Manager("Athos",120000,500));

    for(int i = 0; i<e.size(); i++)
    {
        cout << e.at(i) << endl;
    }
}