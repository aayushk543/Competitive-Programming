#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int index, vector<int>& parent){

    for(int i = 0; i < adj[index].size(); i++) {
        if(parent[adj[index][i]] == -1 && adj[index][i] != 1) {
            parent[adj[index][i]] = index;
            dfs(adj, adj[index][i], parent);
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj(n + 1);
        vector<vector<int>> edges;

        for(int i = 1; i < n; i++) {
            int u,v;
            cin >> u >> v;

            edges.push_back({u, v});

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> parent(n + 1, -1);
        vector<int> edges_no(n + 1, 0);

        dfs(adj, 1, parent);

        int count = 0;

        vector<int> vis(n + 1);
        edges_no[1] = 0;

        for(int i = 1; i <= n; i++) vis[i] = i;

        for(int i = 0; i < n - 1; i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            if(parent[u] == v) {
                vis[u] = vis[v];
                edges_no[u] = i + 1;
            }
            else {
                vis[v] = vis[u];
                edges_no[v] = i + 1;
            }

        }

        // for(int i = 1; i <= n; i++) cout << edges_no[i] << " ";
        // cout << '\n';

        queue<pair<int,int>> q;
        q.push({1, 1});

        vector<int> vis2(n + 1, -1);
        vis2[1] = 1;

        while(!q.empty()) {
            auto [u, sum] = q.front();
            q.pop();

            int curr = edges_no[u];

            vis2[u] = sum;

            for(int i = 0; i < adj[u].size(); i++) {
                if(vis2[adj[u][i]] != -1) continue;

                //cout << u << " " << sum << " " << adj[u][i] << '\n';
                if(edges_no[adj[u][i]] >= curr) q.push({adj[u][i], sum});
                else q.push({adj[u][i], sum + 1});
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++) ans = max(ans, vis2[i]);


        cout << ans << '\n';
    }
    return 0;
}