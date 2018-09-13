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
