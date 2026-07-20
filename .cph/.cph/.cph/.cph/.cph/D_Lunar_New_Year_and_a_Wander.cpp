#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < m; i++) {
        int m1, m2;
        cin >> m1 >> m2;

        adj[m1].push_back(m2);
        adj[m2].push_back(m1);

    }

    // for(int i = 1; i <= n; i++) {
    //     sort(adj[i].begin(), adj[i].end());
    // }

    vector<int> ans;

    vector<int> vis(n + 1, 0);
    
    vis[1] = 1;

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);

    while(!pq.empty()) {
        int node = pq.top();
        pq.pop();

        ans.push_back(node);

        for(int i = 0; i < adj[node].size(); i++) {
            if(vis[adj[node][i]] == 0) {
                pq.push(adj[node][i]);
                vis[adj[node][i]] = 1;
            }
        }
    }

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << '\n';

    return 0;
}