#include<bits/stdc++.h>
using namespace std;

int dfs(int index, vector<vector<int>>& adj, vector<int>& dist, int depth, vector<int>& dp) {
    dist[index] = depth;
    int curr = depth;

    for(int i = 0; i < adj[index].size(); i++) {
        if(dist[adj[index][i]] == -1) {
            curr = max(curr, dfs(adj[index][i], adj, dist, depth + 1, dp));
        }
    }

    dp[index] = curr;
    return curr;
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

        vector<int> dist(n + 1, -1);
        vector<int> dp(n + 1);

        int max_depth = dfs(1, adj, dist, 1, dp);

        vector<int> diff(max_depth + 2, 0);

        for(int i = 1; i <= n; i++) {
            diff[dist[i]]++;
            diff[dp[i] + 1]--;
        }

        int curr = 0, maxi = 0;

        for(int i = 1; i <= max_depth; i++) cout << diff[i] << " ";

        for(int i = 1; i <= max_depth; i++) {
            curr += diff[i];
            maxi = max(maxi, curr);
        }

        cout << n - maxi << '\n';
    }
    return 0;
}