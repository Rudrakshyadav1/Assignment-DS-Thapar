#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void dfs(int i, vector<vector<int>>& mat, vector<int>& isvisited) {
    isvisited[i] = 1;
    for (auto it : mat[i]) {
        if (!isvisited[it]) {
            dfs(it, mat, isvisited); 
        }
    }
}
int main(){
    int n, e; cin >> n >> e;  
    vector<vector<int>> mat(n);  
    for (int i = 0; i < e; i++) {
        int u, v; 
        cin >> u >> v;
        mat[u].push_back(v);
        mat[v].push_back(u); 
    }
    int c=0;
    vector<int> isvisited(n, 0); 
    for (int i = 0; i < n; i++) {
        if (!isvisited[i]){  
            c++;  
            dfs(i, mat, isvisited); 
        }
    }
    cout << c << endl;
}
