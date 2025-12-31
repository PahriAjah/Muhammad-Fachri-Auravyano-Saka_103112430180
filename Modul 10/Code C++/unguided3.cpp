#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// Fungsi untuk menghapus tree (membersihkan memori)
void deleteTree(Node* root) {
    if (root == NULL) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Membangun pohon
    // Membuat node
    Node* root = createNode(6);
    
    // Membuat subtree kiri
    root->left = createNode(4);
    root->left->left = createNode(2);
    root->left->right = createNode(5);
    root->left->left->left = createNode(1);
    root->left->left->right = createNode(3);
    
    // Membuat subtree kanan
    root->right = createNode(7);
    
    // Mencetak hasil traversal
    cout << "Hasil Pre-order traversal: ";
    preOrder(root);
    cout << endl;
    
    cout << "Hasil Post-order traversal: ";
    postOrder(root);
    cout << endl;
    
    deleteTree(root);
    
    return 0;
}