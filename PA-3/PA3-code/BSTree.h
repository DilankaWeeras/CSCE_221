#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
  int value;
  Node* left;
  Node* right;
  int search_time; //see the problem description

  // Node constructor
  Node(int val = 0, Node* l = nullptr, Node* r = nullptr)
    : value(val), left(l), right(r), search_time(0) {}

  //Node Functions
};

struct BSTree
{
public:
  // constructors
  BSTree() : size(0), root(nullptr) {}
  // copy constructor
  BSTree(const BSTree& other);
  // move constructor
  BSTree(BSTree&& other);
  // copy assignment
  BSTree& operator=(const BSTree& other);
  // move assignment
  BSTree operator=(BSTree&& other);
  ~BSTree();

  const Node* get_root() const { return root; }
  const int get_size() const { return size; }
  Node* insert(int obj);
  Node* search(int obj);
  void update_search_times();
  float get_average_search_time();
  ostream& inorder(ostream& out);
  ostream& print_level_by_level(ostream& out);

private:
  int size;
  Node* root;

  // you may need helper functions to be called recursively
  // this is one example:
  void copy_helper(Node* copy_to, const Node* copy_from) const;
  void pretty_print_node(ostream& out,Node* node);
  int get_total_search_time(Node* node);

  //Helper functions by Dilanka
  void deleteTree(Node*& t);
  Node* insert_helper(int obj,Node*& t);
  Node* search_helper(int obj, Node*& t);
  void inorder_helper(Node*& t, ostream &out);
  void update_search_times_helper(Node*& t, int cost);

  int depth(Node*& t)
  {
    if(t==nullptr)
    {
      return -1;
    }
    else
    {
      int dleft = depth(t->left);
      int dright = depth(t->right);
      return (dleft > dright) ? 1 + dleft : 1 + dright;
    }
  }
};

// print a BSTree
ostream& operator<<(ostream& out, BSTree& tree);

// print a node
ostream& operator<<(ostream& out, Node node);

// read in a tree from a file
istream& operator>>(istream& in, BSTree& tree);


#endif
