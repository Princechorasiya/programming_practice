#include <bits/stdc++.h>
using namespace std;

class node
{
  // represent a node of doubly linked list
public:
  int data;
  node *prev, *next;
  node(int data = 0)
  {
    this->data = data;
    this->prev = nullptr;
    this->next = nullptr;
  }
};

class LinkedList
{
public:
  node *head, *tail;

  LinkedList()
  {
    head = tail = nullptr;
  }

  void print()
  {
    node *temp = head;
    while (temp != nullptr)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }

  void insertAtHead(int val)
  {
    node *new_node = new node(val);
    if (head == nullptr)
    {
      head = tail = new_node;
      return;
    }
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
  }
  void insertAtEnd(int val)
  {
    // insert the element at the end of list
    node *new_node = new node(val);
    if (tail == nullptr)
    {
      tail = head = new_node;
      return;
    }
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
  }

  void insert(int val, int pos)
  {
    int cnt = 1;
    if (cnt == pos)
    {
      insertAtHead(val);
      return;
    }
    node *temp = head;
    while (cnt < pos - 1)
    {
      cnt++;
      temp = temp->next;
    }
    if (temp == nullptr)
    {
      cout << "going out of the linked list" << endl;
    }
    if (temp->next == nullptr)
    {
      // insert at tail
      insertAtEnd(val);
      return;
    }
    node *new_node = new node(val);
    new_node->next = temp->next;
    temp->next->prev = new_node;
    temp->next = new_node;
    new_node->prev = temp;
  }

  void deleteAtHead()
  {
    node *temp = head;
    if (head == nullptr)
    {
      cout << "underflow no elemnt" << endl;
      return;
    }
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;
  }
  void deleteAtTail()
  // works fine
  {
    if (tail == nullptr)
    {
      cout << "underflowe" << endl;
      return;
    }
    node *temp = tail;

    tail = tail->prev;
    tail->next = nullptr;
    temp->prev = nullptr;
    delete temp;
  }

  void deleteA(int pos)
  {
    // delete the element at pos in doubly linked list
    int cnt = 1;
    if (cnt == pos)
    {
      deleteAtHead();
      return;
    }
    node *temp = head;

    while (cnt < pos)
    {
      temp = temp->next;
      cnt++;
    }
    if (tail == nullptr)
    {
      cout << "Out of the ll " << endl;
      return;
    }
    if (temp == tail)
    {
      deleteAtTail();
      return;
    }
    // temp pointing to elemetn
    // cout << temp->data << endl;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;
  }
};

int main()
{
  LinkedList ll;
  ll.insertAtHead(3);
  ll.insertAtHead(2);
  ll.insertAtHead(1);

  ll.insertAtEnd(4);
  ll.insertAtEnd(5);
  ll.insertAtEnd(6);
  ll.insert(7, 7);
  ll.print();
  // ll.deleteAtHead();
  // ll.deleteAtTail();
  int n = 2;
  ll.deleteA(2);

  ll.print();
}