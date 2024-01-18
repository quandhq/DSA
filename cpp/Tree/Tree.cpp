#pragma once
#include <iostream>
#include <deque>
#include <vector>
#include <stack>
#include "Node.cpp"

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

        static int heightOfBinaryTreeWithRecursion(Node* root)
        {
            if(root == nullptr) return 0;
            return std::max(Tree::heightOfBinaryTreeWithRecursion((*root).left), Tree::heightOfBinaryTreeWithRecursion((*root).right)) + 1;
        }

        static int heightOfBinaryTreeWithoutRecursion(Node* root)
        {
            if(root == nullptr) return 0;
            std::deque<Node*> queue;
            queue.push_back(root);
            queue.push_back(nullptr);
            int level = 0;
            while(queue.size() != 0)
            {
                Node* temp = queue.at(0);
                queue.pop_front();
                if(temp == nullptr){
                    ++level;
                    if(queue.size() != 0)
                    {
                        queue.push_back(nullptr);
                    }
                }
                else
                {
                    if(temp->left != nullptr) queue.push_back(temp->left);
                    if(temp->right != nullptr) queue.push_back(temp->right);
                }
            }
            return level;
        }

        static Node* deepestNodeInBinaryTree(Node* root)
        {
            if(root == nullptr) return nullptr;
            std::deque<Node*> d;
            d.push_back(root);
            Node* res;
            while(d.size() != 0)
            {
                res = d.at(0);
                d.pop_front();
                if((*res).left != nullptr) d.push_back((*res).left);
                if((*res).right != nullptr) d.push_back((*res).right);
            }
            return res;
        }

        static std::vector<int> levelTraversalWithoutRecursion(Node* root)
        {
            std::vector<int> res;
            if(root == nullptr) return res;
            std::deque<Node*> d;
            d.push_back(root);
            Node* temp;
            while(d.size() != 0)
            {
                temp = d.at(0);
                d.pop_front();
                res.push_back(temp->val);
                if((*temp).left != nullptr) d.push_back((*temp).left);
                if((*temp).right != nullptr) d.push_back((*temp).right);
            }
            return res;
        }

        static void deleteAnElement(Node* root, int searchVal)
        {
            if(root == nullptr) return;
            std::deque<Node*> d;
            d.push_back(root);
            Node* foundNode = nullptr;
            bool found = false;
            std::stack<Node*> s;
            while(d.size() != 0)
            { 
                Node* temp = d.at(0);
                d.pop_front();
                s.push(temp);
                if((*temp).val == searchVal && found == false)
                {
                    foundNode = temp;
                    found = true;
                }
                if(temp->left != nullptr) d.push_back(temp->left);
                if(temp->right != nullptr) d.push_back(temp->right);
            }

            Node* lastNode = s.top();
            Node* parentOfLastNode;
            bool right = false;
            s.pop();
            while(1)
            {
                Node* cur = s.top();
                s.pop();
                if((*cur).right == lastNode)
                {
                    parentOfLastNode = cur;
                    right = true;
                    break;
                }
                if((*cur).left == lastNode)
                {
                    parentOfLastNode = cur;
                    break;
                }
            }

            if(right == true)
            {
                foundNode->val = (parentOfLastNode->right)->val;
                parentOfLastNode->right = nullptr;
            }
            else
            {
                foundNode->val = (parentOfLastNode->left)->val;
                parentOfLastNode->left = nullptr;
            }
             
        }

        static void insertInBinaryTree(Node* root, int val)
        {
            if(root == nullptr) return;
            std::deque<Node*> d;
            d.push_back(root);
            while(d.size() != 0)
            {
                Node* temp = d.at(0);
                d.pop_front();

                if((*temp).left != nullptr) d.push_back((*temp).left);
                if((*temp).right != nullptr) d.push_back((*temp).right);

                if(temp->left == nullptr)
                {
                    temp->left = new Node(val);
                    return;
                }
                if(temp->right == nullptr)
                {
                    temp->right = new Node(val);
                    return;
                }
            }
        }

        static int numberOfleavesInBTUsingLevelTrversal(Node* root)
        {
            if(root == nullptr) return 0;
            std::deque<Node*> d;
            d.push_back(root);
            int count = 0;
            while(d.size() != 0)
            {
                Node* temp = d.at(0);
                d.pop_front();
                if((*temp).left != nullptr) d.push_back((*temp).left);
                if((*temp).right != nullptr) d.push_back((*temp).right);
                if((*temp).left == nullptr && (*temp).right == nullptr) ++count;
            }
            return count;
        }

        static std::vector<Node*> numberOfFullNodeInBTUsingLevelTraversal(Node* root)
        {
            std::vector<Node*> returnedVector;
            if(root == nullptr) return returnedVector;
            std::deque<Node*> dequeToProcessAllNodeInLevelTraversal;
            dequeToProcessAllNodeInLevelTraversal.push_back(root);
            while(dequeToProcessAllNodeInLevelTraversal.size() != 0)
            {
                Node* currentNode = dequeToProcessAllNodeInLevelTraversal.at(0);
                dequeToProcessAllNodeInLevelTraversal.pop_front();
                if(currentNode->left != nullptr && currentNode->right != nullptr)
                {
                    returnedVector.push_back(currentNode);
                }
                if(currentNode->left != nullptr) dequeToProcessAllNodeInLevelTraversal.push_back(currentNode->left);
                if(currentNode->right != nullptr) dequeToProcessAllNodeInLevelTraversal.push_back(currentNode->right);
            }
            return returnedVector;
        }


        static std::vector<Node*> numberOfHalfNodeInBTUsingLevelOrderTraversal(Node* root)
        {
            std::vector<Node*> returnedVector;
            if(root == nullptr) return returnedVector;
            std::deque<Node*> dequeToProcessAllNodes;
            dequeToProcessAllNodes.push_back(root);
            while(dequeToProcessAllNodes.size() != 0)
            {
                Node* currentNode = dequeToProcessAllNodes.at(0);
                dequeToProcessAllNodes.pop_front();
                if(currentNode->left == nullptr && currentNode->right != nullptr 
                                                || 
                    currentNode->left != nullptr && currentNode->right == nullptr)
                {
                    returnedVector.push_back(currentNode);
                }
                if(currentNode->left != nullptr) dequeToProcessAllNodes.push_back(currentNode->left);
                if(currentNode->right != nullptr) dequeToProcessAllNodes.push_back(currentNode->right);
            }
            return returnedVector;
        }

        static int areStructurullySameTrees(Node* root1, Node* root2)
        {
            if(root1 == nullptr && root2 == nullptr)
            {
                return 1;
            }

            if(root1 == nullptr || root2 == nullptr)
            {
                return 0;
            }

            return (root1->val == root2->val) && areStructurullySameTrees(root1->left, root2->left) 
                    && areStructurullySameTrees(root1->right, root2->right);
        }

        static int levelOfBinaryTree(Node* root)
        {
            int left, right;
            if(root == nullptr)
            {
                return 0;
            }
            left = levelOfBinaryTree(root->left);
            right = levelOfBinaryTree(root->right);
            return std::max(left, right) + 1;
        }

        static int diameterOfTree(Node* root, int* ptr)
        {
            if(root == nullptr) return 0;
            int levelOfNodeLeft, levelOfNodeRight;
            levelOfNodeLeft = diameterOfTree(root->left, ptr);
            levelOfNodeRight = diameterOfTree(root->right, ptr);
            if(levelOfNodeLeft+levelOfNodeRight > *ptr)
            {
                *ptr = levelOfNodeLeft + levelOfNodeRight;
            }
            return std::max(levelOfNodeLeft, levelOfNodeRight) + 1;
        }

        static int findLevelWithMaxSum(Node* root)
        {
            if(!root)
            {
                return 0;
            }
            std::deque<Node*> d;
            d.push_back(root);
            d.push_back(nullptr);
            int temp = 0;
            int sum = 0;
            int level = 0;
            int resultLevel = 0;
            while(d.size() != 0)
            {
                Node* cur = d.at(0);
                d.pop_front();
                if(cur == nullptr)
                {
                    ++level;
                    if(d.size() != 0)
                    {
                        d.push_back(nullptr);
                    }
                    if(temp > sum)
                    {
                        sum = temp;
                        resultLevel = level;
                    }
                    temp = 0;
                }
                else
                {
                    temp += cur->val;
                    if(cur->left != nullptr) d.push_back(cur->left);
                    if(cur->right != nullptr) d.push_back(cur->right);
                }
            } 
            return resultLevel;
        }


        /*
        helper of printPathsUsingRecursion function
        expect:
        1 2 4 10 | 1 2 5 | 1 3 6 | 1 3 7 
        */
        static void printPath(std::vector<int> path)
        {
            for(int i : path)
            {
                std::cout << i << " ";
            }
            std::cout << " | ";
        }
        static void printPathsUsingRecursion(Node* root, std::vector<int> path)
        {
            if(root == nullptr) return;
            path.push_back(root->val);
            if(root->left == nullptr && root->right == nullptr)
            {
                printPath(path);
                return;
            }
            printPathsUsingRecursion(root->left, path);
            printPathsUsingRecursion(root->right, path);
        }

        static void checkExistPathWithGivenSum(Node* root, std::vector<int> path, int sum)
        {
            if(root == nullptr) return;
            path.push_back(root->val);
            if(root->left == nullptr && root->right == nullptr)
            {
                int sumBuffer = 0;
                for(int i : path)
                {
                    sumBuffer += i;
                }
                if(sumBuffer == sum)
                {
                    printPath(path);
                }
                return;
            }
            checkExistPathWithGivenSum(root->left, path, sum);
            checkExistPathWithGivenSum(root->right, path, sum);
        }

        static int findSumOfAllElementUsingRecursion(Node* root)
        {
            if(root == nullptr) return 0;
            int leftSum = findSumOfAllElementUsingRecursion(root->left);
            int rightSum = findSumOfAllElementUsingRecursion(root->right);
            return root->val + leftSum + rightSum;
        }

        static int findSumOfAllElementUsingLevelTraversal(Node* root)
        {
            if(root == nullptr) return 0;
            int sum = 0;
            std::deque<Node*> dequeToProcessAllNodeInTree;
            dequeToProcessAllNodeInTree.push_back(root);
            while(dequeToProcessAllNodeInTree.size() != 0)
            {
                Node* cur = dequeToProcessAllNodeInTree.at(0);
                dequeToProcessAllNodeInTree.pop_front();
                sum += cur->val;
                if(cur->left != nullptr) dequeToProcessAllNodeInTree.push_back(cur->left);
                if(cur->right != nullptr) dequeToProcessAllNodeInTree.push_back(cur->right);
            }
            return sum;
        }



        static Node* mirrorOfBinaryTree(Node* root)
        {
            if(root == nullptr) return root;
            std::deque<Node*> dequeToProcessAllNodes;
            dequeToProcessAllNodes.push_back(root);
            while(dequeToProcessAllNodes.size() != 0)
            {
                Node* cur = dequeToProcessAllNodes.at(0);
                dequeToProcessAllNodes.pop_front();
                Node* temp = cur->left;
                cur->left = cur->right;
                cur->right = temp;
                if(cur->left != nullptr) dequeToProcessAllNodes.push_back(cur->left);
                if(cur->right != nullptr) dequeToProcessAllNodes.push_back(cur->right);
            }
            return root;
        }

        static void print_tree(Node* root)
        {
            std::cout << "Level order traversal" << std::endl;
            for(auto i : Tree::levelTraversalWithoutRecursion(root))
            {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }

        static Node* mirrorOfBTUsingRecursion(Node* root)
        {
            if(root != nullptr)
            {
                mirrorOfBTUsingRecursion(root->left);
                mirrorOfBTUsingRecursion(root->right);
                Node* temp = root->left;
                root->left = root->right;
                root->right = temp;
            }
            return root;
        }

        static bool areMirrors(Node* root1, Node* root2)
        {
            if(root1 == nullptr && root2 == nullptr) return true;
            if(root1 == nullptr || root2 == nullptr) return false;
            return (root1->val == root2->val) && areMirrors(root1->left, root2->right) && areMirrors(root1->right, root2->left);      
        }

        /*
        leastCommonAncestor: the lowest node in the tree that is the ancestor of both two given nodes
        condition: two given nodes must be in tree or both of them are not in tree
        */
        static Node* leastCommonAncestor(Node* root, int val1, int val2)
        {
            if(root == nullptr) return nullptr;
            if(root->val == val1 || root->val == val2) return root;
            Node* left = leastCommonAncestor(root->left, val1, val2);
            Node* right = leastCommonAncestor(root->right, val1, val2);
            if(left != nullptr && right != nullptr) return root;
            if(left != nullptr && right == nullptr) return left;
            if(right != nullptr && left == nullptr) return right;
            return nullptr;
        }


        /*
        for example:
        preOrder: 1 2 4 5 3 6
        inOrder: 4 2 5 1 6 3
        => tree:
                        1
                    2       3
                  4   5    6
        */

        static int searchNodeInInorder(std::vector<int> inOrder, int searchNode)
        {
            for(int i=0; i<inOrder.size(); ++i)
            {
                if(inOrder[i] == searchNode) return i;
            }
            return -1;
        }

        static Node* buildBinaryTree(std::vector<int> preOrder, std::vector<int> inOrder, int* preOrderIndex)
        {
            if(inOrder.size() == 0) return nullptr;
            Node* node = new Node(preOrder[*preOrderIndex]);
            int inOrderIndex = searchNodeInInorder(inOrder, preOrder[*preOrderIndex]);
            std::vector<int> left(inOrder.begin(), inOrder.begin() + inOrderIndex);
            if(left.size() != 0)
            {
                ++(*preOrderIndex);
            }
            node->left = buildBinaryTree(preOrder, left , preOrderIndex);
            std::vector<int> right(inOrder.begin() + inOrderIndex + 1, inOrder.begin() + inOrder.size());
            if(right.size() != 0)
            {
                ++(*preOrderIndex);
            }
            node->right = buildBinaryTree(preOrder, right, preOrderIndex);
            return node;
        }



        // /**
        //  * Definition for a binary tree node.
        //  * struct TreeNode {
        //  *     int val;
        //  *     TreeNode *left;
        //  *     TreeNode *right;
        //  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
        //  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        //  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
        //  * };
        //  */
        // class Solution {
        // public:

        //     int searchInorderIndex(vector<int>& inorder, int searchNode)
        //     {
        //         for(int i=0; i<inorder.size(); ++i)
        //         {
        //             if(inorder[i] == searchNode) return i;
        //         }
        //         return -1;
        //     }

        //     std::vector<int> getVectorLeft(std::vector<int> inorder, int index)
        //     {   
        //         std::vector<int> v;
        //         if(index==0) return v;
        //         for(int i=0; i<=index-1; ++i) v.push_back(inorder[i]);
        //         return v;
        //     }

        //     std::vector<int> getVectorRight(std::vector<int> inorder, int index)
        //     {   
        //         std::vector<int> v;
        //         if(index==inorder.size()-1) return v;
        //         for(int i=index; i<inorder.size(); ++i) v.push_back(inorder[i]);
        //         return v;
        //     }

        //     TreeNode* helper(vector<int> preorder, vector<int> inorder, int* preorderIndex)
        //     {
        //         if(inorder.size() == 0) return nullptr;
        //         TreeNode* node = new TreeNode(preorder[*preorderIndex]);
        //         int inorderIndex = searchInorderIndex(inorder, preorder[*preorderIndex]);
        //         vector<int> left = getVectorLeft(inorder, inorderIndex);
        //         if(left.size() != 0) ++(*preorderIndex);
        //         node->left = helper(preorder, left, preorderIndex);
        //         vector<int> right = getVectorRight(inorder, inorderIndex);
        //         if(right.size() != 0) ++(*preorderIndex);
        //         node->right = helper(preorder, right, preorderIndex);
        //         return node;
        //     }

        //     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
        //     {
        //         int preorderIndex = 0;
        //         return helper(preorder, inorder, &preorderIndex);
        //     }
        // };
};