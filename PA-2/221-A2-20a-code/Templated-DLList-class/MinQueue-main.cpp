#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

#include "MinQueue.h"

using namespace std;

int main()
{
    MinQueue<string> list1;

    cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
    for (int i = 0; i <= 100; i += 1)
    {
        stringstream ss;
        ss << i;
        list1.enqueue(ss.str());
    }

    cout << "Find Min Value:\n";
    string s = list1.min();
    cout << s << endl
         << endl;

    cout << "Add -100 Find min:\n";
    list1.enqueue("-100");
    s = list1.min();
    cout << s << endl
         << endl;

    cout << "Add -1123 Find min:\n";
    list1.enqueue("-1123");
    s = list1.min();
    cout << s << endl
         << endl;

    cout << "Add 12 Find min:\n";
    list1.enqueue("-12");
    s = list1.min();
    cout << s << endl
         << endl;

    cout << "Add -10003 Find min:\n";
    list1.enqueue("-10003");
    s = list1.min();
    cout << s << endl
         << endl;

    cout << "Pop first 100 nodes" << endl;
    for (int i = 0; i <= 100; i += 1)
    {
        cout << "Pop: " << list1.dequeue() << endl; // Pop all values
    }
    //list1.dequeue(); // Used for error checking This is sopposed to abort without seg fault.

    MinQueue<int> list2;

    cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
    for (int i = 0; i <= 100; i += 1)
    {
        list2.enqueue(i);
    }

    cout << "Find Min Value:\n";
    int j = list2.min();
    cout << j << endl
         << endl;

    cout << "Add -100 Find min:\n";
    list2.enqueue(-100);
    j = list2.min();
    cout << j << endl
         << endl;

    cout << "Add -1123 Find min:\n";
    list2.enqueue(-1123);
    j = list2.min();
    cout << j << endl
         << endl;

    cout << "Add 12 Find min:\n";
    list2.enqueue(-12);
    j = list2.min();
    cout << j << endl
         << endl;

    cout << "Add -10003 Find min:\n";
    list2.enqueue(-10003);
    j = list2.min();
    cout << j << endl
         << endl;

    cout << "Pop first 100 nodes" << endl;
    for (int i = 0; i <= 100; i += 1)
    {
        cout << "Pop: " << list2.dequeue() << endl; // Pop all values
    }
    //list1.dequeue(); // Used for error checking This is sopposed to abort without seg fault.

    return 0;
}