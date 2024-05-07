
#include <bits/stdc++.h>
using namespace std;

// Node structure for threaded binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;
    bool rightThread;

    Node(int value) : data(value), left(nullptr), right(nullptr), rightThread(false) {}
};

// Function to insert a new node in the threaded binary search tree
Node* insert(Node* root, int data) {
    Node* newNode = new Node(data);
    if (!root)
        return newNode;

    Node* current = root;
    while (true) {
        if (data < current->data) {
            if (current->left)
                current = current->left;
            else {
                current->left = newNode;
                newNode->right = current;
                newNode->rightThread = true;
                return root;
            }
        } else {
            if (current->rightThread || !current->right) {
                newNode->right = current->right;
                newNode->rightThread = current->rightThread;
                current->right = newNode;
                current->rightThread = true;
                return root;
            }
            current = current->right;
        }
    }
}

// Function to perform inorder traversal of threaded binary search tree
void inorderTraversal(Node* root) {
    if (!root)
        return;

    Node* current = root;
    while (current->left)
        current = current->left;

    while (current) {
        cout << current->data << " ";
        if (current->rightThread)
            current = current->right;
        else {
            current = current->right;
            while (current && !current->left)
                current = current->left;
        }
    }
}

int main() {
    Node* root = nullptr;

    // Inserting nodes
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 9);

    // Inorder traversal
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}