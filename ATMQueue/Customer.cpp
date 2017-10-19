/*
 * Customer.cpp
 *
 */

#include "Customer.h"


Customer::Customer(){}

Customer::Customer(int new_arrival_time , int new_transaction_time)

{
  	time_arrive = new_arrival_time;
  	transaction_time = new_transaction_time ;
}


int Customer::tran_time()
{
  return transaction_time;
}

int Customer::arrival_time()
{
  return time_arrive;
}
