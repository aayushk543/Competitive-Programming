#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& adj, int index, vector<int>& vis) {
    vis[index] = 0;

    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> vis(n + 1, 1);

    for(int i = 1; i <= n - 1; i++) {
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        if(adj[i].size() == 1) index = i;
    }

    if(index != 0) cout << dfs(adj, index, -1) << '\n';
    else cout << 0 << '\n';
}