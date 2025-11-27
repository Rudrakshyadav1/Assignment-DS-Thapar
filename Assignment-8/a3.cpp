#include <bits/stdc++.h>
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
int maxdepth(Node*h){
    if(!h) return 0;
    return 1+max(maxdepth(h->left),maxdepth(h->right));
}
int main(){

}
