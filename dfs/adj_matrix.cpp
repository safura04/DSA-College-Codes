#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int value) {
    if (root == NULL) return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

Node* copyTree(Node* root) {
    if (root == NULL) return NULL;
    Node* copy = new Node(root->data);
    copy->left = copyTree(root->left);
    copy->right = copyTree(root->right);
    return copy;
}

void levelOrder(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty.\n";
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int levelCount = (int)q.size();
        while (levelCount--) {
            Node* current = q.front();
            q.pop();
            cout << current->data << ' ';
            if (current->left != NULL) q.push(current->left);
            if (current->right != NULL) q.push(current->right);
        }
        cout << '\n';
    }
}

int heightEdges(Node* root) {
    if (root == NULL) return -1;
    return 1 + max(heightEdges(root->left), heightEdges(root->right));
}

void printLeaves(Node* root) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        cout << root->data << ' ';
        return;
    }
    printLeaves(root->left);
    printLeaves(root->right);
}

void deleteTree(Node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node* original = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Enter value: ";
        cin >> value;
        original = insert(original, value);
    }

    // Make an independent copy of the original BST.
    Node* newTree = copyTree(original);

    cout << "\nOriginal BST level-wise:\n";
    levelOrder(original);
    cout << "New (copied) BST level-wise:\n";
    levelOrder(newTree);

    cout << "Height of original BST (edges): " << heightEdges(original) << '\n';
    cout << "Leaf nodes: ";
    printLeaves(original);
    cout << '\n';

    deleteTree(original);
    deleteTree(newTree);
    return 0;
}
