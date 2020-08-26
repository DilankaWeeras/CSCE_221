//#ifndef BSTREE_H //undo comment at some point
//#define BSTREE_H //undo comment at some point

#include "BSTree.h"
//#include <queue>

// input / output operators
ostream &operator<<(ostream &out, BSTree &tree)
{
  tree.print_level_by_level(out);
  return out;
}

ostream &operator<<(ostream &out, Node node)
{
  return out << "( " << node.value << ", "
             << node.search_time << " )";
}

istream &operator>>(istream &in, BSTree &tree)
{
  /*
    take input from the in stream, and build your tree
    input will look like
    4 
    2 
    6 
    1 
    3 
    5 
    7
  */
  int next;
  while (in >> next)
    tree.insert(next);
  return in;
}

///////////// Implementation To Do ////////////////////

// copy constructor
BSTree::BSTree(const BSTree &other)
{
  /*
    complete this copy constructor
    make sure when copying nodes to copy
    the value and left and right children
  */
  root = new Node(other.root->value);
  copy_helper(root, other.get_root());
  size = other.size;
  update_search_times();
}

// move constructor
BSTree::BSTree(BSTree &&other)
{
  root = other.root;
  other.root = nullptr;
}

//copy assignment
BSTree &BSTree::operator=(const BSTree &other)
{
  /*
    complete this assignment operator
    make sure when copying nodes to copy
    the value
    and left and right children
    not important for this part but will be used later
  */
  root = new Node(other.root->value);
  copy_helper(root, other.get_root());
  size = other.size;
  update_search_times();
  return *this;
}

// move assignment
BSTree BSTree::operator=(BSTree &&other)
{
  root = other.root;
  other.root = nullptr;
  return *this;
}
// recursive helper function
void BSTree::copy_helper(Node *copy_to,
                         const Node *copy_from) const
{
  if (copy_from == nullptr)
    return;

  if (copy_from->left != nullptr)
  {
    copy_to->left = new Node(*copy_from->left);
    copy_helper(copy_to->left, copy_from->left);
  }
  else
  {
    copy_to->left = nullptr;
  }

  if (copy_from->right != nullptr)
  {
    copy_to->right = new Node(*copy_from->right);
    copy_helper(copy_to->right, copy_from->right);
  }
  else
  {
    copy_to->right = nullptr;
  }
}
// destructor
BSTree::~BSTree()
{
  // use a helper function
  deleteTree(root);
}
// recursive helper function
void BSTree::deleteTree(Node *&t)
{
  //postorder travel
  if (t == nullptr)
  {
    return;
  }
  if (t->left != nullptr)
  {
    deleteTree(t->left);
  }
  if (t->right != nullptr)
  {
    deleteTree(t->right);
  }
  delete t;
}
//implemented
Node *BSTree::insert(int obj)
{
  /*
    insert a node into the tree
    first find where the node should go
    then modify pointers to connect your new node 
  */
  return insert_helper(obj, root);
}
Node *BSTree::insert_helper(int obj, Node *&t)
{
  /*
    insert a node into the tree
    first find where the node should go
    then modify pointers to connect your new node 
  */
  if (t == nullptr)
  {
    t = new Node(obj);
    size++;
    update_search_times();
  }
  else if (obj < t->value)
  {
    t->left = insert_helper(obj, t->left);
  }
  else if (obj > t->value)
  {
    t->right = insert_helper(obj, t->right);
  }
  else
  {
    throw "Duplicate item";
  }
  return t;
}
//implemented
Node *BSTree::search(int obj)
{
  /*
    recursivly search down the tree to find the node that contains obj
    if you dont find anything return null
  */
  return search_helper(obj, root);
}
Node *BSTree::search_helper(int obj, Node *&t)
{
  if (t->value == obj)
  {
    return t;
  }
  else if (obj < t->value)
  {
    search_helper(obj, t->left);
  }
  else if (obj > t->value)
  {
    search_helper(obj, t->right);
  }
  return nullptr;
}

void BSTree::update_search_times()
{
  /*
    do a BFS or DFS of your tree and update the searchtimes of all nodes
  */
  /*
  queue<int> q;
  q.emplace(root);
  while(!q.empty())
  {
    q.emplace(root); //finish later because I dont know how to.
  }
  */
  update_search_times_helper(root, 1);
}
void BSTree::update_search_times_helper(Node *&t, int cost)
{
  if (t != nullptr)
  {
    t->search_time = cost;
    update_search_times_helper(t->left, cost + 1);
    update_search_times_helper(t->right, cost + 1);
  }
}

ostream &BSTree::inorder(ostream &out)
{
  /*
    print your nodes in infix order
    if our tree looks like 

    4
    2 6
    1 3 5 7

    we should get

    1 2 3 4 5 6 7 
  */
  inorder_helper(root, out);
  return out;
}
void BSTree::inorder_helper(Node *&t, ostream &out)
{
  if (t == nullptr)
  {
    return;
  }
  inorder_helper(t->left, out);
  out << t->value << "[" << t->search_time << "]\t";
  inorder_helper(t->right, out);
  //return out;
}
// implemented
void BSTree::pretty_print_node(ostream &out, Node *node)
{
  out << node->value << "[" << node->search_time << "] ";
}
// implemented
ostream &BSTree::print_level_by_level(ostream &out)
{
  /*
    print the tree using a BFS 
    output should look like this if we dont have a full tree

    4
    2 6
    1 X 5 7
    X X X X X X X 9

    it will be helpfull to do this part iterativly, 
    so do the BFS with the std stack data structure.

    it may also be helpfull to put the entire tree into a vector 
    (probably google this if you dont know how to do it)
  */

  if (root == nullptr)
    return out;

  bool hasNodes = true;
  vector<Node *> current_level;
  vector<Node *> next_level;
  current_level.push_back(root);
  while (hasNodes)
  {
    hasNodes = false;
    for (auto node : current_level)
    {
      if (node != nullptr)
      {
        pretty_print_node(out, node);
        if (node->left != nullptr)
          hasNodes = true;
        if (node->right != nullptr)
          hasNodes = true;

        next_level.push_back(node->left);
        next_level.push_back(node->right);
      }
      else
      {
        out << "X ";
        next_level.push_back(nullptr);
        next_level.push_back(nullptr);
      }
    }
    out << endl;
    current_level.clear();
    current_level = next_level;
    next_level.clear();
  }

  return out;
}

// implemented
int BSTree::get_total_search_time(Node *node)
{
  if (node == nullptr)
    return 0;

  return get_total_search_time(node->left) +
         get_total_search_time(node->right) + node->search_time;
}

// implemented
float BSTree::get_average_search_time()
{
  int total_search_time = get_total_search_time(root);
  if (total_search_time == 0)
    return -1;

  return ((float)total_search_time) / size;
}

//#endif// change at the end
