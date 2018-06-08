/*
 * BSTree.cpp
 *
 *  
 *      
 */
#include <iostream>
#include<vector>

#include "BSTree.h"


BSTree::BSTree() {
	root = NULL;
}

BSTree::BSTree(const BSTree & rbt)
{
	Copy_construct(rbt.root);
}

void BSTree::Copy_construct(Node* leaf)
{
	if(leaf != NULL)
	{
		insert(leaf->customer->get_name() , leaf->customer->get_initial() , leaf->customer->get_account() );
		Copy_construct(leaf->left_child);
		Copy_construct(leaf->right_child);
	}
}


BSTree::~BSTree() {

}

void BSTree::Destroy_tree(Node* leaf)
{
	if(leaf != 0)
	{
		Destroy_tree(leaf->get_left());
		Destroy_tree(leaf->get_right());
		delete leaf;
	}
}


bool BSTree::insert(string x, char y, int z) {
	Customer* new_customer = new Customer(x,y,z);
	bool find = true;
	Node*parent = NULL;


	Node**search = BinarySearch(&root,new_customer,find,parent);

	if(find == true)
	{
		(*search)->customer->set_account(z);
		return false;
	}

	else
	{
		(*search) = new Node(new_customer,parent);
		return true;

	}

}
/*

void BSTree::Tree_insert(Customer* new_customer,Node* leaf)
{

	Node* parent;

	/*
	if(new_customer < leaf->get_customer())
	{
		if(leaf->get_left() != NULL)
		{
			Tree_insert(new_customer , leaf->get_left());
		}

		else
		{
			leaf->set_left(new Node () );
			leaf->get_left()->set_customer(new_customer);
			leaf->get_left()->set_left(NULL);
			leaf->get_left()->set_right(NULL);
		}
	}

	else if (leaf->get_customer() <= new_customer)
	{
		if(leaf->get_right() != NULL)
		{
			Tree_insert(new_customer, leaf->get_right());
		}

		else
		{
			leaf->set_right(new Node() );
			leaf->get_right()->set_customer(new_customer);
			leaf->get_right()->set_right(NULL);
			leaf->get_right()->set_left(NULL);

		}
	}
}
*/


bool BSTree::remove(string x, char y) {

	Customer customer_remove = Customer(x,y);

	bool find = false;

	Node*parent;

	Node* target = *BinarySearch(&root, &customer_remove , find , parent);

	parent = target->parent;

	if(find == true)																															//the customer was found , now check for the the cases
	{
		if(target->left_child == NULL && target->right_child == NULL)								//  the node has no children
		{
				if(target->customer < parent->customer)																	//delete left child
				{
					target->parent->left_child = NULL;
					return true;
				}
				else if(target->customer > parent->customer)														//delete right child
				{
					target->parent->right_child = NULL;
					return true;
				}
			}
			else if(target->left_child != NULL  && target->right_child == NULL)  			//the node has 2 children (worst case)
			{
				if(parent != NULL && target->customer < parent->customer)								//make parents left child to be targets left child
				{
					parent->left_child = target->left_child;
					return true;
				}

				else if(parent != NULL && target->customer > parent->customer)					//make parents right child to be parents left child
				{
					parent->right_child = target->left_child;
					return true;
				}

				else																																		//takes care of the case where therres only one thing in the tree
				{
					root = target->left_child;
					return true;
				}
			}

			else if(target->left_child == NULL && target->right_child != NULL) 				// the node only has a right child
			{
				if(parent != NULL && target->customer < parent->customer)								// make prents left child  to be the nodes right child
				{
					parent->left_child = target->right_child;
					return true;
				}

				else if(parent != NULL && target->customer > parent->customer)					//make parents right child to be nodes right child
				{
					parent->right_child = target->right_child;
					return true;

				}

				else																																		//the tree only has one node and its a right child of the root
				{
					root = target->right_child;
					return true;
				}
			}

			else if(target->left_child != NULL && target->right_child != NULL)				// the case where the Node  has to children
			{
				vector<Customer> V_children = rangeSearch(target->customer->get_name(),target->customer->get_initial(),target->right_child->customer->get_name(), target->right_child->customer->get_initial() ); //find and stores all the values of target and its childrens
				Customer V_children_customers = Customer (V_children[1].get_name() , V_children[1].get_initial() );
				Node* parent_temp;
				Node* target_temp = *BinarySearch(&root, & V_children_customers , find, parent_temp);

				parent_temp->left_child = NULL;
				/*make the temp nodes children to be targets children */
				target_temp->left_child = target->left_child;
				target_temp->right_child = target->right_child;


				if(parent != NULL && target->customer < parent->customer )							//make parent's left child to be the temp_target
				{

					parent->left_child = target_temp;
					return true;
				}

				else if(parent != NULL &&  target->customer > parent->customer)					// make parents right child  to be temp
				{

					parent->right_child = target_temp;
					return true;
				}

				else
				{
					root = target_temp;
					return true;
				}

			}
		}



	return false;
}


bool BSTree::search(string x, char y) {

	Customer* temp_customer = new Customer(x,y);
	bool find = false;
	Node*parent;
	BinarySearch(&root,temp_customer,find,parent);

	delete temp_customer; 																												//no need for the customer since we already got our result above;

	if(find == false)
	{
		return false;
	}

	else
	{
		return true;
	}


}

Node** BSTree::BinarySearch(Node**leaf , Customer* key, bool &find , Node* &parent)
{

	if(*leaf == NULL)																															//the leaf points to nothing (empty)
	{
		find = false;
		return leaf;
	}


		if(*key < *((*leaf)->customer))
		{
			parent = *leaf;
			return BinarySearch(&(*leaf)->left_child, key, find,parent);
		}

		else if(*key > *((*leaf)->customer))
		{
			parent = *leaf;
			return BinarySearch(&(*leaf)->right_child, key ,find,parent);
		}


		else
		{
			find = true;
			return leaf;

		}

}


vector<Customer> BSTree::rangeSearch(string x, char y, string z, char a) {
	vector<Customer> value;

	Customer left_customer = Customer(x,y);

	Customer right_customer =  Customer(z,a);

	rangeSearchHelper(root,value,left_customer,right_customer);

	return value;

}

void BSTree::rangeSearchHelper(Node* leaf,vector<Customer>& value , Customer left,Customer right)
{
		if(leaf != NULL)
		{
			rangeSearchHelper(leaf->left_child , value , left , right);

			if(left <= *leaf->customer && *leaf->customer <= right)
			{
				value.push_back(*leaf->customer);
			}

			rangeSearchHelper(leaf->right_child,value, left , right);
		}
}


void BSTree::inOrderPrint() {

	InorderPrintHelper(root);


}

void BSTree::InorderPrintHelper(Node* starting_node)
{
	if(starting_node != 0)
	{
		InorderPrintHelper(starting_node->left_child);
		  cout << *starting_node->customer << endl;
			InorderPrintHelper(starting_node->right_child);
	}
}
/*
int main()
{
	Customer c("parsa",'H',124);
	//cout << c << endl;

	BSTree bst;
	bst.insert("Mori",'G',1);
	bst.insert("Mori",'B',1);
	bst.insert("Mori",'A',1);

	//bst.insert("Mori",'A',1);

	bst.inOrderPrint();
	bst.remove("Mori",'A');
	bst.inOrderPrint();
	cout << bst.search("Mori",'G') << endl;
}
*/
