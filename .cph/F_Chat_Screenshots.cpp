#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;

        vector<vector<int>> adj(n + 1, vector<int>());
        vector<int> indeg(n + 1, 0);

        for(int i = 1; i <= k; i++) {

            vector<int> curr(n);

            for(int j = 0; j < n; j++) cin >> curr[j];

            for(int j = 1; j < n - 1; j++) {
                int u = curr[j];
                int v = curr[j+1];

                adj[u].push_back(v);
                indeg[v]++;
            }
        }

        queue<int> q;
        vector<int> topo;

        for(int i = 1; i <= n; i++) if(indeg[i] == 0) q.push(i);

        while(!q.empty()) {
            int index = q.front();
            q.pop();

            topo.push_back(index);

            for(int i = 0; i < adj[index].size(); i++) {
                indeg[adj[index][i]] -= 1;

                if(indeg[adj[index][i]] == 0) {
                    q.push(adj[index][i]);
                }
            }
        }

        if(topo.size() == n) cout << "YES" << '\n';
        else cout << "NO" << '\n';

    }
    return 0;
}