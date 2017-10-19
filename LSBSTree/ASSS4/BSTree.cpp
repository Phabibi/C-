/*
 * BSTree.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */
#include <iostream>
#include "BSTree.h"


BSTree::BSTree() {
	root = NULL;
}


BSTree::~BSTree() {
	delete root;
}


bool BSTree::insert(string x, char y, int z) {

	if(root == NULL)		//empty tree
	{
		Customer new_customer(x,y,z);
		Node* new_node = new Node (new_customer,NULL,NULL);
		root = new_node;

		return true;
	}

	else
	{
		Customer new_customer(x,y,z);
		Node* left_child = NULL;
		Node* right_child = NULL;
		Node* new_node = new Node (new_customer,left_child,right_child);

		return true;

	}

	return false;
}


bool BSTree::remove(string x, char y) {
	return false;
}


bool BSTree::search(string x, char y) {
	return false;
}


vector<Customer> BSTree::rangeSearch(string x, char y, string z, char a) {
}


void BSTree::inOrderPrint() {

	Node* n = root;

	if(n != NULL)
	{
		inOrderPrint(n->left_child);
		cout << n->data << endl;
		inOrderPrint(n->right_child);
	}
}
