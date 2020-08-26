#ifndef MINQUEUE_H
#define MINQUEUE_H

#include "TemplatedDLList.h"

template <typename Object>
class MinQueue
{
private:
    DLList<Object> queue; // has a dll
    int s = 0; // has a size

protected:
public:
    MinQueue() // default constructor
    {
        s = 0;
    }
    void enqueue(Object x) // use dll to insert first
    {
        s++;
        queue.insert_first(x);
    }
    Object dequeue() // use dll to remove last and return removed value
    {
        try
        {
            if (s == 0) // Error check for empty list. This is also done in DLL class
            {
                throw "The list is empty\n";
            }
            s--;
        return queue.remove_last();
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << '\n'; //will abort program
        }
    }
    int size() // return the size
    {
        return s;
    }
    Object min() // go through linked list and return the smallest object of that datatype using  < 
    {
        try
        {
            if (s == 0)
            {
                throw "The list is empty.\n";
            }
            Object min = queue.first_node()->obj;
            T_DLListNode<Object> *currNode = queue.first_node();
            while (currNode != queue.after_last_node() && !queue.is_empty())
            {
                if (currNode->obj < min)
                {
                    min = currNode->obj;
                }
                currNode = currNode->next;
            }
            return min;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
};

#endif
