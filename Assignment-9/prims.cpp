#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, in;cin >> n >> in;  
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < in; i++) {
        int w, u, v;cin >> w >> u >> v;  
        graph[u].push_back({w, v}); 
        graph[v].push_back({w, u}); 
    }
    vector<vector<int>> mst; 
    vector<int> visited(n, 0);  
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    visited[0] = 1;  
    for (auto edge : graph[0]){
        pq.push(edge); 
    }
    int mst_edges = 0;
    while (!pq.empty() && mst_edges < n - 1) {
        auto edge = pq.top();
        pq.pop();
        int weight = edge.first;
        int u = 0; 
        if (visited[edge.second])continue; 
        visited[edge.second] = 1;  
        mst.push_back({weight, u, edge.second});  
        mst_edges++;
        for (auto neighbor : graph[edge.second]) {
            if (!visited[neighbor.second]){
                pq.push(neighbor);  
            }
        }
    }
    for (const auto& edge : mst) {
        cout << edge[0] << " " << edge[1] << " " << edge[2] << endl;  
    }
}
