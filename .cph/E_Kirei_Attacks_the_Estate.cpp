#include<bits/stdc++.h>
using namespace std;

void dfs2(int index, vector<vector<int>>& adj, int prev, vector<vector<long long>>& vec, vector<long long>& arr) {

    vec[index][0] = min(arr[index], arr[index] - vec[prev][1]);
    vec[index][1] = max(arr[index], arr[index] - vec[prev][0]);

    for(int i = 0; i < adj[index].size(); i++) {
        int node = adj[index][i];

        if(node == prev) continue;

        dfs2(node, adj, index, vec, arr);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<long long> arr(n + 1);
        vector<vector<int>> adj(n + 1, vector<int>());

        for(int i = 1; i <= n; i++) cin >> arr[i];

        for(int i = 1; i <= n - 1; i++) {
            int u,v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<long long>> ans(n + 1, vector<long long>(2, 0));

        ans[0][0] = 0;
        ans[0][1] = 0;

        dfs2(1, adj, 0, ans, arr);

        for(int i = 1; i <= n; i++) cout << ans[i][1] << " ";
        cout << '\n';
    }
    
    return 0;
}