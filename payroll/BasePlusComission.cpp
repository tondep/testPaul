#include "BasePlusComission.h"


BasePlusComission::BasePlusComission(const string& first_name, const string& surname,
                                        double base, double comission, int itemsSold ):
                                        Employee(first_name, surname),
                                        _base{base}, _comission{comission}, _items_weekly{itemsSold}
{}

void BasePlusComission::base(double base)
{
    _base= base;
}

void BasePlusComission::comission(double comission)
{
    _comission=comission;
}

void BasePlusComission::items_weekly(int itemsSoldWeekly)
{
    _items_weekly = itemsSoldWeekly;
}

double BasePlusComission::earnings() const
{ 
    return _base + _comission*_items_weekly;
}
void BasePlusComission::print() const
{
    cout<< "Base plus comission: "<< endl;
    Employee::print();
}