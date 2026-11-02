#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<vector<vector<int>>> adj(n + 1, vector<vector<int>>());

    for(int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pair<long long,int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.push({0, 1});

    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = 0;

    vector<int> prev(n + 1, -1);

    while(!q.empty()) {
        auto [w, index] = q.top();
        q.pop();

        for(int i = 0; i < adj[index].size(); i++) {
            if(dist[adj[index][i][0]] > w + adj[index][i][1]) {

                prev[adj[index][i][0]] = index; 
                dist[adj[index][i][0]] = w + adj[index][i][1];
                q.push({w + adj[index][i][1], adj[index][i][0]});
            }
        }
    }

    if(dist[n] == LLONG_MAX) cout << -1 << '\n';
    else {
        int curr = n;
        vector<int> ans;

        while(curr != 1) {
            ans.push_back(curr);
            curr = prev[curr];
        }

        cout << 1 << " ";
        for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
        cout << '\n';
    }


    return 0;
}