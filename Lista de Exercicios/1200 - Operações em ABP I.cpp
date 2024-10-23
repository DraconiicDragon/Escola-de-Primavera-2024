#include <iostream>

using namespace std;

bool first;

struct Node {
    char key;
    Node* left;
    Node* right;

    Node(char item) {
        key = item;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* node, char key) {
    if(node == NULL) 
        return new Node(key);
    if(key >= node->key)
        node->right = insert(node->right, key);
    else
        node->left = insert(node->left, key);
    return node;
}

Node* search(Node* node, char key) {
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

Node* deleteNode(Node* node, char key) {
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

    if(first) first = false;
    else cout << " ";
    cout << node->key;

    printInorder(node->right);
}

void printPreorder(Node* node) {
    if(node == NULL)
        return;

    if(first) first = false;
    else cout << " ";
    cout << node->key;

    printPreorder(node->left);
    printPreorder(node->right);
}

void printPosoder(Node* node) {
    if(node == NULL)
        return;

    printPosoder(node->left);
    printPosoder(node->right);

    if(first) first = false;
    else cout << " ";
    cout << node->key; 
}

int main() {
    Node* root = NULL;
    string comando;
    char letra;

    while(cin >> comando) {

        if(comando == "I") {
            cin >> letra;
            root = insert(root, letra);
            continue;
        }

        if(comando == "P") {
            cin >> letra;
            if(search(root, letra) != NULL)
                cout << letra << " existe" << endl; 
            else
                cout << letra << " nao existe" << endl;
            continue;
        }

        if(comando == "INFIXA") {
            first = true;
            printInorder(root);
            cout << endl;
            continue;
        }

        if(comando == "PREFIXA") {
            first = true;
            printPreorder(root);
            cout << endl;
            continue;
        }

        if(comando == "POSFIXA") {
            first = true;
            printPosoder(root);
            cout << endl;
            continue;
        }
    }

    return 0;
}