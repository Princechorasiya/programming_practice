
class node
{
public:
  int data;
  node *next;
  node(int value = 0, node *next = nullptr)
  {
    this->data = value;
    this->next = next;
  }
};

class LinkedList
{
public:
  node *head;
  node *tail;
  LinkedList()
  {
    head = nullptr, tail = nullptr;
  }

  // methods i
  // print the linked list;
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
    // insert at head
    node *new_node = new node(val);
    if (head == nullptr)
      head = new_node, tail = new_node;
    else
    {
      new_node->next = head;
      head = new_node;
    }
  }

  void insertAtTail(int val)
  {
    node *new_node = new node(val);
    if (tail == nullptr)
      head = tail = new_node;

    tail->next = new_node;
    tail = new_node;
  }

  void insert(int val, int pos)
  {
    // inset the element at the given pos pos count 1,2,3,4 ....
    node *temp = head;
    if (pos == 1)
    {
      insertAtHead(val);
      return;
    }
    for (int i = 0; i < pos - 2 && temp != nullptr; i++)

    {
      temp = temp->next;
    }
    if (temp == nullptr)
    {
      cout << "not enough elements in the linked list what to do?" << endl;
    }
    if (temp->next == nullptr)
    {
      insertAtTail(val);
      return;
    }
    node *new_node = new node(val, temp->next);
    temp->next = new_node;
  }

  void deleteHead()
  {
    if (head == nullptr)
    {
      cout << "underflwo ll empty" << endl;
      return;
    }
    node *temp = head;

    head = head->next;
    delete temp;
  }

  void deleteTail()
  {
    node *temp = head;

    if (tail == nullptr)
    {
      cout << "underflwow" << endl;
      return;
    }

    while (temp->next != tail)
    {
      temp = temp->next;
    }

    tail = temp;
    tail->next = nullptr;
    temp = temp->next;
    delete temp;
  }
  void deletePos(int pos)
  {
    node *temp = head;
    int cnt = 1;
    if (pos == cnt)
    {
      deleteHead();
      return;
    }
    while (cnt < pos - 1)
    {
      temp = temp->next;
      cnt++;
    }

    if (temp == nullptr)
    {
      cout << "oout of the position count" << endl;
    }
    if (temp->next == tail)
    {
      deleteTail();
      return;
    }
    node *delete_node = temp->next;

    temp->next = temp->next->next;
    delete delete_node;
  }
};
