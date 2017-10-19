#include "Item.h"
#include <iostream>


Item::Item(string name, int age, int idNumber)
{
	this->name = name;
	this->age  = age;
	this->idNumber = idNumber;
}

Item::~Item()
{
}

ostream& operator<<(ostream& out, const Item& item)
{
	out << "[" << item.name << " " << item.age << " " << item.idNumber << "]";
	return out;
}
