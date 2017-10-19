#include <iostream>
#include "ATM.h"
using namespace std;

int getSimParameters(int &M, int &N, int &C, int *&atime_list, int *&ttime_list);
void displaySimResults(int wait, int C);
int ATM_shortest_queue(ATM atmarray[] , int atm_number);

int main () {
  // TO DO:: Rename these
  int simulation_time , number_of_ATMs,number_of_customers;
  int *atime_list, *ttime_list;

  // Total wait time for all customers in the simulation.
  int total_wait_time = 0;

  // Input code to read simulation parameters
  int param_err = getSimParameters(simulation_time, number_of_ATMs, number_of_customers, atime_list, ttime_list);
  if (param_err) {
    cerr << "Error in simulation parameters." << endl;
    return -1;
  }



  // TO DO:: Your simulation code goes here.
  int minutes;
  int remaining_customers = number_of_customers;
  ATM* ATMarray = new ATM[number_of_ATMs];
  Customer new_customer;
  int shortest_queue;

  while(minutes < simulation_time || remaining_customers > 0)
  {
    for(int i = 0 ; i < number_of_customers ; i++)
    {
      if(atime_list[i] == minutes && minutes < simulation_time)
      {
        new_customer = Customer(atime_list[i] , ttime_list[i]);
        shortest_queue = ATM_shortest_queue(ATMarray , number_of_ATMs);
        ATMarray[shortest_queue].insert_customer(new_customer);
        remaining_customers--;
      }
    }
    minutes ++;

    for(int j = 0 ; j < number_of_ATMs ; j++)
    {
      ATMarray[j].customer_process(minutes);
    }
  }

  for(int k = 0 ; k < number_of_ATMs  ; k++)
  {
    total_wait_time += ATMarray[k].total_time();
  }






  // Display statistics on the simulation.
  displaySimResults(total_wait_time, number_of_customers);
  // Return total_wait_time, will be used by test script.
  return total_wait_time;
}

int ATM_shortest_queue(ATM atmarray[] , int atm_number)
{
  int shortest_len = atmarray[0].queue_len();
  int shortest_index = 0;

  for(int i = 0 ; i < atm_number ; i++)
  {
    if(atmarray[i].get_availability()==true)
    {
      return i;
    }
  }

  for(int j = 1 ; j < atm_number ; j++)
  {
    if(atmarray[j].queue_len() < shortest_len)
    {
      shortest_len = atmarray[j].queue_len();
      shortest_index = j;
    }

  }
      return shortest_index;

}




// Read the simulation parameters from standard input (cin).
// Parameters:
// M: minutes to run simulation
// N: number of ATMs
// C: number of customers
// atime_list: array of customer arrival times
// ttime_list: array of customer transaction times
//    customer i arrives at time atime_list[i] and performs a transaction that takes ttime_list[i] minutes
//
// All parameters are pass-by-reference (note & character).  This means assignments in this function will affect value from calling function
//
// Return value:
// returns 0 if successful read of input
// non-zero values used to denote failure
//   1: simulation time < 1
//   2: number of ATMs < 1
//   3: number of customers < 1
//   4: a customer's transaction time < 1
//   5: customer list is not sorted by arrival time
//   6: customer arrival time later than simulation end time
int getSimParameters(int &M, int &N, int &C, int *&atime_list, int *&ttime_list) {
  // Code to read simulation parameters.
  cout << "Run an ATM simulation" << endl;

  cout << "Enter the number of minutes" << endl;
  cin >> M;
  // Check input validity.
  if (M < 1) {
    cerr << "Simulation for invalid length of time." << endl;
    return 1;
  }


  cout << "Enter the number of ATMs" << endl;
  cin >> N;
  // Check input validity.
  if (N < 1) {
    cerr << "Simulation for invalid number of ATMs." << endl;
    return 2;
  }


  // Read customer list
  cout << "Enter the number of customers" << endl;
  cin >> C;
  if (C < 1) {
    cerr << "Simulation for invalid number of customers." << endl;
    return 3;
  }
  // Allocate memory for customer list.
  atime_list = new int [C];
  ttime_list = new int [C];

  // Read C customers
  int atime = -1;
  int prevatime = -1;
  int ttime = 0;
  for (int i=0; i<C; i++) {
    cout << "Enter customer arrival and transaction time." << endl;
    cin >> atime;
    cin >> ttime;

    // Check input validity.
    if (ttime < 1) {
      cerr << "Invalid transaction time." << endl;
      return 4;
    }
    if (atime < prevatime) {
      cerr << "Arrival times not sorted." << endl;
      return 5;
    }
    if (atime >= M) {
      cerr << "Arrival time later than simulation end time." << endl;
      return 6;
    }
    prevatime = atime;

    atime_list[i] = atime;
    ttime_list[i] = ttime;
  }

  // All went well, return 0.
  return 0;
}


// Display statistics on the simulation.
// wait: Total wait time of all customers in simulation.
// C: total number of customers in simulation.
void displaySimResults(int wait, int C) {
  cout << "Simulation results" << endl;
  cout << "Number of customers: " << C << endl;
  cout << "Total wait time: " << wait << endl;
  cout << "Average wait time: " << ((double) wait)/((double) C) << endl;
}
