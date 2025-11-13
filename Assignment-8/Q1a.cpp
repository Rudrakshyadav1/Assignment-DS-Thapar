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
bool isLeaf(Node* head){
    return head && !head->left && !head->right;
}
void sumLeftLeaves(Node* h, int &ans){
    if (!h) return; 
    if (isLeaf(h->left)){
        ans += h->left->v;
    }
    sumLeftLeaves(h->left, ans);
    sumLeftLeaves(h->right, ans);
}
int main(){
}
