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
int findPos(int e, vector<int>& inorder){ // better to use map
    for (int i = 0; i < inorder.size(); i++){
        if (e == inorder[i]) return i;
    }
    return -1;
}
Node* buildTreeHelper(vector<int>& inorder, vector<int>& preorder, int& index, int s, int e) {
    if (index >= preorder.size() || s > e){
        return nullptr;
    }
    int rootVal = preorder[index++];
    Node* root = new Node(rootVal);
    int pos = findPos(rootVal, inorder);
    root->left = buildTreeHelper(inorder, preorder, index, s, pos - 1);
    root->right = buildTreeHelper(inorder, preorder, index, pos + 1, e);
    return root;
}
int main(){
}
