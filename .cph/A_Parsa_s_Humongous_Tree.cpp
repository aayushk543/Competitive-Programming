#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int index, vector<int>& parent, vector<vector<int>>& dp, vector<vector<int>>& range) {

    for(int i = 0; i < adj[index].size(); i++) {
        int node = adj[index][i];

        if(parent[node] == -1) {
            parent[node] = index;
            dfs(adj, node, parent, dp, range);
        }
    }

    int dp1 = 0, dp2 = 0;

    for(int i = 1; i < parent.size(); i++) {

        if(parent[i] == index) {
            dp1 += max(dp[i][0] + abs(range[i][0] - range[index][0]), dp[i][1] + abs(range[i][0] - range[index][1]));
            dp2 += max(dp[i][0] + abs(range[i][1] - range[index][0]), dp[i][1] + abs(range[index][1] - range[i][1]));
        }
    }

    dp[index][0] = dp1;
    dp[index][1] = dp2;

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

        vector<vector<int>> range(n + 1, vector<int>(2));
        vector<vector<int>> adj(n + 1, vector<int>());
        vector<vector<int>> edges;
        vector<int> parent(n + 1, -1);
        vector<vector<int>> dp(n + 1, vector<int>(2));


        for(int i = 1; i <= n; i++) cin >> range[i][0] >> range[i][1];

        for(int i = 1; i <= n - 1; i++) {
            int u,v;
            cin >> u >> v;

            edges.push_back({u, v});

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // vector<int> val(n + 1, 0);

        // for(int i = 1; i <= n; i++) {
        //     int node = i;

        //     int p = 0, q = 0;

        //     for(int j = 0; j < adj[node].size(); j++) {
        //         int next = adj[node][j];

        //         if(range[node][0] <= range[next][0]) p++;
        //         else if(range[node][1] >= range[next][1]) q++;
        //     }

        //     if(p > q) val[node] = range[node][0];
        //     else if(p == q) val[node] = range[node][0];
        //     else if(p < q) val[node] = range[node][1];
        // }

        // long long ans = 0;

        // for(int i = 0; i < edges.size(); i++) {
        //     ans = abs(val[edges[i][0]] - val[edges[i][1]]);
        // }

        long long ans = 0;

        dfs(adj, 1, parent, dp, range);

        cout << max(dp[1][0], dp[1][1]) << '\n';
    }

    return 0;
}