#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,a,b;
        cin >> n >> a >> b;

        vector<vector<vector<int>>> adj(n + 1);

        for(int i = 1; i <= n - 1; i++) {
            int u,v,w;
            cin >> u >> v >> w;

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> vis(n + 1, 0);
        queue<pair<int, int>> q;
        q.push({a, 0});

        while(!q.empty()) 
    }
}