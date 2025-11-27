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
void flattenTree(Node* root, Node*& nr){
    if (!root) return;
    flattenTree(root->right, nr);  
    flattenTree(root->left, nr);   
    root->left = nullptr;      
    root->right = nr;        
    nr = root;                   
}
Node* mergeLinked(Node* r1, Node* r2){
    if (!r1) return r2;  
    if (!r2) return r1; 
    Node* ans = nullptr;
    if (r1->v <= r2->v){
        ans = r1;
        r1 = r1->right;  
    }
    else{
        ans = r2;
        r2 = r2->right;  
    }
    Node* temp = ans; 
    while (r1 && r2){
        if (r1->v <= r2->v){
            temp->right = r1; 
            r1 = r1->right; 
        }
        else {
            temp->right = r2; 
            r2 = r2->right;   
        }
        temp = temp->right;
    }
    if (r1) temp->right = r1;
    if (r2) temp->right = r2;
    return ans;
}
int main(){
}
