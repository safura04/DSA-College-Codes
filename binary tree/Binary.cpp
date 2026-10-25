#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

Node* createTree() {
    int value;
    cout << "Enter node value (-1 for no node): ";
    cin >> value;

    if (value == -1)
        return NULL;

    Node* root = new Node(value);
    cout << "Left child of " << value << ":\n";
    root->left = createTree();
    cout << "Right child of " << value << ":\n";
    root->right = createTree();
    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << ' ';
}

void deleteTree(Node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    cout << "Create a binary tree in preorder order.\n";
    cout << "Enter -1 whenever a child is absent.\n";
    Node* root = createTree();

    cout << "\nInorder (Left, Root, Right): ";
    inorder(root);
    cout << "\nPreorder (Root, Left, Right): ";
    preorder(root);
    cout << "\nPostorder (Left, Right, Root): ";
    postorder(root);
    cout << '\n';

    deleteTree(root);
    return 0;
}
