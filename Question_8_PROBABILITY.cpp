//Code:
#include <iostream>
#include <limits.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int k) {
        key = k;
        left = right = NULL;
    }
};
int findOptimalRoot(int keys[], int freq[], int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) { sum += freq[i]; }
    int minCost = INT_MAX, cost;
    for (int i = start; i <= end; i++) {
        cost = sum + ((i > start) ? findOptimalRoot(keys, freq, start, i - 1) : 0) + ((i < end) ? findOptimalRoot(keys, freq, i + 1, end) : 0);
        if (cost < minCost) minCost = cost;
    }
    return minCost;
}
Node* buildOptimalBST(int keys[], int freq[], int start, int end) {
    if (start > end) {
        return NULL;
    }
    int minIdx, minCost = INT_MAX, cost;
    for (int i = start; i <= end; i++) {
        cost = findOptimalRoot(keys, freq, start, end);
        if (cost < minCost) {
            minCost = cost;
            minIdx = i;
        }
    }
    Node *root = new Node(keys[minIdx]);
    root->left = buildOptimalBST(keys, freq, start, minIdx - 1);
    root->right = buildOptimalBST(keys, freq, minIdx + 1, end);
    return root;
}
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}

int main() {
    int ks;
    cout<<"Enter number of keys:";
    cin>>ks;
    cout<<"Enter keys:";
    int keys[ks];
    for(int i=0;i<ks;i++) { cin>>keys[i]; }
    int freq[ks];
    cout<<"Enter frequencies of keys:";
    for(int i=0;i<ks;i++){ cin>>freq[i]; }
    int n = sizeof(keys)/sizeof(keys[0]);
    Node* root = buildOptimalBST(keys, freq, 0, n - 1);
    cout << "Inorder traversal of the optimal binary search tree: ";
    inorderTraversal(root);
    return 0;
}
/*
Output:
Enter number of keys:5
Enter keys:10 20 30 40 50
Enter frequencies of keys:34 8 50 23 47
Inorder traversal of the optimal binary search tree: 10 20 30 40 50
*/