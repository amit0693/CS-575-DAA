#include <iostream>
//#include <iomanip>
#include<stdlib.h>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
: myRoot(0)
{}

bool BST::empty() const
{ return myRoot == 0; }


bool BST::search(const int & item) const
{
   BinNode * locptr = myRoot;
   bool found = false;
   while (!found && locptr != 0)
   {
      if (item < locptr->data)       // descend left
        locptr = locptr->left;
      else if (locptr->data < item)  // descend right
        locptr = locptr->right;
      else                           // item found
        found = true;
   }
   return found;
}


void BST::insert(const int & item)
{
   BinNode * locptr = myRoot;   // search pointer
   BinNode * parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in BST
   while (!found && locptr != 0)
   {
      parent = locptr;
      if (item < locptr->data)       // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else                           // item found
         found = true;
   }
   if (!found)
   {                                 // construct node containing item
      // cout<<"Creating new item with value"<<item<<"\n";
      locptr = new BinNode(item);  
      // cout<<"created new item\n";

      if (parent == 0)               // empty tree
         myRoot = locptr;
      else if (item < parent->data )  // insert to left of parent
         parent->left = locptr;
      else                           // insert to right of parent
         parent->right = locptr;
   }
   else
      cout << "Item already in the tree\n";
   // cout<<"Balancing after insertion\n";
   //balance();
}

void BST::preorder()
{
   preorderHelper(myRoot);
}

void BST::preorderHelper(BinNode * node)
{
   if(node != NULL) 
   {
      cout<<node->data <<"\n";
      preorderHelper(node->left);
      preorderHelper(node->right);
   }
}

void BST::inorder()
{
   inorderHelper(myRoot);
}

void BST::inorderHelper(BinNode * node)
{
   if(node != NULL) 
   {
      inorderHelper(node->left);
      cout<<node->data <<"\n";
      inorderHelper(node->right);
   }
}

int BST::nodeCount()
{
   return nodeCountHelper(myRoot);
}

int BST::nodeCountHelper(BinNode * node)
{
   if(node != NULL) 
   {
      int leftSize = nodeCountHelper(node->left);
      int rightSize = nodeCountHelper(node->right);
      return leftSize + rightSize + 1;
   }
   else
   {
      return -1;
   }
   
}

int BST::calculateTreeHeight()
{
   return calculateTreeHeightHelper(myRoot);
}

int BST::calculateTreeHeightHelper(BinNode *node)
{
   if(node!=NULL) 
   {
      int leftheight= calculateTreeHeightHelper(node->left);
      int rightheight = calculateTreeHeightHelper(node->right);
      int maxHeight = leftheight > rightheight ? leftheight : rightheight;
      return maxHeight + 1;
   }
   else
   {
      return -1;
   }
   
}

void BST::deleteValue(int & item) {
   deleteNode(item);
}


void BST::deleteNode(int & item)
{
   BinNode * locptr = myRoot;   // search pointer
   BinNode * parent = 0;        // pointer to parent of current node

   bool found = false;
   while (!found && locptr != 0)
   {

      if (item < locptr->data) {
         parent = locptr;
         locptr = locptr->left;
     } else if (locptr->data < item) {// descend right
         parent = locptr;
        locptr = locptr->right;
     } else {
         // Node has no children
         if (locptr->left == NULL && locptr->right == NULL) {
            if (parent == 0) {
               myRoot = locptr;
               return;
            }             // empty tree
               
            else if (item < parent->data ) {
               parent->left = NULL;
               return;

            } else {
               parent->right = NULL;// delete to right of parent
               free(locptr);
               return;
            }                          
               
         }
         // node has one children
         if (locptr->left == NULL && locptr->right!=NULL) {
            if (parent == 0){
               myRoot = locptr;
               return;
            }             // empty               // empty tree
              
            else if (item < parent->data ) {
               parent->left = locptr->right;
               free(locptr);
               return;
            } else {
               parent->right = locptr->right;
               free(locptr);
               //cout<<"Returning\n";
               return;
            }          
         }

         if (locptr->right == NULL && locptr->left!=NULL) {
            if (parent == 0)  {
               myRoot = locptr;
               return;
            }            

            else if (item < parent->data ) {
               parent->left = locptr->left;
               free(locptr);
               return;

            } else {
               parent->right = locptr->left;
               free(locptr);
               return;
            }          
         }
         // node has two children
         // Get the inorder successor (smallest 
         // in the right subtree) 
         BinNode * minNode = locptr->right;
         while (minNode->left != NULL) {
               minNode = minNode->left;
         }

         locptr->data = minNode->data; // duplicate the node
         parent = locptr;
         locptr = locptr->right;
         item = minNode->data;
         //deleteNode(locptr->right, minNode->data); // delete the duplicate node
      }  

   }
}
