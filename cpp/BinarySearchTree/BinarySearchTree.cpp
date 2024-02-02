#pragma once
#include "TreeNode.cpp"
#include <iostream>
#include <stack>
#include <queue>


class BinarySearchTree
{
    public:

    static void levelTraversal(TreeNode* root)
    {
        std::cout << "Level Traversal: " << "\n";
        if(root == nullptr) return;
        std::deque<TreeNode*> q;
        q.push_back(root);
        while(q.size() != 0)
        {
            TreeNode* temp = q.at(0);
            q.pop_front();
            std::cout << temp->val << " ";
            if(temp->left != nullptr)
            {
                q.push_back(temp->left);
            }
            if(temp->right != nullptr)
            {
                q.push_back(temp->right);
            }
        }
        std::cout << "\n";
        return;
    }

    static void inOrderTraversal(TreeNode* root)
    {
        std::cout << "============INORDER TRAVERSAL============" << "\n";
        if(root == nullptr)
        {
            std::cout << "No elements" << "\n";
        }
        std::stack<TreeNode*> s;
        while(true)
        {
            while(root != nullptr)
            {
                s.push(root);
                root = root->left; 
            }
            if(s.size() == 0) break;
            root = s.top();
            s.pop();
            std::cout << root->val << " ";
            root = root->right;
        }
        std::cout << "\n";
    }

    static TreeNode* find(TreeNode* root, int searchValue)
    {
        if(root == nullptr) return nullptr;
        if(root->val == searchValue) return root;
        if(searchValue < root->val)
        {
            return find(root->left, searchValue);
        }
        if(searchValue > root->val)
        {
            return find(root->right, searchValue);
        }
        return nullptr; //not reach this but this is just for getting rid of warning
    }

    static TreeNode* findMin(TreeNode* root)
    {
        if(root==nullptr) return nullptr;
        while(root->left != nullptr)
        {
            root = root->left;
        }
        return root;
    }

    static TreeNode* findMax(TreeNode* root)    //always return a node, only return nullptr if root = nullptr
    {
        if(root==nullptr) return nullptr;
        while(root->right != nullptr)
        {
            root = root->right;
        }
        return root;
    }

    static TreeNode* insert(TreeNode* root, int insertValue)
    {
        if(root == nullptr)
        {
            return new TreeNode(insertValue);
        }

        TreeNode* temp = root;

        while(root->val != insertValue)
        {
            if(insertValue < root->val)
            {
                if(root->left != nullptr) root = root->left;
                else root->left = new TreeNode(insertValue);
            }
            else if(insertValue > root->val)
            {
                if(root->right != nullptr) root = root->right;
                else root->right = new TreeNode(insertValue);
            } 
        }
        return root;
    }

    static TreeNode* deleteNode(TreeNode* root, int valueToDelete)
    {
        if(root == nullptr) return nullptr;
        TreeNode* returnNode = root;
        //consider the case that root is already the node we need to delete
        if(root->val == valueToDelete)
        {
            if(root->left == nullptr && root->right == nullptr)
            {
                return nullptr;
            }
            else if(root->left != nullptr && root->right != nullptr)
            {
                TreeNode* nodeWithMaxValue = findMax(root->left);
                root->val = nodeWithMaxValue->val;
                root->left = deleteNode(root->left, nodeWithMaxValue->val);
                return root;
            }
            else
            {
                if(root->left != nullptr)
                {
                    return root->left;
                }
                else if(root->right != nullptr)
                {
                    return root->right;
                }
            }
        }
        if(valueToDelete < root->val)
        {
            root->left = deleteNode(root->left, valueToDelete); 
        }
        else 
        {
            root->right = deleteNode(root->right, valueToDelete);
        }
        return root;
    }
};