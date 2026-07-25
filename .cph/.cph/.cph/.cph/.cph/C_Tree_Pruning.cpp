#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj(n + 1);
        vector<int> indeg(n + 1, 0);
        queue<int> q;

        for(int i = 1; i <= n - 1; i++) {
            int m1, m2;
            cin >> m1 >> m2;

            adj[m1].push_back(m2);
            adj[m2].push_back(m1);

            indeg[m1]++;
            indeg[m2]++;
        }

        for(int i = 1; i <= n; i++) {
            if(indeg[i] == 1) q.push(i);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,1});

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

        vector<int> root;
        int pre = 0, suf = 0;

        

        while(!q.empty()) {
            root.push_back(vis[q.front()]);
            suf += vis[q.front()];
            //cout << suf << '\n';
            q.pop();
        }

        //for(int i = 0; i < root.size(); i++) cout << root[i] << " ";

        sort(root.begin(), root.end());

        int ans = 1000;

        for(int i = 0; i < root.size(); i++) {
            int suf2 = suf - (root.size() - i) * root[i] - pre;
            //cout << suf << '\n';
            ans = min(ans, pre + suf2);
            pre += root[i];
        }

        cout << ans << '\n';
    }

    return 0;
}
