/*
 * Customer.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "Customer.h"

#include <string>
#include <iostream>
using namespace std;

Customer::Customer()
{

}
Customer::Customer(string x, char y, int z)
{
  name = x;
  initial = y;
  account = z;

}

Customer::Customer(string x, char y)
{
  name = x;
  initial = y;
}

string Customer::get_name()
{
  return name;
}

int Customer::get_account()
{
  return account;
}

char Customer::get_initial()
{
  return initial;
}

void Customer::set_account(int new_account)
{
  account = new_account;
}

ostream& operator<<(ostream & os,  Customer & c)
{
  os << c.name <<", "<< c.initial<<". "<<"("<<c.account<<")";
  return os;
}


bool Customer::operator<(const Customer& c) const
{
	return (name + initial) < (c.name + c.initial);
}

bool Customer::operator>(const Customer& c) const
{
	return (name + initial) > (c.name + c.initial);
}

bool Customer::operator<=(const Customer& c) const
{
	return (name + initial) <= (c.name + c.initial);
}
bool Customer::operator>=(const Customer& c) const
{
	return (name + initial) >= (c.name + c.initial);
}
bool Customer::operator==(const Customer& c) const
{
	return (name + initial) == (c.name + c.initial);
}
bool Customer::operator!=(const Customer& c) const
{
	return (name + initial) != (c.name + c.initial);
}
/*
int main()
{
  Customer customer("Parsa" ,'H', 123);
  cout << customer <<endl;
}
*/
