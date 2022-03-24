#include <iostream>
//#include <iomanip>
#include<stdlib.h>

using namespace std;

#include "AVL.h"

int htDiff;
//--- Definition of constructor
AVL::AVL()
: myRoot(0)
{}

bool AVL::empty() const
{ return myRoot == 0; }


bool AVL::search(const int & item) const
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


void AVL::insert(const int & item)
{
   BinNode * locptr = myRoot;   // search pointer
   BinNode * parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in AVL
   while (!found && locptr != 0)
   {
      parent = locptr;
      bool val = (item < locptr->data) ? true : false;
      if (val)       // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else                           // item found
         found = true;
   }
   bool val = (!found) ? true : false;
   if (val){      // construct node containing item
      locptr = new BinNode(item);
      val = (parent == 0) ? true : false;
      if (val)               // empty tree
         myRoot = locptr;


      else if (item < parent->data){
         val = (parent->right == 0) ? true : false;
          if(val) {
              parent->left = locptr;
              locptr->parent = parent;
          }
          else{
              parent->left = locptr;
              locptr->parent = parent;
          }
      }
      else{
         val = (parent->left == 0) ? true : false;
          if(val) {
              parent->right = locptr;
              locptr->parent = parent;
          }
          else{
              parent->right = locptr;
              locptr->parent = parent;
          }
      }
       
       val = (locptr!=myRoot) ? true : false;
       if(val){
           updateHeight(parent); // Update Height after Insert
           balanceAVLafterINSERT(locptr->parent, item); // Balance tree after Insert
       }
   }

   else
      cout << "Item already in the tree\n";
}

void AVL::preorder()
{
   preorderHelper(myRoot);
}

void AVL::preorderHelper(BinNode * node)
{
   if(node != NULL) 
   {
      cout<<node->data <<"\n";
      preorderHelper(node->left);
      preorderHelper(node->right);
   }
}

void AVL::inorder()
{
   inorderHelper(myRoot);
}

void AVL::inorderHelper(BinNode * node)
{
   if(node != NULL) 
   {
      inorderHelper(node->left);
      cout<<node->data <<"\n";
      inorderHelper(node->right);
   }
}

int AVL::nodeCount()
{
   return nodeCountHelper(myRoot);
}

int AVL::nodeCountHelper(BinNode * node)
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

int AVL::calculateTreeHeight()
{
   return calculateTreeHeightHelper(myRoot);
}

int AVL::calculateTreeHeightHelper(BinNode *node)
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


void AVL::deleteNode(int & item)
{
   bool val = (myRoot == 0) ? true : false;
   if (val)
        cout << "\nThere are no nodes in the tree. The Tree is empty\n";
    else {
        BinNode *locptr = myRoot; // To search the Pointer
        BinNode *parent = 0; // Pointer to the parent of current Node.
        bool found = false; // Check if already in AVL.
		// Find the location of the item to be deleted.
        while (!found && locptr != 0) {
           val = (!found && locptr->data!=item) ? true : false;

            if(val)
                parent = locptr;
            val = (item < locptr->data) ? true : false;
            if (val) { // Move left
                locptr = locptr->left;
            }
            else if (locptr->data < item) {// Move right
                locptr = locptr->right;
            }
            else // If Item Found
                found = true;
        }
		// When found there are 3 cases.
        if (found) {
            //CASE 1: Node to be deleted has no children
            val = (locptr->left == 0 && locptr->right == 0) ? true : false;
            if (val) {
                if(parent!=0) {
                   val = (parent->left == locptr) ? true : false;
                    if (val)
                        parent->left = 0;
                    else
                        parent->right = 0;

                    updateHeight(parent);
                    balanceAVLafterDELETE(parent);
                }
                else
                    myRoot = 0;
            }
            //CASE2: Node to be deleted has 1 children
            else if((locptr->left != 0 && locptr->right == 0) || (locptr->left == 0 && locptr->right != 0)){
                if(parent!=0) {
                   val = (parent->left == locptr) ? true : false;
                    if (val) {
                       val = (locptr->left != 0) ? true : false;
                        if (val) {
                            parent->left = locptr->left;
                            locptr->left->parent = parent;
                        } else {
                            parent->left = locptr->right;
                            locptr->right->parent = parent;
                        }

                        updateHeight(parent->left);
                        balanceAVLafterDELETE(parent->left);
                    }
                    else {
                       val = (locptr->left != 0) ? true : false;
                        if (val) {
                            parent->right = locptr->left;
                            locptr->left->parent = parent;
                        } else {
                            parent->right = locptr->right;
                            locptr->right->parent = parent;
                        }
                        updateHeight(parent->right);
                        balanceAVLafterDELETE(parent->right);
                    }
                }
                // ROOT to be deleted case when root has only 1 child
                else{
                   val = (locptr->left != 0) ? true : false;
                    if(val){
                        myRoot = locptr->left;
                        myRoot->parent = 0;
                    }
                    else{
                        myRoot = locptr->right;
                        myRoot->parent = 0;
                    }
                }

            }
            //CASE3: Node to be deleted has two children. Min(RightSubTree) replaces the current node.
            else if(locptr->left != 0 && locptr->right != 0){
                BinNode * min_RightTree = locptr;
                BinNode * minParent = locptr;
                min_RightTree = min_RightTree->right;
                while(min_RightTree->left!=0){
                    minParent = min_RightTree;
                    min_RightTree = min_RightTree->left;
                }
                val = (min_RightTree->right == 0) ? true : false;
                if (val) { //Smallest item on right subtree has right child
                     val = (minParent->left == min_RightTree) ? true : false;
                    if (val) {
                        minParent->left = 0;
                        locptr->data = min_RightTree->data;
                    } else {
                        minParent->right = 0;
                        locptr->data = min_RightTree->data;
                    }
                    updateHeight(minParent);
                    balanceAVLafterDELETE(minParent);
                }
                else {
                   val = (minParent->left == min_RightTree) ? true : false;
                    if (val) {
                        minParent->left = min_RightTree->right;
                        min_RightTree->right->parent = minParent;
                        locptr->data = min_RightTree->data;
                    } else {
                        minParent->right = min_RightTree->right;
                        min_RightTree->right->parent = minParent;
                        locptr->data = min_RightTree->data;
                    }
                    updateHeight(minParent); // Update Height after delete
                    balanceAVLafterDELETE(minParent); // Balance Tree After Delete
                }
            }
        }
        else
            cout << "\nItem to delete is not in the Tree\n";
    }
}

// Balance Condition 1 : Rotate Right
void AVL::rotateRight(BinNode *Y) {
//rotate about Y to right, now X becomes the root.
    BinNode *X = Y->left;
    BinNode *temp = X->right;
    X->right = Y;
    Y->left = temp;
    if(temp!=0) temp->parent = Y;
    bool val = (Y->parent!=0) ? true : false;
    if(val){
        X->parent = Y->parent;
        val = (Y==Y->parent->left) ? true : false;
        if(val)
            Y->parent->left = X;
        else
            Y->parent->right = X;
    }
    else{ //Y is root
        myRoot = X;
        X->parent = 0;
    }
    Y->parent = X;
    Y->height = maxLorH(Y->left,Y->right)+1;
    X->height = maxLorH(X->left,X->right)+1;
}
// Balance Condition 2 : Rotate Left
void AVL::rotateLeft(BinNode *Y) {
    //rotate about Y to right, now X becomes the root.
    BinNode *X = Y->right;
    BinNode *temp = X->left;
    X->left = Y;
    Y->right = temp;
    if(temp!=0) temp->parent = Y;
    bool val = (Y->parent!=0) ? true : false;
    if(val){
        X->parent = Y->parent;
        val = (Y==Y->parent->left) ? true : false;
        if(val)
            Y->parent->left = X;
        else
            Y->parent->right = X;
    }
    else{ //Y is root
        myRoot = X;
        X->parent = 0;
    }
    Y->parent = X;
    Y->height = maxLorH(Y->left,Y->right)+1;
    X->height = maxLorH(X->left,X->right)+1;

}
// Update Height
void AVL::updateHeight(BinNode *reversePtr) {
    while (reversePtr != 0) {
        reversePtr->height = maxLorH(reversePtr->left, reversePtr->right)+1;
        reversePtr = reversePtr->parent;
    }
}

int AVL::maxLorH(BinNode * leftTree, BinNode * rightTree){
   bool val = (leftTree == 0 && rightTree != 0) ? true : false;
    if(val)
        return rightTree->height;
    else if(leftTree !=0 && rightTree == 0)
        return leftTree->height;
    else if(leftTree !=0 && rightTree != 0)
        return (leftTree->height>rightTree->height) ? leftTree->height : rightTree->height;
    else
        return -1;
}

int AVL::heightD(BinNode * leftTree, BinNode * rightTree){
   bool val = (leftTree != 0 && rightTree != 0) ? true : false;
    if(val)
        return (leftTree->height - rightTree->height);
    else if(leftTree != 0 && rightTree == 0)
        return leftTree->height+1;
    else if(leftTree == 0 && rightTree != 0)
        return -rightTree->height-1;
    else
        return 0;
}

void AVL::balanceAVLafterDELETE(BinNode *revHtCheck) {
   
    while (revHtCheck != 0) {
        //Checking the difference in the heights of L and R subtree and break if > 1
        htDiff = heightD(revHtCheck->left, revHtCheck->right);
        bool val = (htDiff > 1 || htDiff < -1) ? true : false;
        if (val) {
            //Case 1: Left Left
            val = (htDiff > 1) ? true : false;
            if (val)
            {
               if(heightD(revHtCheck->left->left, revHtCheck->left->right) >= 0)
               {
                  rotateRight(revHtCheck);
               }
            }
                

                //Case 2: Right Right
            else if (htDiff < -1)
            {
               if(heightD( revHtCheck->right->left, revHtCheck->right->right) <= 0)
               {
                  rotateLeft(revHtCheck);
               }
            }
                

                //Case 3: Left Right
            else if (htDiff > 1) {
               if(heightD(revHtCheck->left->left, revHtCheck->left->right) < 0)
               {
                  rotateLeft(revHtCheck->left);
                  rotateRight(revHtCheck);
               }
                
            }

                //Case 4: Right Left
            else if (htDiff < -1) {
               if(heightD(revHtCheck->right->left, revHtCheck->right->right) > 0)
               {
                  rotateRight(revHtCheck->right);
                rotateLeft(revHtCheck);
               }
                
            }
        }
        //update height after rotation and before next iteration
        updateHeight(revHtCheck);

        revHtCheck = revHtCheck->parent;

    }
}

void AVL::balanceAVLafterINSERT(BinNode *revHtCheck, const int & item) {
   
    while (revHtCheck != 0) {
        //Checking the difference in the heights of L and R subtree and rotate accordingly.
        htDiff = heightD(revHtCheck->left,revHtCheck->right);
        bool val = (htDiff > 1 || htDiff < -1) ? true : false;
        if (val){
            //Case 1: Left Left
            val = (htDiff > 1 && item < revHtCheck->left->data) ? true : false;
            if (val)
                rotateRight(revHtCheck);
                //Case 2: Right Right
            else if (htDiff < -1 && item > revHtCheck->right->data)
                rotateLeft(revHtCheck);
                //Case 3: Left Right
            else if (htDiff > 1 && item > revHtCheck->left->data){
                rotateLeft(revHtCheck->left);
                rotateRight(revHtCheck);
            }
                //Case 4: Right Left
            else if(htDiff < -1 && item < revHtCheck->right->data){
                rotateRight(revHtCheck->right);
                rotateLeft(revHtCheck);
            }
        }

        //update height after rotation and before next iteration
        updateHeight(revHtCheck);
        revHtCheck = revHtCheck->parent;
    }
}