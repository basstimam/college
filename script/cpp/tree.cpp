/*
Algoritma dan Struktur Data
Muhammad Imam Fahrudin
065121077
*/

#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void preorderTraversal(struct Node *node){
    if(node == NULL){
        return;
    }

    cout << node->val << "->";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void printTree(const string &prefix, const Node *node, bool isLeft)
{
    if (node != NULL)
        {
            cout << prefix;

            cout << (isLeft ? "├──" : "└──");

            cout << node->val << endl;

            auto icon = isLeft ? "├──" : "└──";

            printTree(prefix + (isLeft ? "│   " : "    "), node->left, true);
            printTree(prefix + (isLeft ? "│   " : "    "), node->right, false);
            
        }
}



int main(){
    Node *root = new Node(1);


    //left subtree
    root->left = new Node(3);
    root->left->left = new Node(8);
    root->left->right = new Node(2);
    root->left->right->right = new Node(11);
    root->left->left->left = new Node(10);
    root->left->left->right = new Node(13);
    root->left->left->left->left = new Node(14);
    root->left->left->left->right = new Node(6);

    //right subtree
    root->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    root->right->right->left = new Node(4);
    root->right->right->right = new Node(12);

printTree("", root, false);

cout << "Preorder Traversal: ";
    preorderTraversal(root);


}

