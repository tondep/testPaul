// Definition of class HourlyWorker
#ifndef HOURLY_H
#define HOURLY_H
#include "employee.h"

class HourlyWorker : public Employee {
public:
   HourlyWorker(const string& first_name, const string& surname, 
	   double wage = 0.0, double weekly_hours = 0.0);
  
   void wage( double );		// set the hourly wage
   void hours( double );	// set the number of hours worked
   
   virtual double earnings() const override;
   void print() const;

private:
   double _wage;   // wage per hour
   double _weekly_hours;  // hours worked for week
};

#endif
