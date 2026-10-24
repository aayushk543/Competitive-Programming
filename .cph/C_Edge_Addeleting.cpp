#include<bits/stdc++.h>
using namespace std;

vector<int> f1(vector<vector<int>>& adj) {
    int n = adj.size() - 1;

    queue<pair<int, int>> q2;
    vector<int> dist(n + 1, -1);

            dist[n] = 0;
            q2.push({0, n});

            while(!q2.empty()) {
                auto [distance, index] = q2.front();
                q2.pop();

                //cout << index << " " << distance << '\n';

                for(int i = 0; i < adj[index].size(); i++) {

                    if(dist[adj[index][i]] == -1) {
                        dist[adj[index][i]] = distance + 1;
                        q2.push({distance + 1, adj[index][i]});
                    }
                }
            }

        return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n,m;
        cin >> n >> m;

        vector<vector<int>> adj(n + 1, vector<int>());
        vector<int> edges(m);

        for(int i = 1; i <= n - 1; i++) {
            int u,v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = -1;

        for(int i = 0; i < m; i++) cin >> edges[i];

        queue<tuple<int, int, int>> q;

        

        vector<int> vis(n + 1, -1);
        vis[1] = 1;

        //vector<vector<int>> height(n + 1, vector<int>());
        //height[1].push_back(1);

        vector<int> parent(n + 1, -1);

        for(int i = 0; i < adj[1].size(); i++) {

            q.push({adj[1][i], 1, adj[1][i]});
            parent[adj[1][i]] = adj[1][i];
        }
        

        while(!q.empty()) {
            auto [index, h, pt] = q.front();
            q.pop();

            for(int i = 0; i < adj[index].size(); i++) {
                if(vis[adj[index][i]] == -1) {

                    vis[adj[index][i]] = h + 1;
                    //height[h + 1].push_back(adj[index][i]);
                    parent[adj[index][i]] = pt;

                    q.push({adj[index][i], h + 1, pt});
                }
            }
        }

        int edgy = -1;
        int curr = 0;
        int par = 0;

        //cout << ans << '\n';

        int interest = parent[n];

        int prev = -1;

        for(int i = 0; i < adj[1].size(); i++) {

            if(adj[1][i] == interest) {
                prev = i; 
                break;
            }
        }

        vector<int> dist2 = f1(adj);

        for(int i = 0; i < m; i++) {

            if(parent[edges[i]] == interest && prev != -1) {
                
                adj[1][prev] = edges[i];

                ans = max(ans, dist2[edges[i]] + 1);

                //adj[1][prev] = interest;
            }
        }

        ans = max(ans, dist2[1]);

        // priority_queue<pair<int, int>> q2;
        // vector<int> dist(n + 1, -1);

        // dist[1] = 0;
        // q2.push({0, 1});

        // while(!q2.empty()) {
        //     auto [distance, index] = q2.top();
        //     q2.pop();

        //     //cout << index << " " << distance << '\n';

        //     for(int i = 0; i < adj[index].size(); i++) {

        //         if(dist[adj[index][i]] == -1) {
        //             dist[adj[index][i]] = distance + 1;
        //             q2.push({distance + 1, adj[index][i]});
        //         }
        //     }
        // }

        // int ans = -1;

        // for(int i = 1; i <= n ; i++) {
        //     ans = max(ans, dist[i]);
        //     //cout << dist[i] << " ";
        // }

        cout << ans << '\n';

    }
    return 0;
}