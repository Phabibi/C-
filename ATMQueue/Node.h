/*
 * Node.h
 *
 */

#ifndef NODE_H_
#define NODE_H_
#include "Customer.h"

class Node {
private:

 Customer customer;
 Node* next;

public:
//constructor & destructor
	Node();

	Node(Customer customer);
/*gets nodes Customer*/

	Customer get_customer();

/* gets the next */

	Node* get_next();


/* sets a new nose */
	void  set_next(Node*  next);




};

#endif /* NODE_H_ */
