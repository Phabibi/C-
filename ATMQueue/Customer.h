/*
 * Customer.h
 *
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

class Customer {

private:
	int transaction_time;
	int time_arrive;


public:

	Customer();
	Customer(int time_arrive, int transaction_time);

	/*
	returns the transaction_time
	*/
	int tran_time();

	/*
	returns the arrival_time
	*/

	int arrival_time();
};

#endif /* CUSTOMER_H_ */
