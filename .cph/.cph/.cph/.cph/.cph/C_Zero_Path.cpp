#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;

        vector<vector<int>> mat(n + 1, vector<int>(m + 1));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) cin >> mat[i][j];
        }

        vector<vector<vector<int>>> vis(n + 1, vector<vector<int>>(m + 1, vector<int>(INT_MAX, INT_MIN)));

        queue<pair<int,int>> q;
        //q.push({1,1});

        vis[1][1][0] = mat[1][1];
        vis[1][1][1] = mat[1][1];

        cout << "flag1" << '\n';

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            
            if(x < n) {

                if(vis[x+1][y][0] > mat[x+1][y] + vis[x][y][0] || vis[x+1][y][1] < mat[x+1][y] + vis[x][y][1]) q.push({x + 1, y});
                if(vis[x+1][y][0] > mat[x+1][y] + vis[x][y][0]) {
                    vis[x+1][y][0] = mat[x+1][y] + vis[x][y][0];
                }
                if(vis[x+1][y][1] < mat[x+1][y] + vis[x][y][1]) {
                    vis[x+1][y][1] = mat[x+1][y] + vis[x][y][1];
                }
            }
            if(y < m) {

                if(vis[x][y+1][0] > mat[x][y+1] + vis[x][y][0] || vis[x][y+1][1] < mat[x][y+1] + vis[x][y][1]) q.push({x, y + 1});
                if(vis[x][y+1][0] > mat[x][y+1] + vis[x][y][0]) {
                    vis[x][y+1][0] = mat[x][y+1] + vis[x][y][0];
                }
                if(vis[x][y+1][1] < mat[x][y+1] + vis[x][y][1]) {
                    vis[x][y+1][1] = mat[x][y+1] + vis[x][y][1];
                }
            }
        }

        if(vis[n][m][0] <= 0 && vis[n][m][1] >= 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';

    }
    return 0;
}