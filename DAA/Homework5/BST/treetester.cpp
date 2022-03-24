/*----- treetester.cpp -----------------------------------------------------
                Program for testing BST.
 ------------------------------------------------------------------------*/
#include <iostream>
using namespace std;
#include "BST.h"
int main()
{
   // Testing Constructor and empty()
   BST intBST;		// test the class constructor            
   cout << "Constructing empty BST\n";
   cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";
   cout << "\nNow insert a bunch of integers into the BST."
           "\nTry items not in the BST and some that are in it:\n";
            // Testing insert
   int number;
   for (;;)
   {
      cout << "Item to insert (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      intBST.insert(number);
   }
   cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";
   cout << "Printing preorder\n";
   intBST.preorder();
   cout << "Printing inorder\n";
   intBST.inorder();
   cout << "Printing height of the tree\n";
   cout<<intBST.calculateTreeHeight()<<endl;
   for (;;)
   {
      cout << "Item to find (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      cout << (intBST.search(number) ? "Found" : "Not found") << endl;
   }
   for (;;)
   {
      cout << "Item to delete (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      intBST.deleteValue(number);
      intBST.inorder();
   }
   cout << "\n\nNow testing the search() operation."
           "\nTry both items in the BST and some not in it:\n";
   
}
