#include <iostream>
#include <vector>


/*
                1
           2         3
        4    5      6   7   

*/

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
            std::cout << "Deconstruct Node val: " << this->val << std::endl;
        }
};


class Tree
{
    public:
        static std::vector<int> postOrderTraversalWithoutRecursion(Node* root)
        {
            std::vector<int> result;
            std::vector<Node*> stack;
            stack.push_back(root);
            std::vector<bool> visit;
            visit.push_back(false);
            while(stack.size() != 0)
            {
                Node* cur = stack.at(stack.size()-1);
                stack.pop_back();
                bool visited = visit.at(visit.size()-1);
                visit.pop_back();
                if(cur != nullptr)
                {
                    if(visited == true)
                    {
                        result.push_back((*cur).val);
                    }
                    else
                    {
                        stack.push_back(cur);
                        visit.push_back(true);
                        stack.push_back((*cur).right);
                        visit.push_back(false);
                        stack.push_back((*cur).left);
                        visit.push_back(false);
                    }
                }
            }
            return result;
        }
};

int main()
{
    Node node4 = Node(4);
    Node node5 = Node(5);
    Node node6 = Node(6);
    Node node7 = Node(7);
    Node node2 = Node(2, &node4, &node5);
    Node node3 = Node(3, &node6, &node7);
    Node root = Node(1, &node2, &node3);
    std::vector<int> res = Tree::postOrderTraversalWithoutRecursion(&root);
    for(auto i : Tree::postOrderTraversalWithoutRecursion(&root))
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
