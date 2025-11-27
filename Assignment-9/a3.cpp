#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> dijkstras(vector<vector<pair<ll,ll>>> &mat, int v, int k){  
    vector<ll> d(v, LLONG_MAX);                                     
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq; 
    pq.push({0,k});
    d[k]=0; 
    while(!pq.empty()){
        auto t = pq.top(); pq.pop();
        ll w = t.first;
        ll ver = t.second;
        if(w > d[ver]) continue; 
        for(auto it : mat[ver]){
            ll nxt = it.first;
            ll wt  = it.second;
            if(w + wt < d[nxt]){                                        
                d[nxt] = w + wt;
                pq.push({d[nxt], nxt});
            }
        }
    }
    for(ll i=0; i<d.size(); i++)
        if(d[i] == LLONG_MAX) d[i] = -1;

    return d;                                                          
}
int main(){
    int v,e; cin >> v >> e;
    vector<vector<pair<ll,ll>>> mat(v);                                
    for(ll i=0; i<e; i++){                                       
        int u, vv, w;
        cin >> u >> vv >> w;
        mat[u].push_back({vv,w});
        mat[vv].push_back({u,w});
    }
    int k; cin >> k;
    vector<ll> time = dijkstras(mat, v, k);                          
}
