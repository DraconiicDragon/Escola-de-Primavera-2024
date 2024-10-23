#include <iostream>
#include <vector>

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

Node* insert(Node* node, int key, size_t& depth) {
    if(node == NULL) 
        return new Node(key);

    depth++;
    
    if(key >= node->key)
        node->right = insert(node->right, key, depth);
    else
        node->left = insert(node->left, key, depth);
    return node;
}

int main() {
    int n, h;
    cin >> n;
    Node* raiz = NULL;
    vector<int> maiorAltura;
    size_t depth;
    for(int i = 0; i < n; i++) {
        cin >> h;
        depth = 0;
        raiz = insert(raiz, h, depth);
        if(depth >= maiorAltura.size()) {
            maiorAltura.push_back(h);
        } else if(h < maiorAltura[depth]) {
            maiorAltura[depth] = h;
        }
    }
    int tamanho = maiorAltura.size();   
    for(int i = 0; i < tamanho; i++) {
        cout << i << " " << maiorAltura[i] << endl;
    }
}