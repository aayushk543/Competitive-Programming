#include <bits/stdc++.h>
using namespace std;


int f(vector<vector<int>>& adj, int index, vector<int>& depth, int parent) {

    int d1 = 0, d2 = 0;
    for(int i = 0; i < adj[index].size(); i++) {
        if(adj[index][i] == parent) continue;

        if(d1 == 0) d1 = f(adj, adj[index][i], depth, index);
        else if(d2 == 0) d2 = f(adj, adj[index][i], depth, index);
        else {
            if(d1 > d2) d2 = max(d2, f(adj, adj[index][i], depth, index));
            else d1 = max(d1, f(adj, adj[index][i], depth, index));
        }
    }

    depth[index] = d1 + d2;
    return max(d1, d2) + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> depth(n + 1, 0);

    for(int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int p = f(adj, 1, depth, 1);
    int ans = 0;

    for(int i = 1; i <= n; i++) ans = max(ans, depth[i]);

    cout << ans << '\n';

}    