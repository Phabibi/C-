/*
 * Node.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "Node.h"

Node::Node()
{
  left_child = NULL;
  right_child = NULL;
  parent = NULL;

}

Node::~Node()
{
  delete left_child;
  delete right_child;
  delete parent;
}

Node::Node(Customer* new_customer , Node*new_left, Node* new_right)
{
  customer = new_customer;
  left_child = new_left;
  right_child = new_right;
}

Node::Node(Customer* new_customer,Node*new_parent)
{
  customer = new_customer;
  parent = new_parent;
}


void Node::set_left(Node* new_left)
{
  left_child = new_left;
}

void Node::set_right(Node* new_right)
{
  right_child = new_right;
}

Node* Node::get_left()
{
  return left_child;
}
Node* Node::get_right()
{
  return right_child;
}

Customer* Node::get_customer()
{
  return customer;
}

void Node::set_customer(Customer* cust)
{
  customer = cust;

}
