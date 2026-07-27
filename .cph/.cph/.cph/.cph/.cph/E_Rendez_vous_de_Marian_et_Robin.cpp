#include<bits/stdc++.h>
using namespace std;

vector<vector<long long>> dij(vector<vector<vector<int>>>& adj, set<int>& horse, int index) {
    int n = adj.size();
    priority_queue<tuple<long long,int, int>, vector<tuple<long long,int,int>>, greater<tuple<long long,int,int>>> pq;
    vector<vector<long long>> vis(n, vector<long long>(2, LLONG_MAX));

    int now = 0;

    if(horse.find(index) != horse.end()) now = 1;

    pq.push({0, index, now});
    vis[index][now] = 0;

   while(!pq.empty()) {
        auto [dist, node, in] = pq.top();
        pq.pop();

        if(vis[node][in] != dist) continue;

        if(in == 0 && horse.find(node) != horse.end()) in = 1; 

        for(int i = 0; i < adj[node].size(); i++) {
            if(in) {
                if(vis[adj[node][i][0]][in] > dist + (adj[node][i][1] >> 1)) {

                    vis[adj[node][i][0]][in] = dist + (adj[node][i][1] >> 1);
                    pq.push({dist + (adj[node][i][1] >> 1), adj[node][i][0], in});
                }
            }
            else {
                if(vis[adj[node][i][0]][in] > dist + (adj[node][i][1])) {

                    vis[adj[node][i][0]][in] = dist + (adj[node][i][1]);
                    pq.push({dist + (adj[node][i][1]), adj[node][i][0], in});
                }
            }
        }
    }

    return vis;   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n,m,h;

       cin >> n >> m >> h;

       set<int> horse;
       vector<int> hor(h);

       for(int i = 0; i < h; i++) {
        cin >> hor[i];

        horse.insert(hor[i]);
       }

       vector<vector<vector<int>>> adj(n + 1);

       for(int i = 0; i < m; i++) {
        int m1, m2, m3;
        cin >> m1 >> m2 >> m3;

        adj[m1].push_back({m2, m3});
        adj[m2].push_back({m1, m3});
       }

       vector<vector<long long>> vis1 = dij(adj, horse, 1);
       vector<vector<long long>> vis2 = dij(adj, horse, n);

       long long ans = LLONG_MAX;

       for(int i = 1; i <= n; i++) {
        if((vis1[i][0] == LLONG_MAX) && vis1[i][1] == LLONG_MAX) continue;

        ans = min(ans, max(min(vis1[i][0],vis1[i][1]),min(vis2[i][0],vis2[i][1])));
       }

       if(ans == LLONG_MAX) cout << -1 << '\n';
       else cout << ans << '\n';

       
    }
    return 0;
}