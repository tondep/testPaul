#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Employee.h"
#include "BasePlusComission.h"
#include "Hourly.h"
#include "Fixed.h"

#include <iostream>
using std::cout;

#include <memory>
using std::shared_ptr;
using std::make_shared;
using std::unique_ptr;
using std::make_unique;

#include<vector>
using std::vector;

TEST_CASE("Employee has a base salary and additional comimmision")
{
    shared_ptr<BasePlusComission> first_base = make_shared<BasePlusComission> ("Tanaka", "Matare", 900, 15,30);
    CHECK(first_base->earnings()==1350);
}
TEST_CASE("Employee's salary change with changed comission per item")
{
    auto first_ptr = make_shared<BasePlusComission>("Walusungu", "Makuwa", 900, 15, 30);
    CHECK(first_ptr->earnings()==1350);
    
    first_ptr->comission(25);
    CHECK_FALSE(first_ptr->earnings()==1350);
    CHECK_EQ(first_ptr->earnings(),1650);
}
TEST_CASE("Employee's salary change with sold items per week")
{
    auto items_ptr= make_shared<BasePlusComission>("Matare", "Kuzivakwashe", 900, 25, 30);
    CHECK_EQ(items_ptr->earnings(),1650);
    
    items_ptr->items_weekly(50);
    CHECK_FALSE(items_ptr->earnings()== 1650);
    CHECK_EQ(2150,items_ptr->earnings());
}


double totalEarnings(vector<shared_ptr<Employee>>& employees)
{
    double totalEarnings=0.0;
    
/*    for(auto count =0; count < employees.size(); count++){
        totalEarnings += employees.at(count)->earnings();}*/
        for(auto  workers:employees)
           totalEarnings += workers->earnings();
    return totalEarnings;
}

TEST_CASE("Total earnings of the work force")
{
    vector<shared_ptr<Employee>> employees;
    shared_ptr<Employee>  worker1_ptr= make_unique<FixedRateWorker>("Matare","Tawanda", 2500);
    shared_ptr<Employee>  worker2_ptr= make_unique<HourlyWorker>("Mampimpi", "Makazola", 50, 38);
    shared_ptr<Employee>  worker3_ptr= make_unique<BasePlusComission>("Matare", "makanaka", 1000, 25, 30);
    employees.push_back(worker1_ptr);
    employees.push_back(worker2_ptr);
    employees.push_back(worker3_ptr);
    
    std::cout<< "total: "<<totalEarnings(employees)<< std::endl;
    CHECK_EQ(totalEarnings(employees), (2500+ (50*38)+(1000+(25*30))));
}

TEST_CASE("Total earnings of the work force with over time")
{
    vector<shared_ptr<Employee>> employees;
    shared_ptr<Employee>  worker1_ptr= make_unique<FixedRateWorker>("Matare","Tawanda", 2500);
    shared_ptr<Employee>  worker2_ptr= make_unique<HourlyWorker>("Mampimpi", "Makazola", 50, 48);
    shared_ptr<Employee>  worker3_ptr= make_unique<BasePlusComission>("Matare", "makanaka", 1000, 25, 30);
    employees.push_back(worker1_ptr);
    employees.push_back(worker2_ptr);
    employees.push_back(worker3_ptr);
    
    std::cout<< worker1_ptr->earnings()<< std::endl;
    std::cout<< worker2_ptr->earnings()<< std::endl;
    std::cout<< worker3_ptr->earnings()<< std::endl;
    
    CHECK_EQ(totalEarnings(employees), (2500+ ((50*40)+((48-40)*50*1.5)+(1750))));
}
