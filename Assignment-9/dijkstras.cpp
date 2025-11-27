#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dijkstras(vector<vector<int>>& mat, int n, int m) {
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
    distance[0][0] = mat[0][0];
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({mat[0][0], 0, 0});
    int ux[] = {-1, 0, 1, 0};
    int uy[] = {0, 1, 0, -1};
    while (!pq.empty()) {
        auto e = pq.top(); 
        pq.pop();
        int dist = e[0];
        int i = e[1];
        int j = e[2];
        if (dist > distance[i][j]) continue;
        for (int k = 0; k < 4; k++) {
            int newx = i + ux[k];
            int newy = j + uy[k];
            if (newx >= 0 && newx < n && newy >= 0 && newy < m) {
                int newDist = distance[i][j] + mat[newx][newy];

                if (newDist < distance[newx][newy]) {
                    distance[newx][newy] = newDist;
                    pq.push({newDist, newx, newy});
                }
            }
        }
    }

    return distance[n - 1][m - 1]; 
}
int main() {
    int n, m;cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    cout << dijkstras(mat, n, m) << endl;
}
