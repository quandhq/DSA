#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <stack>

#include "Node.cpp"
#include "Tree.cpp"

void print_tree(Node* root)
{
    std::cout << "Level order traversal" << std::endl;
    for(auto i : Tree::levelTraversalWithoutRecursion(root))
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{

    /*
                1
           2         3
        4    5      6   7   

    */

    Node node4 = Node(4);
    Node node5 = Node(5);
    Node node6 = Node(6);
    Node node7 = Node(7);
    Node node2 = Node(2, &node4, &node5);
    Node node3 = Node(3, &node6, &node7);
    Node root = Node(1, &node2, &node3);
    Node root1 = Node(1, &node2, &node3);
    print_tree(&root);

    std::cout << "Number of leaves in BT" << std::endl;
    std::cout << Tree::numberOfleavesInBTUsingLevelTrversal(&root) << std::endl;



    std::cout << "Find level with max sum" << std::endl;
    std::cout << Tree::findLevelWithMaxSum(&root);
    std::cout << std::endl;

    std::cout << "Print all paths from root to leaf" << std::endl;
    std::vector<int> buffer;
    /*
        expect:
        1 2 4 10 | 1 2 5 | 1 3 6 | 1 3 7 
    */
    Tree::printPathsUsingRecursion(&root, buffer);
    std::cout << std::endl;

    /*
                     1
                2         3
             4    5    6    7   
          1000
    */

    print_tree(&root);

    std::cout << "Check path with sum which is 11" << std::endl;
    std::vector<int> vectorBufferForCheckExistPathWithGivenSum;
    Tree::checkExistPathWithGivenSum(&root, vectorBufferForCheckExistPathWithGivenSum, 11);
    std::cout << std::endl;

    std::cout << "==================================================\n";

    /*
                     1
                2         3
             4    5    6    7   
          1000
    */

    print_tree(&root);

    std::cout << "Find sum of all element in BTree\n";
    std::cout << Tree::findSumOfAllElementUsingRecursion(&root) << "\n";

    std::cout << "==================================================\n";

    /*
                     1
                2         3
             4    5    6    7   
          1000
    */

    print_tree(&root);

    std::cout << "Calculate all sum of node in tree using levelTraversal" << "\n";
    std::cout << Tree::findSumOfAllElementUsingLevelTraversal(&root) << "\n";


    /*
                        1
                  2           3
              4       5     6      7   
         1000  9999

            Node node4 = Node(4);
            Node node5 = Node(5);
            Node node6 = Node(6);
            Node node7 = Node(7);
            Node node2 = Node(2, &node4, &node5);
            Node node3 = Node(3, &node6, &node7);
            Node root = Node(1, &node2, &node3);
            Node root1 = Node(1, &node2, &node3);
    */

    std::cout << "===============Test for checking mirror BT=============" << "\n";
    Node node4_1 = Node(4);
    Node node5_1 = Node(5);
    Node node6_1 = Node(6);
    Node node7_1 = Node(7);
    Node node2_1 = Node(2, &node4_1, &node5_1);
    Node node3_1 = Node(3, &node6_1, &node7_1);
    Node root1ForMirror = Node(1, &node2_1, &node3_1);
    Tree::print_tree(&root1ForMirror);
    /*
                       1
                2           3
            4       5     6      7   
    */
    Node node4_2 = Node(4);
    Node node5_2 = Node(5);
    Node node6_2 = Node(6);
    Node node7_2 = Node(7);
    Node node2_2 = Node(2, &node4_2, &node5_2);
    Node node3_2 = Node(3, &node6_2, &node7_2);
    Node root2ForMirror = Node(1, &node2_2, &node3_2);
    Tree::mirrorOfBTUsingRecursion(&root2ForMirror);
    Tree::print_tree(&root2ForMirror);
    /*
                      1
                3           2
            7       6     5      4   
    */
    if(Tree::areMirrors(&root1ForMirror, &root2ForMirror))
    {
        std::cout << "Yes they are mirror\n";
    }


    std::cout << "Test for least common ancestor \n";
    /*
                     1
                2         3
             4    5    6    7  
    */

    print_tree(&root);
    Node* leastCommonAncestorNode = Tree::leastCommonAncestor(&root, 100, 999);
    if(leastCommonAncestorNode != nullptr)
    {
        std::cout << leastCommonAncestorNode->val << "\n";
    }
    else
    {
        std::cout << "Not found!" << std::endl;
    }
    
    std::cout << "==============Test for build binary Tree===========" << std::endl;
    int preOrderIndex = 0;
    std::vector<int> preOrderVector =  {1, 2, 4, 5, 3, 6};
    std::vector<int> inOrderVector =  {4, 2, 5, 1, 6, 3};
    Node* new_node = Tree::buildBinaryTree(preOrderVector, inOrderVector, &preOrderIndex);
    
    Tree::print_tree(new_node);
}
