// Member function definitions for abstract base class Employee.
// Note: No definitions given for pure virtual functions.
#include "employee.h"

Employee::Employee(const string& first_name, const string& surname):
	_first_name(first_name),
	_surname(surname)
{   
}

// Destructor - nothing to do
Employee::~Employee()
{
}

// Return a copy of the first name
string Employee::first_name() const 
{ 
   return _first_name; 
}

// Return a copy of the surname
string Employee::surname() const 
{ 
   return _surname; 
}

// Print the name of the Employee
void Employee::print() const
{ 
	cout << _first_name << ' ' << _surname; 
}


