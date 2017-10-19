/*
 * Customer.h
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <iostream>
using namespace std;

class Customer {
public:
	/*constructors*/

	Customer();
	Customer(string,char,int);
	Customer(string x, char y);

	/* getters */

	string get_name();
	char get_initial();
	int get_account();

	/*setters*/

	void  set_account(int new_account);

	/*opperators*/


	 bool operator<(const Customer& c) const;

	 bool operator>(const Customer& c) const;

	 bool operator<=(const Customer& c) const;

	 bool operator>=(const Customer& c) const;

	 bool operator==(const Customer& c) const;

	 bool operator!=(const Customer& c) const;

private:
	friend ostream& operator<<(ostream & os,  Customer & c);


	string name;
	char initial;
	int account;

};

#endif /* CUSTOMER_H_ */
