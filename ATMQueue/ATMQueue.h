/*
 * ATMQueue.h
 *
 */
 

#ifndef ATMQUEUE_H_
#define ATMQUEUE_H_
#include "Customer.h"
#include "Node.h"


class ATMQueue {
  // TO DO:: Fill in.
private:

  Node * customer_front;

  Node * customer_back;

  int cust_count;

public:

  ATMQueue();

  /*inserts a customer in the front of the Queue*/

  void enqueue(Customer new_customer);

  /*takes the customer in the front and returns its value */

  Customer dequeue();

  /*returns length of the Queue (cust_count) */
  
  int get_customer_count();

  


};

#endif /* ATMQUEUE_H_ */
