/*
 * ATM.h
 *
 */


#ifndef ATM_H_
#define ATM_H_
#include "ATMQueue.h"





class ATM {


private:
/* Remaining transaction time for the current customer */

	int time_remain;

/*total  waiting time */

	int totalwaittime;

	ATMQueue lineup;


public:
/*
constructor and destructor
*/

	ATM();
/* if the ATM is not in use, it will assign a customer to it
(and assigns the transaction time of that customer to the ATM)
else it will enter the customer into the queue.
*/
	void insert_customer(Customer new_customer);



	bool get_availability();
/*
updates the ATM's variables for the passage of time
removes a customer from a queue
*/
	void customer_process(int current_time);

/*returns length of the queue*/

	int queue_len();	

/*
return remaining transaction time and total time
*/

	int remaining_time();

/*returns the total wait time*/

	int total_time();






};

#endif /* ATM_H_ */
