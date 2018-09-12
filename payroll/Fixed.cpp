// Member function definitions for class FixedRateWorker

#include "fixed.h"

// Constructor
FixedRateWorker::FixedRateWorker(const string& first_name, const string& surname, double weekly_salary)
   : Employee(first_name, surname),  // call base-class constructor
	 _weekly_salary(weekly_salary)	 
{}   
	 

   
void FixedRateWorker::salary(double weekly_salary)	// set weekly salary
{
	_weekly_salary = weekly_salary;
}

// Get the FixedRateWorker's pay
double FixedRateWorker::earnings() const { return _weekly_salary; }

// Print the FixedRateWorker's name 
void FixedRateWorker::print() const
{
   cout << "FixedRateWorker: ";
   // re-use Employee's print function (DRY principle)
   Employee::print();
}
