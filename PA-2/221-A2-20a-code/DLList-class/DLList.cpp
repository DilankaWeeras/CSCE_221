// implementation of the DLList class

#include <stdexcept>
#include "DLList.h"

// extend runtime_error from <stdexcept>
struct EmptyDLList : public std::runtime_error
{
  explicit EmptyDLList(char const *msg = nullptr) : runtime_error(msg) {}
};

// copy constructor
DLList::DLList(const DLList &dll)
{
  // Initialize the list
  header.next = &trailer;
  trailer.prev = &header;

  DLListNode *currNode = dll.first_node();
  while (currNode != dll.after_last_node())
  {
    this->insert_last(currNode->obj);
    currNode = currNode->next;
  }

  /* Complete this function */
}
// move constructor
DLList::DLList(DLList &&dll)
{
  header.next = dll.first_node();
  trailer.prev = dll.after_last_node()->prev;
  header.next->prev = &header;
  trailer.prev->next = &trailer;
  dll.header.next = nullptr;
  dll.trailer.prev = nullptr;
  /* Complete this function */
}

// copy assignment operator
DLList &DLList::operator=(const DLList &dll)
{
  /* Complete this function */
  header.next = &trailer;
  trailer.prev = &header;

  DLListNode *currNode = dll.first_node();
  while (currNode != dll.after_last_node())
  {
    this->insert_last(currNode->obj);
    currNode = currNode->next;
  }
  return *this;
}

// move assignment operator
DLList &DLList::operator=(DLList &&dll)
{
  /* Complete this function */
  header.next = dll.first_node();
  trailer.prev = dll.after_last_node()->prev;
  header.next->prev = &header;
  trailer.prev->next = &trailer;
  dll.header.next = nullptr;
  dll.trailer.prev = nullptr;
  return *this;
}

// destructor
DLList::~DLList()
{
  DLListNode *nextNode = header.next;
  while (nextNode != &trailer)
  {
    nextNode = nextNode->next;
    delete header.next;
    header.next = nextNode;
  }
  header.next = &trailer;
  trailer.prev = &header;
  /* Complete this function */
}

// insert a new object as the first one
void DLList::insert_first(int obj)
{
  DLListNode *newNode = new DLListNode(obj, &header, header.next); //places new node with prev = header, next = headers next
  header.next->prev = newNode;                                     //header next is still set to header so header next becomes prev
  header.next = newNode;                                           //now that header next is set to prev newNode, header.next can be set to newNode
}

// insert a new object as the last one
void DLList::insert_last(int obj)
{
  DLListNode *newNode = new DLListNode(obj, trailer.prev, &trailer);
  trailer.prev->next = newNode; // Same as insert first
  trailer.prev = newNode;
}

// remove the first node from the list
int DLList::remove_first()
{
  //Do not remove the head, instead remove the first thing added
  if (header.next == &trailer)
  {
    throw; // complete later
  }
  DLListNode *nodeRemove = header.next; //copy the address of header next
  nodeRemove->next->prev = &header;     // nodeRemoves next's prev will point to header
  header.next = nodeRemove->next;       // header will point to nodeRemoves next
  int obj = nodeRemove->obj;            // temp for obj
  delete nodeRemove;                    // delete nodeRemove
  return obj;
  /* Complete this function */
}

// remove the last node from the list
int DLList::remove_last()
{
  try
  {
    if (header.next == &trailer)
    {
      throw "List is empty";
    }
    DLListNode *nodeRemove = trailer.prev;
    nodeRemove->prev->next = &trailer; // -> explained: will access and dereference at the same time so when nodeRemove is ->prev it will look at the object and not the address
    trailer.prev = nodeRemove->prev;
    int obj = nodeRemove->obj;
    delete nodeRemove;
    return obj;
    /* Complete this function */
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}

// return the first object (do not remove)
int DLList::first() const
{
  try
  {
    if (header.next == &trailer)
    {
      throw "List is Empty";
    }
    return header.next->obj;
    /* Complete this function */
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}

// return the last object (do not remove)
int DLList::last() const
{
  try
  {
    if (header.next == &trailer)
    {
      throw;
    }
    return trailer.prev->obj;
    /* Complete this function */
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}

// insert a new node after the node p
void DLList::insert_after(DLListNode &p, int obj)
{
  DLListNode *newNode = new DLListNode(obj, &p, p.next);
  p.next->prev = newNode;
  p.next = newNode;
}

// insert a new node before the node p
void DLList::insert_before(DLListNode &p, int obj)
{
  DLListNode *newNode = new DLListNode(obj, p.prev, &p);
  p.prev->next = newNode;
  p.prev = newNode;
}

// remove the node after the node p
int DLList::remove_after(DLListNode &p)
{
  try
  {
    if (header.next == &trailer)
    {
      throw;
    }
  DLListNode *remNode = p.next;
  remNode->prev->next = remNode->next;
  remNode->next->prev = remNode->prev;
  int obj = remNode->obj;
  delete remNode;
  return obj;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
}

// remove the node before the node p
int DLList::remove_before(DLListNode &p)
{
  try
  {
    if (header.next == &trailer)
    {
      throw;
    }
  DLListNode *remNode = p.prev;
  remNode->prev->next = remNode->next;
  remNode->next->prev = remNode->prev;
  int obj = remNode->obj;
  delete remNode;
  return obj;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
}

// output operator
ostream &operator<<(ostream &out, const DLList &dll)
{
  DLListNode *currNode = dll.first_node();
  while (currNode != dll.after_last_node() && !dll.is_empty())
  {
    out << currNode->obj << " ";
    currNode = currNode->next;
  }
  /* Complete this function */
  return out;
}
