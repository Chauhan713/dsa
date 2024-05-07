#include <iostream>
#include <stack>

using namespace std;

// Node structure for binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a node into binary search tree
Node* insert(Node* root, int data) {
    if (!root)
        return new Node(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to convert binary search tree to inorder threaded binary search tree
void convertToThreadedBST(Node* root, Node*& prev) {
    if (!root)
        return;

    convertToThreadedBST(root->left, prev);

    if (!root->left) {
        root->left = prev;
        root->right = nullptr;
    }

    if (prev && !prev->right)
        prev->right = root;

    prev = root;

    convertToThreadedBST(root->right, prev);
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
        if (!current->right)
            break;
        current = current->right;
    }
}

int main() {
    Node* root = nullptr;

    // Inserting nodes into binary search tree
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 4);
    insert(root, 6);
    insert(root, 9);

    // Converting BST to threaded BST
    Node* prev = nullptr;
    convertToThreadedBST(root, prev);

    // Inorder traversal of threaded BST
    cout << "Inorder Traversal of Threaded BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
