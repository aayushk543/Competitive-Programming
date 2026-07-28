#include<bits/stdc++.h>
using namespace std;

vector<long long> dij(vector<vector<vector<long long>>>& adj, int index) {
    int n = adj.size();
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> vis(n, LLONG_MAX);

    vis[index] = 0;
    pq.push({0, index});

    while(!pq.empty()) {
        auto [dist, node] = pq.top();
        pq.pop();

        if(vis[node] != dist) continue;

        for(int i = 0; i < adj[node].size(); i++) {

            if(vis[adj[node][i][0]] > dist + adj[node][i][1]) {

                vis[adj[node][i][0]] = dist + adj[node][i][1];
                pq.push({dist + adj[node][i][1], adj[node][i][0]});
            }
        }
    }

    return vis;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        int n,m;

        cin >> n >> m;

        vector<vector<vector<long long>>> adj(n + 1);

        for(int i = 1; i <= m; i++) {
            long long u,v,w;

            cin >> u >> v >> w;

            adj[u].push_back({v, w});
        }

        vector<long long> vis1 = dij(adj, 1);
        vector<long long> vis2 = dij(adj, n);

        long long ans = LLONG_MAX;

        for(int i = 1; i <= n; i++) {
            if(vis1[i] == LLONG_MAX || vis2[i] == LLONG_MAX) continue;
            ans = min(ans, vis1[i] + vis2[i]);
        }

        cout << ans << '\n';

    return 0;
}   