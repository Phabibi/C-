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

}

Node::~Node()
{
  delete left_child;
  delete right_child;

}

Node::Node(Customer new_customer , Node*new_left, Node* new_right)
{
  customer = new_customer;
  left_child = new_left;
  right_child = new_right;
}


void Node::set_left(Node* new_left)
{
  left_child = new_left;
}

void Node::set_right(Node* new_right)
{
  right_child = new_right;
}

Customer Node::get_left()
{
  return left_child->customer;
}
Customer Node::get_right()
{
  return right_child->customer;
}
