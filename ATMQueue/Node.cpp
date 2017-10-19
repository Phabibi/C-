/*
 * Node.cpp
 *
 */

#include "Node.h"
#include <iostream>
Node::Node(){}

Node::Node(Customer new_customer)

{
  	customer = new_customer;
  	next = NULL;
}

Customer Node::get_customer()
{
  return customer;
}

Node* Node::get_next()
{
  return next;
}

void Node::set_next(Node * new_next)
{
       next = new_next ;
}


// TO DO:: Fill in.
