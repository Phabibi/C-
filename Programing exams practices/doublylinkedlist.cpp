#include <iostream>
#include "doublylinkedlist.h"

using namespace std;

doublylinkedlist::doublylinkedlist(){

  head = new Node;
  tail = new Node;

  head->next = tail;
  tail->prev = head;

}

doublylinkedlist::~doublylinkedlist(){
  delete head;
  delete tail;
}

void doublylinkedlist::insert(Node* new_node , int new_element)
{
  Node* p = new Node;
  p->element = new_element;
  p->next = new_node;
  p->prev = new_node->prev;
  new_node->prev->next = new_node->prev = p;

}

void doublylinkedlist::insert_front(int new_element)
{
    insert(head->next,new_element);
}

void doublylinkedlist::insert_back(int new_element)
{
    insert(tail, new_element);
}
void doublylinkedlist::remove(Node* new_node )
{
  Node* v = new_node->prev;
  Node* u = new_node->next;

  v->next = u;
  u->prev = v;
  delete new_node;
}

void doublylinkedlist::remove_back()
{
  remove(tail->prev);
}

void doublylinkedlist::remove_front()
{
  remove(head->next);
}
int main()
{
  doublylinkedlist new_doubly = doublylinkedlist();


  new_doubly.insert_front(1);
  new_doubly.insert_front(2);
  new_doubly.insert_front(3);
  new_doubly.remove_front();
  new_doubly.remove_back();

  while(new_doubly.head->next != new_doubly.tail)
  {
    cout << new_doubly.head->next->element << endl;

    new_doubly.head = new_doubly.head->next;

  }

}
