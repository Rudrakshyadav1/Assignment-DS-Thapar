#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Node{
    public:
    int v;
    Node*left;
    Node*right;
    Node(int v){
        this->v = v; 
        this->left = nullptr;
        this->right = nullptr;
    }
};

vector<ll> ans;

void solve(Node* h, int l){
    if(!h) return; 
    if(ans.size() == l) {
        ans.push_back(h->v);
    }
    solve(h->right, l + 1);
    solve(h->left, l + 1);
}

int main(){
}
