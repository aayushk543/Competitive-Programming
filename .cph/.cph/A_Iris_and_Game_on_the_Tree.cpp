#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int index, vector<vector<int>>& indeg, vector<int>& vis, char prev, int count1, int count2, int count3) {
    vis[index] = 1;
    int count = 0;

    char curr = s[index];

    for(int i = 0; i < adj[index].size(); i++) {

        if(vis[adj[index][i]] == -1) {
            count++;
            if(prev == '?') dfs(adj, adj[index][i], indeg, vis, curr, count1, count2, count3 + 1);
            else if(prev == '0') {
                if(curr == '1') dfs(adj, adj[index][i], indeg, vis, curr, count1 + 1, count2);
                else dfs(adj, adj[index][i], indeg, vis, curr, count1, count2);
            }
            else if(prev == '1') {
                if(curr == '0') dfs(adj, adj[index][i], indeg, vis, curr, count1, count2 + 1);
                else dfs(adj, adj[index][i], indeg, vis, curr, count1, count2);
            }
        }
    }

    
    if(count == 0) indeg[index] = {(count1, count2, count3)};

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj(n + 1);

        for(int i = 1; i <= n - 1; i++) {
            int u,v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string s;
        cin >> s;

        vector<vector<int>> indeg(n + 1);
        vector<int> vis(n + 1, -1);

        dfs(adj, 1, indeg, vis);
    }
}