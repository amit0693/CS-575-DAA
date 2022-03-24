/*----- treetester.cpp -----------------------------------------------------
                Program for testing AVL.
 ------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

#include "AVL.h"

int main()
{
   // Testing Constructor and empty()
   AVL intAVL;            // test the class constructor
   cout << "Constructing empty AVL\n";
   cout << "AVL " << (intAVL.empty() ? "is" : "is not") << " empty\n";

   // Testing insert
   cout << "\nNow insert a bunch of integers into the AVL."
           "\nTry items not in the AVL and some that are in it:\n";
   int number;
   for (;;)
   {
      cout << "Item to insert (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      intAVL.insert(number);
   }
   

   cout << "AVL " << (intAVL.empty() ? "is" : "is not") << " empty\n";

   // Testing search()

   cout << "Printing preorder\n";
   intAVL.preorder();
   cout << "Printing inorder\n";
   intAVL.inorder();
   cout << "Printing height of the tree\n";
   cout<<intAVL.calculateTreeHeight()<<endl;

   for (;;)
   {
      cout << "Item to delete (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      intAVL.deleteNode(number);
      intAVL.inorder();
   }

   cout << "\n\nNow testing the search() operation."
           "\nTry both items in the AVL and some not in it:\n";
   for (;;)
   {
      cout << "Item to find (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      cout << (intAVL.search(number) ? "Found" : "Not found") << endl;
   }

}
