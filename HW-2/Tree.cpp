#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

struct Node
{
    int obj;
    struct Node *left, *right;

    Node(int e = int(), Node *l = nullptr, Node *r = nullptr)
        : obj(e), left(l), right(r) {}
};

class Tree
{
    private:
        Node header;
    protected:

    public:
        // STUFF

    int count_Node(Node *currNode) // input head
    {
        int count = 1;
        if(currNode = nullptr)
        {
            return 0;
        }
        else
        {
            count = count + count_Node(currNode->left) + count_Node(currNode->right);
            return count;
        }
    }

};