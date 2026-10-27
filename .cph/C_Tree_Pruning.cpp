#include<bits/stdc++.h>
using namespace std;

long long dfs(int index, vector<vector<int>>& adj, vector<long long>& dist, int so_far, vector<int>& vis, vector<int>& vis2, vector<long long>& vis3) {
    long long curr = 0;
    vis[index] = 1;

    for(int i = 0; i < adj[index].size(); i++) {
        if(vis[adj[index][i]] == -1) {
            long long now = dfs(adj[index][i], adj, dist, so_far + 1, vis, vis2, vis3);

            curr += now;

            vis3[so_far + now] += now;
        }
    }

    vis2[so_far] = 1;
    dist[so_far] += curr;

    return curr + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj(n + 1, vector<int>());

        for(int i = 1; i <= n - 1; i++) {
            int u,v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<long long> dist(n + 1);
        vector<int> vis(n + 1, -1);
        vector<int> vis2(n + 1, -1);
        vector<long long> vis3(n + 1);

        dfs(1, adj, dist, 0, vis, vis2, vis3);

        int ans = -1;
        long long curr = LLONG_MAX;

        long long sum = 0;

        for(int i = 0; i < n; i++) {
            vis3[i + 1] += vis3[i];
        }

        for(int i = 1; i <= n; i++) {

            if(vis2[i] == 1) {

                if(dist[i] + vis3[i] - 1 < curr) {

                    cout << i << " " << dist[i] << " " << vis3[i] - 1 << '\n';
                    curr = dist[i] + vis3[i] - 1;
                    ans = i;
                }
            }
        }

        cout << curr << '\n';

    }
    return 0;
}