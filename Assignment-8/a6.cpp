#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Node {
public:
    int v;
    Node* left;
    Node* right;
    Node(int v) {
        this->v = v; 
        this->left = nullptr;
        this->right = nullptr;
    }
};
int findPos(int e, vector<int>& inorder) {
    for (int i = 0; i < inorder.size(); i++) {
        if (e == inorder[i]) return i;
    }
    return -1;
}
Node* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int& index, int s, int e) {
    if (s > e) return nullptr;
    int rootVal = postorder[index--];
    Node* root = new Node(rootVal);
    int pos = findPos(rootVal, inorder);
    root->right = buildTreeHelper(inorder, postorder, index, pos + 1, e);
    root->left = buildTreeHelper(inorder, postorder, index, s, pos - 1);
    return root;
}
int main(){
}
