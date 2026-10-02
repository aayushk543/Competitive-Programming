#include<bits/stdc++.h>
using namespace std;

int zero_deg = 0;

int dfs(vector<vector<int>>& adj, int index, vector<int>& deg, vector<int>& vis, int h) {
    int count = 0;
    vis[index] = h;

    for(int i = 0; i < adj[index].size(); i++) {

        if(vis[adj[index][i]] == -1) {
            count += dfs(adj, adj[index][i], deg, vis, h+1);
        }
    }

    vis[index] -= count;

    return count + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if(1) {
       int n,k;
       cin >> n >> k;

       vector<vector<int>> adj(n);
       vector<int> deg(n, 0);
       vector<int> vis(n, -1);

       for(int i = 1; i <= n - 1; i++) {
        int u,v;
        cin >> u >> v;

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
       }

       dfs(adj, 0, deg, vis, 0);
       
       sort(vis.begin(), vis.end(), greater<int>());

       long long ans = 0;

       for(int i = 0; i < k; i++) {
        ans += vis[i];
       }

       cout << ans << '\n';

    }
    return 0;
}