#include <iostream>
#include <queue>

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

void eraseTree(Node* node) {
    if(node->left != NULL) {
        eraseTree(node->left);
    }
    if(node->right != NULL) {
        eraseTree(node->right);
    }
    delete node;
}

void bfs(Node* raiz) {
    queue<Node*> fila;
    fila.push(raiz->left);
    fila.push(raiz->right);
    cout << raiz->key;
    while(!fila.empty()) {
        Node* node = fila.front();
        fila.pop();
        if(node == NULL) continue;
        fila.push(node->left);
        fila.push(node->right);
        cout << " " << node->key;
    }
}

int main() {
    int c, n, key;
    cin >> c;

    for(int i = 0; i < c; i++) {
        Node* raiz = NULL;
        cin >> n;      
        for(int j = 0; j < n; j++) {
            cin >> key;
            raiz = insert(raiz, key);
        }
        cout << "Case " << i+1 << ":" << endl;
        bfs(raiz);
        cout << endl << endl;
        eraseTree(raiz);
    }
    return 0;
}