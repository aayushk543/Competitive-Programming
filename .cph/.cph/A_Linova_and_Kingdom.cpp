#include<bits/stdc++.h>
using namespace std;

int zero_deg = 0;

int dfs(vector<vector<int>>& adj, int index, vector<int>& deg, vector<bool>& vis) {
    int count = 0;
    vis[index] = false;

    for(int i = 0; i < adj[index].size(); i++) {

        if(vis[adj[index][i]] == true) {
            count += dfs(adj, adj[index][i], deg, vis);
        }
    }

    deg[index] = count;

    if(count == 0) {
        //cout << index << '\n';
        zero_deg++;
        return 1;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if(1) {
       int n,k;
       cin >> n >> k;

       vector<vector<int>> adj(n);
       vector<int> deg(n, 0);
       vector<bool> vis(n, true);

       for(int i = 1; i <= n - 1; i++) {
        int u,v;
        cin >> u >> v;

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
       }

       dfs(adj, 0, deg, vis);

       sort(deg.begin(), deg.end());

       int ans = 0;

       for(int i = max(zero_deg, k); i < n; i++) {
        //cout << deg[i] << " ";
        ans += deg[i];
       }

       cout << ans << '\n';

    }
    return 0;
}