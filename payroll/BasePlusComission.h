// Abstract base class BasePlusComission
#ifndef BASEPLUSCOMISSION_H
#define BASEPLUSCOMISSION_H
#include "Employee.h"
#include <iostream>
using std::cout;
using std::endl;

class BasePlusComission : public Employee
{
public:
    BasePlusComission(const string& first_name, const string& surname, 
	   double base = 0.0, double comission= 0.0,  int items_weekly = 0);
       
       void base(double);
       void items_weekly(int);
       void comission(double);
       //member function from the super class.
        virtual double earnings() const override;
        void print() const;
    
private:
    double _comission;
    double _base;
    int _items_weekly;
};
#endif
