/*
 * BSTree.h
 *
 */

#ifndef BSTREE_H_
#define BSTREE_H_

#include "Customer.h"
#include "Node.h"
#include<vector>
#include<string>
using namespace std;

class BSTree {
public:
	BSTree();
	BSTree(const BSTree & rbt); // Copy constructor
	virtual ~BSTree();

	// Creates and inserts a new customer (with the data shown in the parameters) in the tree, in a new tree node.
	bool insert(string, char, int);

	// Deletes the first node with a matching name and initial from the tree.
	// Returns true if the deletion was successful (that is, if the customer was found).
	// Note that two customers are equal if they have the same name and initial, regardless of the account balance.
	bool remove(string, char);

	//  Searches the tree for the given value, returning true if the customer is found
	bool search(string, char);

	// Returns a vector of Customers where the customer names (initial and last name)
	// are in the range specified in the parameters.  For example rangeSearch("Dobbs", 'A', "Fogg", D)
	// returns all customers whose names are between Dobbs A and Fogg D.
	vector<Customer> rangeSearch(string, char, string , char);

	// Prints the contents of the tree in sorted order.
	void inOrderPrint();

private:

	//Binary Searches through the tree in order to find the right insertion point
	//it is also used in remove to find the target that needs to be removed
	Node** BinarySearch(Node** leaf,Customer* key, bool &find, Node* &parent);
	//helps inOrderPrint
	//accepts a node (root) and recursivly prints the tree;
	void InorderPrintHelper(Node* starting_node);
	//accepts a node (root) and recursivly deletes tree then the node in post order triversal
	void Destroy_tree(Node* leaf);
	//not used..
	void Tree_insert(Customer* new_customer , Node * leaf);
	//recursivly deep copies every elment of thre tree
	void Copy_construct(Node* leaf);

	void rangeSearchHelper(Node* leaf,vector<Customer> &value , Customer left,Customer right);

	Node* root;


};

#endif /* BSTREE_H_ */
