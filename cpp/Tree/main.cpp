#include <iostream>
#include <vector>


class Node
{
public:
    int val;
    Node* right;
    Node* left;
    Node(int val) : val(val), left(nullptr), right(nullptr)
    {
        std::cout << "Contruct Node with only value" << std::endl;
    }
    Node(int val, Node* left, Node* right) : val(val), left(left), right(right)
    {
        std::cout << "Contruct Node with full new node" << std::endl;
    }

    ~Node()
    {
        delete right;
        delete left;
        std::cout << "Deconstruct Node" << std::endl;
    }
};


class Tree
{
    static void postOrderTraversalWithoutRecursion(Node* root)
    {
        std::vector<Node*> stack;
        stack.push_back(root);
        std::vector<bool> visit;
        visit.push_back(false);
        while(stack.size() != 0)
        {
            Node* cur = stack.at(stack.size()-1);
            stack.pop_back();
            // ...
        }
    }
};
