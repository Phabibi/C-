#include <iostream>

using namespace std;

class Node {
public:
  int element;
  Node* prev;
  Node* next;

  friend class doublylinkedlist;

};
class doublylinkedlist
{
public:
  doublylinkedlist();
  ~doublylinkedlist();


  void insert(Node*new_node , int new_element);
  void insert_front(int new_element);
  void insert_back(int new_element);
  void remove(Node* node);
  void remove_front();
  void remove_back();


  Node* head;
  Node* tail;

};
