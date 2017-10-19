/*
 * Node.h
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#ifndef NODE_H_
#define NODE_H_

#include "Customer.h"

class Node {
public:

  Node();
  Node(Customer new_customer, Node*new_left , Node*new_right);
  ~Node();
  void set_left(Node* new_left);
  void set_right(Node* new_right);
  Customer get_left();
  Customer get_right();
private:
  Customer customer;
  Node* left_child;
  Node* right_child;
};

#endif /* NODE_H_ */
