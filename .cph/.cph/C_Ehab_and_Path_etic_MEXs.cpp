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

        vector<vector<int>> adj(n + 1);
        map<pair<int,int>, int> mp;

        for(int i = 1; i <= n - 1; i++) {
            int u,v;
            cin >> u >> v;

            mp[{u, v}] = i - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 0;

        queue<int> q;

        q.push(1);

        vector<int> ans(n - 1, 0);

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int i = 0; i < adj[node].size(); i++) {

                if(mp.find({node, adj[node][i]}) != mp.end()) {
                    ans[mp[{node, adj[node][i]}]] = count++;
                }
                else {
                    ans[mp[{adj[node][i], node}]] = count++;
                }
            }
        }

        for(int i = 0; i < n - 1; i++) cout << ans[i] << '\n';
    }
}