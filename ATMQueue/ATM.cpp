/*
 * ATM.cpp
 *
 */

#include "ATM.h"
#include <iostream>
using namespace std;




// TO DO:: Fill in.
ATM::ATM(){}


bool ATM::get_availability()
{
  if(time_remain == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void ATM::insert_customer(Customer new_customer)
{

  if(get_availability() == true)

    {
      time_remain = new_customer.tran_time();
    }


  else
  {
    lineup.enqueue(new_customer);
  }
}

void ATM::customer_process(int current_time)
{


  if(get_availability() == false)
  {
     time_remain--;
  }

  if(time_remain == 0 && queue_len() > 0)
  {
      Customer new_custo = lineup.dequeue();

      time_remain = new_custo.tran_time();

      totalwaittime += (current_time - new_custo.arrival_time() ) ;

  }

}


int ATM::queue_len()
{
  return lineup.get_customer_count();
}

int ATM::remaining_time()
{
  return time_remain;
}


int ATM::total_time()
{
  return totalwaittime;
}
