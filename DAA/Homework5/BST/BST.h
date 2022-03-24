#include <iostream>
using namespace std;  

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
 public:
  /***** Function Members *****/
  BST();
  bool empty() const;
  bool search(const int & item) const; 
  void insert(const int & item);
  void avlInsert(const int & item);
  void preorder();
  void inorder();
  int nodeCount();
  void deleteNode(int & item);
  void deleteValue(int & item);
  void avlDeleteValue(int & item);

  int calculateTreeHeight();
  void balance();


  /***** Node class *****/
  class BinNode 
  {
   public:
    int data;
    BinNode * left;
    BinNode * right;
    int height;  

    // BinNode constructors
    // Default -- data part is default int value; both links are null.
    BinNode()
    : left(0), right(0)
    {}

    // Explicit Value -- data part contains item; both links are null.
    BinNode(int item)
    : data(item)
    , left(0), right(0)
    {}
 
  };// end of class BinNode declaration
  
  /***** Data Members *****/
  BinNode * myRoot; 
  void preorderHelper(BinNode *);
  void inorderHelper(BinNode *);
  int nodeCountHelper(BinNode *);
  int calculateTreeHeightHelper(BinNode *);
  int balanceHelper(BinNode *, BinNode *);

}; // end of class declaration

#endif
