#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n + 1);

    for(int i = 1; i <= n - 1; i++) {
        int m1,m2;
        cin >> m1 >> m2;

        adj[m1].push_back(m2);
        adj[m2].push_back(m1);
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 1});
    vector<int> vis(n + 1, INT_MAX);
    vis[1] = 0;

    while(!pq.empty()) {
        auto [dist, node] = pq.top();
        pq.pop();

        if(vis[node] != dist) continue;

        for(int i = 0; i < adj[node].size(); i++) {

            if(vis[adj[node][i]] > dist + 1) {

                vis[adj[node][i]] = dist + 1;
                pq.push({dist + 1, adj[node][i]});
            }
        }
    }

    sort(vis.begin(), vis.end(), greater<int>());

    int ans = 0;

    for(int i = 1; i <= k; i++) {
        ans += vis[i];
    }

    cout << ans << '\n';

    return 0;
}