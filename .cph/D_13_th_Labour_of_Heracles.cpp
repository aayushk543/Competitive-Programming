#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<long long> arr(n+1);

        long long sum = 0;

        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        vector<vector<int>> adj(n + 1, vector<int>());
        vector<int> indeg(n + 1, -1);

        for(int i = 1; i <= n - 1; i++) {
            int u,v;
            cin >> u >> v;

            indeg[u]++;
            indeg[v]++;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        priority_queue<pair<long long, int>> pq;

        for(int i = 1; i <= n; i++) if(indeg[i] > 0) pq.push({arr[i], indeg[i]});

        cout << sum << " ";

        for(int i = 1; i < n - 1; i++) {

            auto [w, in] = pq.top();
            pq.pop();

            sum += w;
            cout << sum << " ";

            if(in > 1) pq.push({w, in - 1});
        }

        cout << '\n';
    }
    return 0;
}