#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n, m;
       cin >> n >> m;

       vector<vector<vector<int>>> adj(n + 1);

       for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
       }

       vector<long long> slow(n + 1);

       for(int i = 1; i <= n; i++) cin >> slow[i];

       priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<tuple<long long,int,int>>> pq;
       pq.push({0, 1, slow[1]});

       vector<vector<long long>> vis(n + 1, vector<long long>(1001, LLONG_MAX));
       vis[1][slow[1]] = 0;

       while(!pq.empty()) {
        auto [time, node, slowness] = pq.top();
        pq.pop();

        if(vis[node][slowness] != time) continue;


        for(int i = 0; i < adj[node].size(); i++) {

            if(vis[adj[node][i][0]][slowness] > time + adj[node][i][1]*slowness) {

               vis[adj[node][i][0]][slowness] = time + adj[node][i][1]*slowness; 
               pq.push({time + adj[node][i][1]*slowness, adj[node][i][0], slowness});
            }

            if(slow[node] < slowness) {
                if(vis[adj[node][i][0]][slow[node]] > time + adj[node][i][1]*slow[node]) {

                    vis[adj[node][i][0]][slow[node]] = time + adj[node][i][1]*slow[node]; 
                    pq.push({time + adj[node][i][1]*slow[node], adj[node][i][0], slow[node]});
                }
            }
        }
       }

       long long ans = vis[n][0];

       for(int i = 1; i <= 1000; i++) ans = min(ans, vis[n][i]);

       cout << ans << '\n';
    }
    return 0;
}   