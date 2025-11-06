#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int v;
    Node*left;
    Node*right;
    Node(int v){
        this->v=v; 
    }
};
Node*TreeBuilder(Node*head){
    
}
void Inorder(Node*head){
    //LNR
    if(!head)return;
    Inorder(head->left); 
    cout<<head->v;
    Inorder(head->right);
}
void Preorder(Node*head){
    //NLR
    if(!head)return;
    cout<<head->v;
    Preorder(head->left); 
    Preorder(head->right);
}
void Postorder(Node*head){
    //LRN
    if(!head)return;
    Postorder(head->left); 
    Postorder(head->right);
    cout<<head->v;
}
int main(){

}