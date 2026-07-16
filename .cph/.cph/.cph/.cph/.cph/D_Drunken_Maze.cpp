#include<bits/stdc++.h>
using namespace std;

int start_x, start_y;
int end_x, end_y;
int n,m;
vector<vector<vector<long long>>> dp;

void dfs(vector<vector<int>>& adj) {
    priority_queue<tuple<int,int,int,int,int>, vector<tuple<int,int,int,int,int>>, greater<tuple<int,int,int,int,int>>> pq;

    pq.push({0, start_x, start_y, 1, -1});
    pq.push({0, start_x, start_y, 2, -1});
    pq.push({0, start_x, start_y, 3, -1});
    pq.push({0, start_x, start_y, 4, -1});
    dp[start_x][start_y][1] = -1;
    dp[start_x][start_y][2] = -1;
    dp[start_x][start_y][3] = -1;
    dp[start_x][start_y][4] = -1;

    while(!pq.empty()) {
        auto [dist, x, y, direc, curr] = pq.top();
        pq.pop();

        if(direc == 1) {
            
            if(x > 0 && curr == 3 && dp[x-1][y][direc] > dist + 3 && adj[x-1][y] != -1) {
                dp[x-1][y][direc] = dist + 3;
                pq.push({dp[x-1][y][direc], x-1, y, 1, 3});
            } 
            else if(x > 0 && dp[x-1][y][direc] > dist + 1 && adj[x-1][y] != -1) {
                dp[x-1][y][direc] = dist + 1;
                pq.push({dp[x-1][y][direc], x - 1, y, 1, curr + 1});
            }


            if(x < n - 1 && dp[x+1][y][2] > dist + 1 && adj[x+1][y] != -1) {
                dp[x+1][y][2] = dist + 1;
                pq.push({dist + 1, x + 1, y, 2, 0});
            }

            if(y > 0 && dp[x][y-1][3] > dist + 1 && adj[x][y-1] != -1) {
                dp[x][y-1][3] = dist + 1;
                pq.push({dist + 1, x, y - 1, 3, 0});
            }

            if(y < m - 1 && dp[x][y+1][4] > dist + 1 && adj[x][y + 1] != -1) {
                dp[x][y+1][4] = dist + 1;
                pq.push({dist + 1, x, y + 1, 4, 0});
            }
        } 
        else if(direc == 2) {
            
            if(x < n - 1 && curr == 3 && dp[x+1][y][2] > dist + 3 && adj[x+1][y] != -1) {
                dp[x-1][y][direc] = dist + 3;
                pq.push({dp[x+1][y][direc], x+1, y, 2, 3});
            } 
            else if(x < n - 1 && dp[x+1][y][direc] > dist + 1 && adj[x+1][y] != -1) {
                dp[x+1][y][direc] = dist + 1;
                pq.push({dp[x+1][y][direc], x - 1, y, 2, curr + 1});
            }


            if(x > 0 && dp[x-1][y][1] > dist + 1 && adj[x-1][y] != -1) {
                dp[x-1][y][1] = dist + 1;
                pq.push({dist + 1, x - 1, y, 1, 0});
            }

            if(y > 0 && dp[x][y-1][3] > dist + 1 && adj[x][y-1] != -1) {
                dp[x][y-1][3] = dist + 1;
                pq.push({dist + 1, x, y - 1, 3, 0});
            }

            if(y < m - 1 && dp[x][y+1][4] > dist + 1 && adj[x][y + 1] != -1) {
                dp[x][y+1][4] = dist + 1;
                pq.push({dist + 1, x, y + 1, 4, 0});
            }
        } 
        else if(direc == 3) {
            
            if(y > 0 && curr == 3 && dp[x][y-1][direc] > dist + 3 && adj[x][y-1] != -1) {
                dp[x][y-1][direc] = dist + 3;
                pq.push({dp[x][y-1][direc], x, y-1, 3, 3});
            } 
            else if(y > 0 && dp[x][y-1][direc] > dist + 1 && adj[x][y-1] != -1) {
                dp[x][y-1][direc] = dist + 1;
                pq.push({dp[x][y-1][direc], x, y - 1, 3, curr + 1});
            }


            if(x < n - 1 && dp[x+1][y][2] > dist + 1 && adj[x+1][y] != -1) {
                dp[x+1][y][2] = dist + 1;
                pq.push({dist + 1, x + 1, y, 2, 0});
            }

            if(x > 0 && dp[x-1][y][1] > dist + 1 && adj[x-1][y] != -1) {
                dp[x-1][y][1] = dist + 1;
                pq.push({dist + 1, x-1, y, 1, 0});
            }

            if(y < m - 1 && dp[x][y+1][4] > dist + 1 && adj[x][y + 1] != -1) {
                dp[x][y+1][4] = dist + 1;
                pq.push({dist + 1, x, y + 1, 4, 0});
            }
        } 
        else if(direc == 4) {
            
            if(y < m - 1 && curr == 3 && dp[x][y + 1][4] > dist + 3 && adj[x][y + 1] != -1) {
                dp[x][y + 1][direc] = dist + 3;
                pq.push({dp[x][y + 1][direc], x, y + 1, 4, 3});
            } 
            else if(y < m - 1 && dp[x][y + 1][direc] > dist + 1 && adj[x][y + 1] != -1) {
                dp[x][y + 1][direc] = dist + 1;
                pq.push({dp[x][y + 1][direc], x, y + 1, 4, curr + 1});
            }


            if(x < n - 1 && dp[x+1][y][2] > dist + 1 && adj[x+1][y] != -1) {
                dp[x+1][y][2] = dist + 1;
                pq.push({dist + 1, x + 1, y, 2, 0});
            }

            if(y > 0 && dp[x][y-1][3] > dist + 1 && adj[x][y-1] != -1) {
                dp[x][y-1][3] = dist + 1;
                pq.push({dist + 1, x, y - 1, 3, 0});
            }

            if(x > 0 && dp[x-1][y][1] > dist + 1 && adj[x-1][y] != -1) {
                dp[x-1][y][1] = dist + 1;
                pq.push({dist + 1, x - 1, y, 1, 0});
            }
        }  
    }
}

int main() {
    
        cin >> n >> m;
        dp.assign(n, vector<vector<long long>>(m, vector<long long>(5, INT_MAX)));

        vector<vector<int>> adj(n, vector<int>(m, -1));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char c;
                cin >> c;

                if(c == 'S') {
                    start_x = i;
                    start_y = j;
                }
                if(c == 'T') {
                    end_x = i;
                    end_y = j;
                }

                if(c == '.' || c == 'S' || c == 'T') adj[i][j] = 1;
            }
        }

        // int ans = min(dfs(adj, start_x, start_y, -2, 0), min(dfs(adj, start_x, start_y, 2, 0), min(dfs(adj, start_x, start_y, 1, 0),dfs(adj, start_x, start_y, -1, 0))));

        dfs(adj);

        long long ans = min(dp[end_x][end_y][1] , min(dp[end_x][end_y][2], min(dp[end_x][end_y][3], dp[end_x][end_y][4]))); 

        if(ans == INT_MAX) cout << -1 << '\n';
        else cout << ans << '\n';
    
}