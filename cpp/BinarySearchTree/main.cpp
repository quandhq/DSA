#include "BinarySearchTree.cpp"
#include <iostream>

int main()
{
    /*
                6
              /    \
            4       9  
          /  \     /  \
         2    5   8    10

    */
    TreeNode node2 = TreeNode(2);
    TreeNode node5 = TreeNode(5);
    TreeNode node8 = TreeNode(8);
    TreeNode node10 = TreeNode(10);
    TreeNode node4 = TreeNode(4, &node2, &node5);
    TreeNode node9 = TreeNode(9, &node8, &node10);
    TreeNode node6 = TreeNode(6, &node4, &node9);

    std::cout << "===========Test for function find of BinarySearchTree============" << "\n";
    int searchVal = 100;
    if(BinarySearchTree::find(&node6, searchVal) != nullptr)
    {
        std::cout << BinarySearchTree::find(&node6, searchVal)->val << "\n";
    }
    else
    {
        std::cout << "Not find value" << "\n";
    }

    std::cout << "========Test for find min===========" <<"\n";
    std::cout << "Min of tree is: " << BinarySearchTree::findMin(&node6)->val << "\n";  //should print out 2

    std::cout << "========Test for find max===========" <<"\n";
    std::cout << "Max of tree is: " << BinarySearchTree::findMax(&node6)->val << "\n";  //should print out 10

    BinarySearchTree::inOrderTraversal(&node6);
    
    // std::cout << "========Test for insert an element to Tree==========" << "\n";
    // TreeNode* newNode = BinarySearchTree::insert(&node6, 999);
    // BinarySearchTree::inOrderTraversal(&node6);
    // delete(newNode);
    // std::cout << "\n";

    std::cout << "========Test for delete node=================" << "\n";
    BinarySearchTree::levelTraversal(&node6);
    BinarySearchTree::deleteNode(&node6, 9); //delete 9 should return 6 4 8 2 5 10
    BinarySearchTree::levelTraversal(&node6);


}