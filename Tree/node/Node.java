package node;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;
import java.util.Stack;
import java.util.Vector;

import javax.swing.AbstractAction;

public class Node
{
    public Node leftNode;
    public int val;
    public Node rightNode;
    public Node()
    {   
    }

    public Node(int val)
    {
        this.val = val;
    }

    public Node(int val, Node leftNode, Node rightNode)
    {
        this.val = val;
        this.leftNode = leftNode;
        this.rightNode = rightNode;
    }

    public static void levelTraversal(Node root)
    {
        Deque<Node> q = new ArrayDeque<>();
        Node temp = root;
        q.addLast(temp);
        while(q.size() != 0)
        {
            temp = q.removeFirst();
            System.out.print(temp.val + " ");
            if(temp.leftNode != null)
            {
                q.addLast(temp.leftNode);
            }
            if(temp.rightNode != null)
            {
                q.addLast(temp.rightNode);
            }
        }
        System.out.println();
    }


    //using level order traversal
    public static int findingTheMaximumElementWithoutRecursion(Node root)
    {
        int max = -1;
        Deque<Node> q = new ArrayDeque<>();
        if(root != null)
        {
            q.addLast(root);
        }
        while(q.size() != 0)
        {
            Node temp = q.removeFirst();
            if(max <= temp.val)
            {
                max = temp.val;
            }
            if(temp.leftNode != null)
            {
                q.addLast(temp.leftNode);
            }
            if(temp.rightNode != null)
            {
                q.addLast(temp.rightNode);
            }
        }
        return max;
    }

    //return 1 if found 0 if not
    public static int findInBinaryTreeUsingRecursion(Node root, int data)
    {
        int temp = 0;
        if(root == null)
        {
            return 0;
        }
        else
        {
            if(root.val == data)
            {
                return 1;
            }
            else
            {
                temp = findInBinaryTreeUsingRecursion(root.leftNode, data);
                if(temp != 0)
                {
                    return temp;
                }
                else
                {
                    return findInBinaryTreeUsingRecursion(root.rightNode, data);
                }
            }
        }
    }

    //return 1 if found 0 
    //using level order traversal
    public static int findInBinaryTreeWithoutRecursion(Node root, int data)
    {
        Deque<Node> d = new ArrayDeque<>();
        if(root == null)
        {
            return 0;
        }
        else
        {
            d.addLast(root);
            while(d.size() != 0)
            {
                Node temp = d.removeLast();
                if(temp.val == data)
                {
                    return 1;
                }
                if(temp.leftNode != null)
                {
                    d.addLast(temp.leftNode);
                }
                if(temp.rightNode != null)
                {
                    d.addLast(temp.rightNode);
                }
            }
        }
        return 0;
    }


    //using level order traversal to travel through the tree to find the null node and insert value into that 
    public static Node insertInBinaryTree(Node root, int val)
    {
        Deque<Node> d = new ArrayDeque<>();
        if(root == null)
        {
            root = new Node(val);
            levelTraversal(root);
            return root;
        }
        else
        {
            d.addLast(root);
            while(d.size() != 0)
            {
                Node temp = d.removeFirst();
                if(temp.leftNode == null)
                {
                    temp.leftNode = new Node(val);
                    return root;
                }
                else
                {
                    d.addLast(temp.leftNode);
                }
                if(temp.rightNode == null)
                {
                    temp.rightNode = new Node(val);
                    return root;
                }
                else
                {
                    d.addLast(temp.rightNode);
                }
            }
        }

        levelTraversal(root);
        return root;
    }

    public static int sizeOfBinaryTreeUsingRecursion(Node root)
    {
        if(root == null)
        {
            return 0;
        }
        return 1 + sizeOfBinaryTreeUsingRecursion(root.leftNode) + sizeOfBinaryTreeUsingRecursion(root.rightNode);
    }

    public static int sizeOfBinaryTreeWithourRecursionUsingLevelTraversal(Node root)
    {
        Deque<Node> d = new ArrayDeque<>();
        if(root == null)
        {
            return 0;
        }
        int num = 0;
        d.addLast(root);
        while(d.size() != 0)
        {
            Node temp = d.removeFirst();
            ++num;
            if(temp.leftNode != null)
            {
                d.addLast(temp.leftNode);
            }
            if(temp.rightNode != null)
            {
                d.addLast(temp.rightNode);
            }
        }
        return num;
    }


    /*
     * Using Stack to store each level, in each level store from right to left
     */
    public static void levelOrderTraversalInReverse(Node root)
    {
        if(root == null)
        {
            return;
        }
        List<Node> s = new ArrayList<>();
        Deque<Node> q = new ArrayDeque<>();
        q.addLast(root);
        s.addLast(root);
        while(q.size() != 0)
        {
            Node temp = q.removeFirst();
            if(temp.rightNode != null)
            {
                q.addLast(temp.rightNode);
                s.addLast(temp.rightNode);
            }
            if(temp.leftNode != null)
            {
                q.addLast(temp.leftNode);
                s.addLast(temp.leftNode);
            }
        }

        while(s.size() != 0)
        {
            Node temp = s.removeLast();
            System.out.print(temp.val);
        }
        System.out.println();
        
    }

    public static void preOrderTraversal(Node root)
    {
        if(root == null)
        {
            return;
        }
        List<Node> l = new ArrayList<>();
        Node temp = root;
        Node currentNode;
        while(true)
        {
            while(temp != null)
            {
                l.addLast(temp);
                temp = temp.leftNode;
            }
            if(l.size() == 0)
            {
                break;
            }
            currentNode = l.removeLast();
            System.out.print(currentNode.val);
            temp = currentNode.rightNode;
        }
    }

    // public void preOrderTraversal() <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
}