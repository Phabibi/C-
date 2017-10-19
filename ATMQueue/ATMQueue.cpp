/*
 * ATMQueue.cpp
 *
 */

#include "ATMQueue.h"
#include <iostream>
using namespace std;

// TO DO:: Fill in.

ATMQueue::ATMQueue(){
	customer_front = NULL;
	customer_back = NULL;
	cust_count = 0;
}

void ATMQueue::enqueue(Customer new_customer)
{
  Node* customer_node = new Node(new_customer);


  if(customer_front == NULL)     //empty
  {
        customer_front = customer_node;
  }

  else                            //enque in the back regular case
  {
    customer_back->set_next(customer_node);
  }

  customer_back = customer_node;

  cust_count++;

}

Customer ATMQueue::dequeue()
{
  Node * temp = new Node();
  Customer cust_temp;

  if(customer_front == NULL)  //empty
  {
  	cout << "dequeue while queue is empty\n";
  }

  else
  {

    temp = customer_front;

    customer_front = customer_front->get_next();

    cust_temp = temp->get_customer();

    cust_count--;


  }

  return cust_temp;
}


int ATMQueue::get_customer_count()
{
  return cust_count;
}
