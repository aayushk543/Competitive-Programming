#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;

    if(1) {
        int n;
        cin >> n;

        vector<vector<pair<int,int>>> adj(n + 1);

        for(int i = 0; i < n - 1; i++) {
            int u,v;
            cin >> u >> v;

            adj[u].push_back({u, i});
            adj[v].push_back({v, i});
        }

        int curr = 0;
        vector<int> ans(n - 1, -1);

        for(int i = 1; i <= n; i++) {

            if(adj[i].size() >= 3) {
                
                ans[adj[i][0].second] = 0;
                ans[adj[i][1].second] = 1;
                ans[adj[i][2].second] = 2;
                curr = 3;
                break;
            }
        }

        for(int i = 0; i < n - 1; i++) {

            if(ans[i] == -1) cout << curr++ << '\n';
            else cout << ans[i] << '\n';
        }
        
    }
}