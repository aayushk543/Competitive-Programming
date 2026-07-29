#include<bits/stdc++.h>
using namespace std;

int start_x, start_y;
int end_x, end_y; 

int ans = INT_MAX;
void bfs(vector<vector<char>>& adj) {
    int n = adj.size();
    int m = adj[0].size();

    queue<tuple<int,int,int,int,int>> q;

    vector<vector<vector<vector<int>>>> vis(n + 1, vector<vector<vector<int>>>(m + 1, vector<vector<int>>(4, vector<int>(4, INT_MAX))));
    q.push({0, start_x, start_y, 0, 0});
    
    vis[start_x][start_y][0][0] = 0;
    

    while(!q.empty()) {
        auto [dist, x, y, direc, count] = q.front();
        q.pop();

        if(vis[x][y][direc][count] != dist) continue;

        if(direc == 0) {

            if(x < n && adj[x+1][y] != '#' && count < 3 && vis[x+1][y][0][count + 1] > dist + 1) {
                vis[x+1][y][0][count + 1] = dist + 1;
                q.push({dist + 1, x + 1, y, 0, count + 1});
            }
            
            if(x > 1 && adj[x-1][y] != '#' && x > 1 && vis[x-1][y][1][1] > 1 + dist) {
                vis[x-1][y][1][1] = dist + 1;
                q.push({dist + 1,x - 1, y, 1, 1});
            }

            if(y < m && adj[x][y+1] != '#' && vis[x][y+1][2][1] > dist + 1) {
                vis[x][y+1][2][1] = dist + 1;
                q.push({dist + 1, x, y + 1, 2, 1});
            }

            if(y > 1 && adj[x][y-1] != '#' && vis[x][y-1][3][1] > dist + 1) {
                vis[x][y-1][3][1] = dist + 1;
                q.push({dist + 1, x, y-1, 3, 1});
            }

        }

        if(direc == 1) {

            if(x > 1 && adj[x-1][y] != '#' && count < 3 && x > 1 && vis[x-1][y][1][count + 1] > dist + 1) {
                vis[x-1][y][1][count + 1] = dist + 1;
                q.push({dist + 1, x - 1, y, 1, count + 1});
            }
            
            if(x < n && adj[x+1][y] != '#' && x < n && vis[x+1][y][0][1] > 1 + dist) {
                vis[x+1][y][0][1] = dist + 1;
                q.push({dist + 1,x + 1, y, 0, 1});
            }

            if(y < m && adj[x][y+1] != '#' && vis[x][y+1][2][1] > dist + 1) {
                vis[x][y+1][2][1] = dist + 1;
                q.push({dist + 1, x, y + 1, 2, 1});
            }

            if(y > 1 && adj[x][y-1] != '#' && vis[x][y-1][3][1] > dist + 1) {
                vis[x][y-1][3][1] = dist + 1;
                q.push({dist + 1, x, y-1, 3, 1});
            }

            
        }

        if(direc == 2) {

            if(y < m && adj[x][y+1] != '#' && count < 3 && vis[x][y+1][2][count + 1] > dist + 1) {
                vis[x][y+1][2][count + 1] = dist + 1;
                q.push({dist + 1, x, y + 1, 2, count + 1});
            }
            
            if(x > 1 && adj[x-1][y] != '#' && vis[x-1][y][1][1] > 1 + dist) {
                vis[x-1][y][1][1] = dist + 1;
                q.push({dist + 1,x - 1, y, 1, 1});
            }

            if(x < n && adj[x+1][y] != '#' && vis[x+1][y][0][1] > dist + 1) {
                vis[x+1][y][0][1] = dist + 1;
                q.push({dist + 1, x + 1, y, 0, 1});
            }

            if(y > 1 && adj[x][y-1] != '#' && vis[x][y-1][3][1] > dist + 1) {
                vis[x][y-1][3][1] = dist + 1;
                q.push({dist + 1, x, y-1, 3, 1});
            }

           
        }

        if(direc == 3) {

            if(y > 1 && adj[x][y-1] != '#' && count < 3 && vis[x][y-1][3][count + 1] > dist + 1) {
                vis[x][y-1][3][count + 1] = dist + 1;
                q.push({dist + 1, x, y - 1, 3, count + 1});
            }
            
            if(x > 1 && adj[x-1][y] != '#' && vis[x-1][y][1][1] > 1 + dist) {
                vis[x-1][y][1][1] = dist + 1;
                q.push({dist + 1,x - 1, y, 1, 1});
            }

            if(y < m && adj[x][y+1] != '#' && vis[x][y+1][2][1] > dist + 1) {
                vis[x][y+1][2][1] = dist + 1;
                q.push({dist + 1, x, y + 1, 2, 1});
            }

            if(x < n && adj[x+1][y] != '#' && vis[x+1][y][0][1] > dist + 1) {
                vis[x+1][y][0][1] = dist + 1;
                q.push({dist + 1, x + 1, y, 0, 1});
            }

        }
    }

    for(int i = 0; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) ans = min(ans, vis[end_x][end_y][i][j]);
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        int n,m;
        cin >> n >> m;

        ans = INT_MAX;

        vector<vector<char>> adj(n + 1, vector<char>(m + 1));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> adj[i][j];

                if(adj[i][j] == 'S') {
                    start_x = i;
                    start_y = j;
                }

                if(adj[i][j] == 'T') {
                    end_x = i;
                    end_y = j;
                }
            }
        }

        bfs(adj);

        if(ans == INT_MAX) cout << -1 << '\n';
        else cout << ans << '\n';


    
    return 0;
}