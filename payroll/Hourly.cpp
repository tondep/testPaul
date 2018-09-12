// Member function definitions for class HourlyWorker

#include "hourly.h"

// Constructor
HourlyWorker::HourlyWorker (const string& first_name, const string& surname,
							double wage, double weekly_hours)
							: Employee(first_name, surname),  // call base-class constructor
							  _wage(wage),
							  _weekly_hours(weekly_hours)
{}

void HourlyWorker::wage(double wage)
{
	_wage = wage;
}

void HourlyWorker::hours(double weekly_hours)
{
	_weekly_hours = weekly_hours;
}

// Get the HourlyWorker's pay
double HourlyWorker::earnings() const
{
   if ( _weekly_hours <= 40 ) // no overtime
      return _wage * _weekly_hours;
   else               // overtime is paid at wage * 1.5
      return 40 * _wage + (_weekly_hours - 40) * _wage * 1.5;
}

// Print the HourlyWorker's name
void HourlyWorker::print() const
{
   cout << "Hourly worker: ";
   // re-use Employee's print function (DRY principle)
   Employee::print();
}
