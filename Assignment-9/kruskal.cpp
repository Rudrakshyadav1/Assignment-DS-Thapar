#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class disjoint{
    vector<int> size, parent;
public:
    disjoint(int n){
        size.resize(n + 1, 1);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }
    int findParent(int n){
        if (parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);  
    }
    void uni(int u, int v) {
        int root_u = findParent(u);
        int root_v = findParent(v);
        if (root_u != root_v){
            if (size[root_u] >= size[root_v]){
                size[root_u] += size[root_v];
                parent[root_v] = root_u;
            }
            else{
                size[root_v] += size[root_u];
                parent[root_u] = root_v;
            }
        }
    }
};
int main() {
    int n;cin >> n;  
    disjoint du(n);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (int i = 0; i < n; i++){
        int w, u, v; 
        cin >> w >> u >> v;
        pq.push({w, u, v});
    }
    vector<vector<int>> mst;
    while (!pq.empty()) {
        auto edge = pq.top(); pq.pop();
        int w = edge[0], u = edge[1], v = edge[2];
        if (du.findParent(u) != du.findParent(v)) {
            du.uni(u, v);
            mst.push_back({w, u, v});
        }
    }
    for (const auto& edge : mst){
        cout << edge[0] << " " << edge[1] << " " << edge[2] << endl;
    }
}
