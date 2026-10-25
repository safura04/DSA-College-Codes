#include <iostream>
#include <stack>
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
    return root; // duplicate values are ignored
}

void inorderNonRecursive(Node* root) {
    stack<Node*> st;
    Node* current = root;

    while (current != NULL || !st.empty()) {
        while (current != NULL) {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        cout << current->data << ' ';
        current = current->right;
    }
}

void preorderNonRecursive(Node* root) {
    if (root == NULL) return;
    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* current = st.top();
        st.pop();
        cout << current->data << ' ';

        // Push right first so left is processed first.
        if (current->right != NULL) st.push(current->right);
        if (current->left != NULL) st.push(current->left);
    }
}

void deleteTree(Node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node* root = NULL;
    int n, value;

    cout << "Enter number of values: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Enter value: ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "Inorder (non-recursive): ";
    inorderNonRecursive(root);
    cout << "\nPreorder (non-recursive): ";
    preorderNonRecursive(root);
    cout << '\n';

    deleteTree(root);
    return 0;
}
