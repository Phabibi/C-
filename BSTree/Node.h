/*
 * Node.h
 *
 *  
 *      
 */

#ifndef NODE_H_
#define NODE_H_

#include "Customer.h"

class Node {
public:

/*constructors*/
  Node();
  Node(Customer* new_customer, Node*new_left , Node*new_right);
  Node(Customer* new_customer, Node*parent);
  ~Node();

/*setters*/

  void set_left(Node* new_left);
  void set_right(Node* new_right);
  void set_customer(Customer* cust);
/*getters*/

  Node* get_left();
  Node* get_right();
  Customer* get_customer();
  Node* left_child;
  Node* right_child;
  Customer* customer;
  Node* parent;     //used for insertion
private:
};

#endif /* NODE_H_ */
