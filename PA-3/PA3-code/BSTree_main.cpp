
#include <iostream>
#include <fstream>
#include "BSTree.h"

BSTree read_file(string file_name)
{
  /*
    open the file and use the input operator (operator>>)
    to construct a new tree
  */

  BSTree new_tree;
  ifstream infile(file_name);
  // use >> to read in to new_tree
  infile >> new_tree;
  return new_tree;
}

int main()
{
  try
  {
    cout << "\nInitiating Dilanka Test:\n";
    BSTree mytest;
    for (int i = 1; i < 2; i++)
    {
      mytest.insert(i);
      //mytest.insert(i-2);
    }
    //mytest.insert(15);
    //mytest.insert(16);
    cout << "Printing my Test:\n"
         << mytest << endl
         << mytest.get_size() << endl;

    // test the copy constructor
    BSTree mytestcopy(mytest);
    //mytestcopy.insert(-1);
    cout << "Printing copy of Test\n"
         << mytestcopy << " " << mytestcopy.get_average_search_time() << endl;
    mytestcopy.inorder(cout);
    cout << endl;

    // test the copy assignment

    for (int i = 1; i <= 12; i++)
    {
      string dir = "data-files/" + std::to_string(i);
      BSTree l = read_file(dir + "l");
      cout << "average search time linear " << i << " "
           << l.get_average_search_time() << "\t" << l.get_size() << endl;
      BSTree p = read_file(dir + "p");
      cout << "average search time perfect " << i << " "
           << p.get_average_search_time() << "\t" << p.get_size() << endl;
      BSTree r = read_file(dir + "r");
      cout << "average search time random " << i << " "
           << r.get_average_search_time() << "\t" << r.get_size() << endl;

      if (i <= 4)
      {
        cout << endl << "prefect tree " << i << endl
             << p << endl;
        cout << "Tree inorder: " << i << endl;
        p.inorder(cout);
        cout << endl << endl;
        //cout << "prefect tree " << i << endl
             //<< l;

        //cout << "prefect tree " << i << endl
             //<< r;
      }

      cout << endl;
    }
  }
  catch (string s)
  {
    cout << s;
  }
}
