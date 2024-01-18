#pragma once
#include <iostream>
#include <deque>
#include <vector>
#include <stack>




class Node
{
    public:
        int val;
        Node* left;
        Node* right;

        Node() : val(0), right(nullptr), left(nullptr)
        {
            
        }
        
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