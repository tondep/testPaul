// Using the Employee hierarchy - inheritance and polymorphism

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <iomanip>
using std::setiosflags;
using std::setprecision;
using std::ios;

#include <iostream>
using std::endl;
using std::cout;

#include "Employee.h"
#include "Fixed.h"
#include "Hourly.h"
#include "BasePlusComission.h"


int main()
{
	// set output formatting for floating point types
	cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);

	shared_ptr<FixedRateWorker> fixed_rate_ptr = make_shared<FixedRateWorker>("Ted", "Ramgasamy", 905.00);
	shared_ptr<HourlyWorker> hourly_ptr = make_shared<HourlyWorker>("Louisa", "Mahlungu", 12.00, 52);

	fixed_rate_ptr->print();										// static binding
	cout << " earned R " << fixed_rate_ptr->earnings() << endl;		// dynamic binding

	hourly_ptr->print();											// static binding
	cout << " earned R " << hourly_ptr->earnings() << endl;		// dynamic binding

	cout << endl;
	cout << "Why is the output below not identical to the output above ?" << endl;
	cout << endl;

	shared_ptr<Employee> employee1_ptr = make_shared<FixedRateWorker>("Ted", "Ramgasamy", 905.00);
	shared_ptr<Employee> employee2_ptr = make_shared<HourlyWorker>("Louisa", "Mahlungu", 12.00, 52);

	employee1_ptr->print();										// static binding
	cout << " earned R " << employee1_ptr->earnings() << endl;	// dynamic binding

	employee2_ptr->print();										// static binding
	cout << " earned R " << employee2_ptr->earnings() << endl;	// dynamic binding

	cout << endl;
    cout<< "Worker with base salary and comission"<< endl << endl;
    
    shared_ptr<BasePlusComission> base_comission_ptr1 = make_shared<BasePlusComission>("Paul", "Matare", 1050.00, 30.00, 20);
    shared_ptr<BasePlusComission> base_comission_ptr2 = make_shared<BasePlusComission>("Walusungu", "Makuwa", 950.00, 15.00, 50);
    
    base_comission_ptr1->print();
    cout<< " earned R "<< base_comission_ptr1->earnings()<< endl<< endl;
    
    base_comission_ptr2->print();
    cout<< " earned R "<<base_comission_ptr2->earnings()<< endl;
    cout<< endl;
    
    cout<< "Change the base salary "<< endl<< endl;
    
    base_comission_ptr1->base(500.00);
    base_comission_ptr2->base(500.00);
    
    base_comission_ptr1->print();
    cout<< " earned R "<< base_comission_ptr1->earnings()<< endl<< endl;
    
     base_comission_ptr2->print();
    cout<< " earned R "<< base_comission_ptr2->earnings()<< endl;

    cout<< endl;
    
    cout<< "Change the comission"<< endl<< endl;
    
    base_comission_ptr1->comission(50.00);
    base_comission_ptr2->comission(50.00);
    
    base_comission_ptr1->print();
    cout<< " earned R "<< base_comission_ptr1->earnings()<< endl<< endl;
    
    base_comission_ptr2->print();
    cout<< " earned R "<< base_comission_ptr2->earnings()<< endl<< endl;

    cout<< endl<<"Change the items sold weekly"<< endl<< endl;
    
    base_comission_ptr1->items_weekly(35);
    base_comission_ptr2->items_weekly(35);
    
    base_comission_ptr1->print();
    cout<< " earned R "<< base_comission_ptr1->earnings()<< endl<< endl;
    
    base_comission_ptr2->print();
    cout<< " earned R "<< base_comission_ptr2->earnings()<< endl<< endl;
	return 0;
}

