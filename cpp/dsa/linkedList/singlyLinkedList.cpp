#include <bits/stdc++.h>
using namespace std;

class node
{
public:
  int val;
  node *next;
  node(int n)
  {
    val = n;
    next = nullptr;
  }
};

class linkedList
{
public:
  node *head, *tail;
  linkedList()
  {
    head = nullptr;
    tail = nullptr;
  }
  linkedList(node *head)
  {
    this->head = head;
  }

  void insertEnd(int n)
  {
    node *new_node = new node(n);
    if (head == nullptr)
    {
      head = tail = new_node;
      return;
    }
    tail->next = new_node;
    tail = new_node;
  }

  node *insertEnd(node *head, int n)
  {
    node *new_node = new node(n);
    if (head == nullptr)
    {
      head = new_node;
      return head;
    }
    node *temp = head;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }
    temp->next = new_node;
    return head;
  }

  node *insertHead(node *head, int n)
  {
    node *new_node = new node(n);
    if (head == nullptr)
    {
      head = tail = new_node;
      return head;
    }
    new_node->next = head;
    head = new_node;
    return head;
  }

  node *insertAtIndex(node *head, int n, int ind)
  {
    if (ind == 0)
    {
      return insertHead(head, n);
    }
    node *new_node = new node(n);
    node *temp = head;
    while (temp != nullptr && ind != 1)
    {
      temp = temp->next;
      ind--;
    }
    if (temp == nullptr)
      return head;
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
  }

  void print(node *head)
  {
    node *temp = head;
    if (head == nullptr)
    {
      return;
    }
    while (temp != nullptr)
    {
      cout << temp->val << " ";
      temp = temp->next;
    }
    cout << endl;
  }

  void makeList()
  {
    int v = -1;
    do
    {
      cin >> v;
      if (v == -1)
      {
        break;
      }
      insertEnd(v);
    } while (v != -1);
    return;
  }

  node *removeHead(node *head)
  {
    if (head == nullptr)
    {
      cout << "zero size" << endl;
      return nullptr;
    }
    node *temp = head;
    head = head->next;
    free(temp);
    return head;
  }

  int getFirst(node *head)
  {
    if (head == nullptr)
      return -1;
    return head->val;
  }

  int getLast()
  {
    if (tail == nullptr)
      return -1;
    return tail->val;
  }

  int getAt(node *head, int n)
  {
    if (head == nullptr)
      return -1;
    if (n == 0)
      return getFirst(head);
    node *temp = head;
    while (temp != nullptr && n != 0)
    {
      temp = temp->next;
      n--;
    }
    if (temp != nullptr)
      return temp->val;
    return -1;
  }

  node *reverse(node *head)
  {
    node *prev = nullptr;
    node *curr = head;
    node *forward = nullptr;
    while (curr != nullptr)
    {
      forward = curr->next;
      curr->next = prev;
      prev = curr;
      curr = forward;
    }
    return prev;
  }

  node *merge2(node *head, node *head1)
  {
    if (head == nullptr || head1 == nullptr)
      return head == nullptr ? head1 : head;

    node *c1 = head, *c2 = head1;
    node *frw = nullptr;
    node *pre = nullptr;
    while (c1 != nullptr && c2 != nullptr)
    {
      frw = c1->next;
      c1->next = c2;
      pre = c1;
      c1 = frw;

      frw = c2->next;
      c2->next = c1;
      pre = c2;
      c2 = frw;
    }
    if (c1 != nullptr || c2 != nullptr)
    {
      pre->next = (c1 == nullptr) ? c2 : c1;
    }
    return head;
  }

  node *mergeSorted(node *head1, node *head2)
  {
    if (head1 == nullptr)
      return head2;
    if (head2 == nullptr)
      return head1;

    node *new_head = nullptr;
    node *temp3 = nullptr;

    if (head1->val <= head2->val)
    {
      new_head = head1;
      head1 = head1->next;
    }
    else
    {
      new_head = head2;
      head2 = head2->next;
    }

    temp3 = new_head;

    while (head1 != nullptr && head2 != nullptr)
    {
      if (head1->val <= head2->val)
      {
        temp3->next = head1;
        head1 = head1->next;
      }
      else
      {
        temp3->next = head2;
        head2 = head2->next;
      }
      temp3 = temp3->next;
    }

    if (head1 != nullptr)
    {
      temp3->next = head1;
    }
    else if (head2 != nullptr)
    {
      temp3->next = head2;
    }

    return new_head;
  }

  node *mergeSort(node *head)
  {
    if (head == nullptr || head->next == nullptr)
      return head;
    node *mid = findMid(head);
    node *head2 = mid->next;
    mid->next = nullptr;
    head = mergeSort(head);
    head2 = mergeSort(head2);
    return mergeSorted(head, head2);
  }

  node *findMid(node *head)
  {
    if (head == nullptr || head->next == nullptr)
      return head;
    node *slow = head;
    node *fast = head->next;
    while (fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  node *mid(node *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return head;
    }
    node *fast = head;
    node *slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};