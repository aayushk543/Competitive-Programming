#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& adj, vector<int>& dist, vector<int>& h, vector<int>& vis, int index, int curr) {
    vis[index] = 1;

    for(int i = 0; i < adj[index].size(); i++) {
        if(vis[adj[index][i]] == -1) {
            dist[index] += dfs(adj, dist, h, vis, adj[index][i], curr);
        }
    }

    h[curr] += dist[index];

    return 1 + dist[index];
}

void dfs2(vector<vector<int>>& adj, vector<int>& dist, int index, int curr) {
    dist[index] = -1;
    int count = 0;

    for(int i = 0; i < adj[index].size(); i++) {
        if(dist[adj[index][i]] == 0) {
            dfs(adj, dist, adj[index][i], curr + 1);
            count++;
        }
    }

    if(count == 0) dist[index] = curr;

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
        vector<int> h(n + 1);
        vector<int> vis(n + 1, -1);

        for(int i = 1; i <= n - 1; i++) {
            int u,v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(n + 1, 0);
        vector<int> dist2(n + 1, 0);

        dfs(adj, dist, h, vis, 1, 0);
        dfs2(adj, dist2, 1, 0);

        int sum = 0;

        map<int, int> mp;


    }
}