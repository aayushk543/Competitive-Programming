#include<bits/stdc++.h>
using namespace std;

vector<vector<unordered_map<int,int>>> memo;

bool dfs(vector<vector<int>>& mat, int x, int y, int dist) {
    int n = mat.size() - 1;
    int m = mat[0].size() - 1;
    if(x > n || y > m || (n + m - 1) & 1) return false;

    dist += mat[x][y];

    if(memo[x][y].find(dist) != memo[x][y].end()) return memo[x][y][dist];

    if(x == n && y == m && dist == 0) return memo[x][y][0] = true;

    bool x1 = dfs(mat, x + 1, y, dist);
    bool x2 = dfs(mat, x, y + 1, dist);

    return memo[x][y][dist] = x1 || x2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;

        memo.assign(n + 1, vector<unordered_map<int,int>>(m + 1));

        vector<vector<int>> mat(n + 1, vector<int>(m + 1));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) cin >> mat[i][j];
        }

        if(dfs(mat, 1, 1, 0)) cout << "YES" << '\n';
        else cout << "NO" << '\n';

    }
    return 0;
}