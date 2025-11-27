#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void bfs(vector<vector<int>>& mat, int s){
    vector<bool>visited(mat.size(), 0);
    queue<int> q;
    visited[s] = 1;
    q.push(s);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        cout<<t<<' ';
        for(int nxt : mat[t]){
            if(!visited[nxt]){
                visited[nxt] = 1;
                q.push(nxt);
            }
        }
    }
}
void dfs(vector<vector<int>>& mat, vector<bool>& visited, int s){
    if (visited[s]) return;
    visited[s]=1;
    cout << s << " ";
    for (auto nxt : mat[s]){
        if (!visited[nxt]){
            dfs(mat, visited, nxt);
        }
    }
}
int main(){
    int n;cin >> n;
    vector<vector<int>> mat(n);   
    for(int i = 0; i < n; i++){
        while(true){
            ll a;
            cin >> a;
            if(a == -1) break;
            mat[i].push_back(a);
        }
    }
    int s;cin>>s;   
    bfs(mat, s);
    vector<bool>visited(mat.size(),0);
}
