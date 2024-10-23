#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int item) {
        key = item;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* node, int key) {
    if(node == NULL) 
        return new Node(key);
    if(key >= node->key)
        node->right = insert(node->right, key);
    else
        node->left = insert(node->left, key);
    return node;
}

Node* search(Node* node, int key) {
    if(node == NULL || node->key == key)
        return node;
    if(key > node->key)
        return search(node->right, key);
    return search(node->left, key);
}

Node* getSuccessor(Node* node) {
    node = node->right;
    while(node->left != NULL && node != NULL)
        node = node->left;
    return node;
}

Node* deleteNode(Node* node, int key) {
    if(node == NULL)
        return node;

    if(key > node->key)
        node->right = deleteNode(node->right, key);
    else if(key < node->key)
        node->left = deleteNode(node->left, key);
    else {

        if(node->left == NULL) {
            Node* temp = node->right;
            delete node;
            return temp; 
        }
        if(node->right == NULL) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* succ = getSuccessor(node);
        node->key = succ->key;
        node->right = deleteNode(node->right, succ->key);
    }
    return node;
}

void printInorder(Node* node) {
    if(node == NULL)
        return;

    printInorder(node->left);
    cout << node->key << " ";
    printInorder(node->right);
}

void printPreorder(Node* node) {
    if(node == NULL)
        return;

    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPosoder(Node* node) {
    if(node == NULL)
        return;

    printPosoder(node->left);
    printPosoder(node->right);
    cout << node->key << " ";
}

int main() {
    Node* root = NULL;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 5);
    root = insert(root, 7);

    if(search(root, 10) != NULL) {
        cout << "found";
    } else {
        cout << "not found";
    }
    
    cout << endl;
    printInorder(root);
    cout << endl;
    printPreorder(root);
    cout << endl;
    printPosoder(root);
}