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
bool Rfinder(Node* head, int v){
    if (!head) return false;
    if (head->v == v) return true;
    if (head->v > v) return Rfinder(head->left, v);
    else return Rfinder(head->right, v);
}
Node* finder(Node* head, int v){
    while (head) {
        if (head->v == v) return head;
        if (head->v > v) head = head->left;
        else head = head->right;
    }
    return nullptr;
}
int maxN(Node* head){
    while (head->right) head = head->right;
    return head->v;
}
int minN(Node* head){
    while (head->left) head = head->left;
    return head->v;
}
void inorder(Node* h, vector<int>& in){
    if (!h) return;
    inorder(h->left, in);
    in.push_back(h->v);
    inorder(h->right, in);
}
Node* inorderPre(Node* root, int v){
    Node* pre = nullptr;
    Node* curr = root;
    while (curr){
        if (v <= curr->v){
            curr = curr->left;
        }
        else {
            pre = curr;  
            curr = curr->right;
        }
    }
    return pre;
}
Node* inorderSuc(Node* root, int v){
    Node* suc = nullptr;
    Node* curr = root;
    while (curr) {
        if (v >= curr->v){
            curr = curr->right;
        }
        else{
            suc = curr; 
            curr = curr->left;
        }
    }
    return suc;
}
int main(){
    Node* root = nullptr;
    vector<int> vals = {5, 3, 7, 2, 4, 6, 8};
    for (int v : vals) root = TreeBuilder(root, v);
    cout << "Inorder predecessor of 6: " << inorderPre(root, 6) << endl;
    cout << "Inorder successor of 6: " << inorderSuc(root, 6) << endl;
}
