#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int v;
    Node* left;
    Node* right;
    Node(int v) {
        this->v = v;
        left = right = nullptr;
    }
};
Node* TreeBuilder(Node* head, int v){
    if (!head) return new Node(v);
    if (v < head->v)
        head->left = TreeBuilder(head->left, v);
    else
        head->right = TreeBuilder(head->right, v);
    return head;
}
void insertion(Node*& h, int v) {
    if (!h){
        h = new Node(v);
        return;
    }
    if (v < h->v){
        insertion(h->left, v);
    }
    else{
        insertion(h->right, v);
    }
}
int maxDepth(Node*h){
    if(!h) return 0;
    return 1+max(maxDepth(h->left),maxDepth(h->right));
}
int minDepth(Node* h){
    if (!h) return 0;
    if (!h->left) return 1 + minDepth(h->right);
    if (!h->right) return 1 + minDepth(h->left);
    return 1 + min(minDepth(h->left), minDepth(h->right));
}
bool isBST(Node* root,int minVal = INT_MIN,int maxVal =INT_MAX){
    if (!root) return true;
    if (root->v <= minVal || root->v >= maxVal) return false;
    return isBST(root->left, minVal, root->v) &&
           isBST(root->right, root->v, maxVal);
}
int main(){
}
