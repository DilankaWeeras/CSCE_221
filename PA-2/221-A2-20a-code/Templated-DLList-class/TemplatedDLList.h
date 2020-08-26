// header file for the templated DLList

#ifndef DLList_H
#define DLList_H

#include <iostream>

using namespace std;

//class DLList; // class declaration

// doubly linked list node
template <typename Object>
struct T_DLListNode
{
    Object obj;
    T_DLListNode<Object> *prev, *next;
    // constructor
    T_DLListNode(Object e = Object(), T_DLListNode *p = nullptr, T_DLListNode *n = nullptr)
        : obj(e), prev(p), next(n) {}
};

// doubly linked list class
template <typename Object>
class DLList
{
private:
    T_DLListNode<Object> header, trailer;

public:
    DLList() : header(Object()), trailer(Object()) // default constructor
    {
        header.next = &trailer;
        trailer.prev = &header;
    }
    DLList(const DLList &dll) // copy constructor
    {
        // Initialize the list
        header.next = &trailer;
        trailer.prev = &header;

        T_DLListNode<Object> *currNode = dll.first_node();
        while (currNode != dll.after_last_node())
        {
            this->insert_last(currNode->obj);
            currNode = currNode->next;
        }
        /* Complete this function */
    }
    DLList(DLList &&dll) // move constructor
    {
        header.next = dll.first_node();
        trailer.prev = dll.after_last_node()->prev;
        header.next->prev = &header;
        trailer.prev->next = &trailer;
        dll.header.next = nullptr;
        dll.trailer.prev = nullptr;
        /* Complete this function */
    }
    ~DLList() // destructor
    {
        T_DLListNode<Object> *nextNode = header.next;
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
    DLList &operator=(const DLList &dll) // copy assignment operator
    {
        /* Complete this function */
        header.next = &trailer;
        trailer.prev = &header;

        T_DLListNode<Object> *currNode = dll.first_node();
        while (currNode != dll.after_last_node())
        {
            this->insert_last(currNode->obj);
            currNode = currNode->next;
        }
        return *this;
    }
    DLList &operator=(DLList &&dll) // move assignment operator
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
    // return the pointer to the first node
    T_DLListNode<Object> *first_node() const { return header.next; }
    // return the pointer to the trailer
    const T_DLListNode<Object> *after_last_node() const { return &trailer; }
    // return if the list is empty
    bool is_empty() const { return header.next == &trailer; }
    Object first() const // return the first object
    {
        try
        {
            if (header.next == &trailer)
            {
                throw "The list is empty";
            }
            return header.next->obj;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        /* Complete this function */
    }
    Object last() const // return the last object
    {
        try
        {

            if (header.next == &trailer)
            {
                throw "The list is empty";
            }
            return trailer.prev->obj;
            /* Complete this function */
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n'; //will abort program
        }
    }
    void insert_first(Object obj) // insert to the first node
    {
        T_DLListNode<Object> *newNode = new T_DLListNode<Object>(obj, &header, header.next); //places new node with prev = header, next = headers next
        header.next->prev = newNode;                                                         //header next is still set to header so header next becomes prev
        header.next = newNode;
    }
    Object remove_first() // remove the first node
    {

        /* Complete this function */
        try
        {
            //Do not remove the head, instead remove the first thing added
            if (header.next == &trailer)
            {
                throw "The list is empty"; // complete later
            }
            T_DLListNode<Object> *nodeRemove = header.next; //copy the address of header next
            nodeRemove->next->prev = &header;               // nodeRemoves next's prev will point to header
            header.next = nodeRemove->next;                 // header will point to nodeRemoves next
            Object obj = nodeRemove->obj;                   // temp for obj
            delete nodeRemove;                              // delete nodeRemove
            return obj;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n'; // will abort program
        }
    }
    void insert_last(Object obj) // insert to the last node
    {
        T_DLListNode<Object> *newNode = new T_DLListNode<Object>(obj, trailer.prev, &trailer);
        trailer.prev->next = newNode; // Same as insert first
        trailer.prev = newNode;
    }
    Object remove_last() // remove the last node
    {

        try
        {
            if (header.next == &trailer)
            {
                throw "The list is empty";
            }
            T_DLListNode<Object> *nodeRemove = trailer.prev;
            nodeRemove->prev->next = &trailer; // -> explained: will access and dereference at the same time so when nodeRemove is ->prev it will look at the object and not the address
            trailer.prev = nodeRemove->prev;
            Object obj = nodeRemove->obj;
            delete nodeRemove;
            return obj;
            /* Complete this function */
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n'; //will abort program
        }
    }
    void insert_after(T_DLListNode<Object> &p, Object obj)
    {
        T_DLListNode<Object> *newNode = new T_DLListNode<Object>(obj, &p, p.next);
        p.next->prev = newNode;
        p.next = newNode;
    }
    void insert_before(T_DLListNode<Object> &p, Object obj)
    {
        T_DLListNode<Object> *newNode = new T_DLListNode<Object>(obj, p.prev, &p);
        p.prev->next = newNode;
        p.prev = newNode;
    }
    Object remove_after(T_DLListNode<Object> &p)
    {
        try
        {
            if (header.next == &trailer || p.next == &trailer)
            {
                throw "The list is empty or Nothing after";
            }
            T_DLListNode<Object> *remNode = p.next;
            remNode->prev->next = remNode->next;
            remNode->next->prev = remNode->prev;
            Object obj = remNode->obj;
            delete remNode;
            return obj;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n'; //will abort program
        }
    }
    Object remove_before(T_DLListNode<Object> &p)
    {
        try
        {
            if (header.next == &trailer || p.prev == &header)
            {
                throw "The list is empty or Nothing before";
            }
            T_DLListNode<Object> *remNode = p.prev;
            remNode->prev->next = remNode->next;
            remNode->next->prev = remNode->prev;
            Object obj = remNode->obj;
            delete remNode;
            return obj;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n'; //will abort program
        }
    }
};

// output operator
template <typename Object>
ostream &operator<<(ostream &out, const DLList<Object> &dll)
{
    T_DLListNode<Object> *currNode = dll.first_node();
    while (currNode != dll.after_last_node() && !dll.is_empty())
    {
        out << currNode->obj << " ";
        currNode = currNode->next;
    }
    /* Complete this function */
    return out;
}

#endif
