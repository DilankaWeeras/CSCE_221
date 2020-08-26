// testing the templated class DLList

#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

#include "TemplatedDLList.h"

using namespace std;

int main()
{
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DLList<int> dll;
  cout << "list: " << dll << endl
       << dll.count_Nodes(dll.first_node()) << endl;

  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i = 10; i <= 100; i += 10)
  {
    stringstream ss;
    ss << i;
    dll.insert_last(i);
  }

  cout << "list: " << dll << endl
       << dll.count_Nodes(dll.first_node()) << endl;

  DLList<int> dll2;

  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i = 10; i <= 100; i += 10)
  {
    stringstream ss;
    ss << i;
    dll2.insert_first(i);
  }

  DLList<int> dll3;

  //dll3 = mergeList(dll, dll2);

  cout << "list: 10 10 20 20 30 30 40 40 50 50 60 60 70 70 80 80 90 90 100 100" << endl
       << dll.count_Nodes(dll.first_node()) << endl;

  /*
  cout << "list: " << dll << endl << endl;
  
  cout << "Copy to a new list" << endl;
  DLList<string> dll2(dll);
  cout << "list2: " << dll2 << endl << endl;

  DLList<string> mergeLists = mergeList(dll, dll2);
  cout << "Merged List: " << mergeLists << endl << endl;

  
  cout << "Assign to another new list" << endl;
  DLList<string> dll3;
  dll3 = dll;
  cout << "list3: " << dll3 << endl << endl;
  
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0; i<10; i++) {
    dll.remove_last();
  }
  cout << "list: " << dll << endl << endl;
  
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0; i<10; i++) {
    dll.remove_first();
  }
  cout << "list: " << dll << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl;

  // more testing...
  // add tests for insert_after, insert_before
  // add tests for remove_after, remove_before

  cout << "Testing insert before and insert after:\n\n";
  T_DLListNode<string> *currNode = dll2.first_node()->next->next->next;
  cout << "Insert before and after: (" << currNode->obj << ") the strings for before and after." <<  endl;
  dll2.insert_after(*currNode, "after");
  dll2.insert_before(*currNode, "before");
  cout << "list2: " << dll2 << endl << endl;
  // add tests for remove_after, remove_before
  cout << "Remove before and after: (" << currNode->obj << ")" <<  endl;
  string rA = dll2.remove_after(*currNode);
  string rB = dll2.remove_before(*currNode);
  cout << "(" << rA << ") and (" << rB << ") were removed\n\n";
  cout << "list: " << dll2 << endl << endl;
  */
  return 0;
}
