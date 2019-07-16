#include "BasicTree.h"
#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;

class val_not_found{};

BasicTree::BasicTree() : root{nullptr} {}
BasicTree::BasicTree(int i) : root{new Node(i)} {}

void BasicTree::insert(int val)
{
    // 1. Check whether the tree is empty or not;
    if (root == nullptr)
    {
        // 2a. if the tree is empty set root equal to a new node with the passed value and return.
        root = new Node(val);
        root->left = nullptr;
        root->right = nullptr;
    }
    else
    {
        Node *parent = nullptr;
        Node* currNode = root;
        while (currNode != nullptr)
        {
            parent = currNode;
            if(val < currNode->data)
            {
                currNode = currNode->left;
            }
            else
            {
                currNode = currNode->right;
            }
        }
        if(val < parent->data)
        {
            parent->left = new Node(val);
            currNode = parent->left;
            currNode->parent = parent;
        }
        else
        {
            parent->right = new Node(val);
            currNode = parent->right;
            currNode->parent = parent;
        }
    }
    // 2b. Otherwise, find the proper location to tag on a new node storing the passed value on to the tree;
    //  be sure to set this node's Node* parent to the node preceding it in the tree.
}

ostream& BasicTree::in_order(Node *n, ostream &os)
{
    // 1. Traverse the left subtree by visiting node to the left of the current node.
    Node *curr = n;

    if(curr->left == nullptr && curr->right == nullptr)
    {
        os << curr->data << " ";
    }
    else if(curr->left == nullptr)
    {
        os << curr->data << " ";
        in_order(curr->right, os);
    }
    else
    {
        in_order(curr->left, os);
        os << curr->data << " ";
        if(curr->right != nullptr)
        {
            in_order(curr->right, os);
            //os << curr->data << "\t";
        }
    }

    /*while(curr->left != nullptr) //going all the way to the end of the left branch
    {
        curr = curr->left;
    }
    cout << curr->data;

    while(curr != nullptr)
    {
        os << curr->data << " ";
        if(curr->left != nullptr)
        {
            curr = curr->left;
            cout << curr->data;
        }
        else if(curr->right != nullptr)
        {
            cu
        }
        else
        {
            curr = curr->parent;
            cout << curr->data;
        }
    }*/
    // 2. Visit the current node; insert its value to the stream.

    // 3. Traverse the right subtree by visiting node to the right of the current node.

    // 4. Return the stream
    return os;
}

ostream& BasicTree::post_order(Node *n, ostream &os)
{
    Node *curr = n;

    if(curr->left == nullptr && curr->right == nullptr)
    {
        os << curr->data << " ";
    }
    else if(curr->left != nullptr && curr->right != nullptr)
    {
        post_order(curr->left, os);
        post_order(curr->right, os);
        os << curr->data << " ";
    }
    else if(curr->left == nullptr)
    {
        post_order(curr->right,os);
        os << curr->data << " ";
    }
    else
    {
        post_order(curr->left, os);
        os << curr->data << " ";
    }

    // 1. Traverse the left subtree by visiting node to the left of the current node.

    // 2. Traverse the right subtree by visiting the node to the right of the current node.

    // 3. Visit the current node; insert its value to the stream.

    // 4. Return the stream
    return os;
}

ostream& BasicTree::pre_order(Node *n, ostream &os)
{
    Node *curr = n;

    if(curr->left == nullptr && curr->right == nullptr)
    {
        os << curr->data << " ";
    }
    else if(curr->left != nullptr && curr->right != nullptr)
    {
        os << curr->data << " ";
        pre_order(curr->left, os);
        pre_order(curr->right, os);
    }
    else if(curr->left == nullptr)
    {
        os << curr->data << " ";
        pre_order(curr->right,os);
    }
    else
    {
        os << curr->data << " ";
        pre_order(curr->left, os);
    }
    // 1. Visit the current node; insert its value to the stream.

    // 2. Traverse the left subtree by visiting node to the left of the current node.

    // 3. Traverse the right subtree by visiting the node to the right of the current node.

    // 4. Return the stream
    return os;
}

int const& BasicTree::find(int val) {
    Node* curr = root;
    bool found = false;
    // 1. Search the tree for node containing val ...
    while (curr != nullptr && !found)
    {
        if(curr->data == val)
        {
            found = true;
        }
        else if(curr->data < val)
        {
            curr = curr->left;
        }
        else 
        {
            curr = curr->right;
        }
    }

    if(!found)
    {
        throw val_not_found();
    }

    return curr->data;
    // 2a. If such node is found, return a constant reference to the int object
    // contained in that node (to do this, simply return curr->val);

    // 2b. Otherwise, if such a node is not found, throw val_not_found{};

}

///////////////////////////////////////////////////////////////////////////////
// operator<< support
///////////////////////////////////////////////////////////////////////////////
stringstream& BasicTree::to_sstream(Node *n, int depth, string s, stringstream& os) const
{
    if (n==nullptr) {
        os << "Empty" << endl;
        return os;
    }
    os << "("<<n->data<<") Address: " << n << " Parent: " << n->parent << "\n";
    os << s << " `--[L]";
    s += " |  ";
    if (n->left)
        to_sstream(n->left, depth + 1, s, os);
    else
        os <<"nullptr\n";
    s.erase(s.end() - 4, s.end());

    os << s << " `--[R]";
    s += "    ";
    if (n->right)
        to_sstream(n->right, depth + 1, s, os);
    else
        os <<"nullptr\n";
    s.erase(s.end() - 4, s.end());
    return os;
}

ostream& operator<<(ostream& os, BasicTree const& bt)
{
    os << bt.to_str();
    return os;
}