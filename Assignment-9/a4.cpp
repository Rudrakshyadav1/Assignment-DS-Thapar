#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void dfs(vector<vector<int>>& mat, int ix, int jy, vector<vector<int>>& isvisited){
    int n = mat.size();
    int m = mat[0].size();
    vector<int> ux = {-1, 0, 1, 0};
    vector<int> uy = {0, 1, 0, -1};
    isvisited[ix][jy] = 1;
    for (int i = 0; i < 4; i++){
        int newX = ix + ux[i], newY = jy + uy[i];
        if (newX >= 0 && newX < n && newY >= 0 && newY < m && !isvisited[newX][newY] && mat[newX][newY] == 1){
            dfs(mat, newX, newY, isvisited); 
        }
    }
}
void bfs(vector<vector<int>>& mat, int ix, int jy, vector<vector<int>>& isvisited){
    int n = isvisited.size();
    int m = isvisited[0].size();
    queue<pair<int, int>> pq;
    pq.push({ix, jy});
    isvisited[ix][jy] = 1;  
    vector<int> ux = {-1, 0, 1, 0};
    vector<int> uy = {0, 1, 0, -1};
    while (!pq.empty()) {
        auto t = pq.front(); pq.pop();
        int x = t.first, y = t.second;
        for (int i = 0; i < 4; i++) {
            int newX = x + ux[i], newY = y + uy[i];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && !isvisited[newX][newY] && mat[newX][newY] == 1){
                isvisited[newX][newY] = 1;  
                pq.push({newX, newY});  
            }
        }
    }
}
int main() {
    int n, m;cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    vector<vector<int>> isvisited(n, vector<int>(m, 0));
    int c = 0;  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1 && !isvisited[i][j]){ 
                bfs(mat, i, j, isvisited);  
                c++;  
            }
        }
    }
    cout << "Number of connected components: " << c << endl;
}
