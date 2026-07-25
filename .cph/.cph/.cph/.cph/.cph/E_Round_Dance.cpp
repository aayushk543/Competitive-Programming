#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<int>& indeg, int index, int prev) {
    if(index == -1 || index == prev) return false;
    if(vis[index]) return true;

    vis[index] = true;

    if(adj[index][0] == prev) return dfs(adj, vis, indeg, adj[index][1], index);
    else if(adj[index][1] == prev) return dfs(adj, vis, indeg, adj[index][0], index);
    return dfs(adj, vis, indeg, adj[index][0], index) || dfs(adj, vis, indeg, adj[index][1], index);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj(n + 1, vector<int>(2, -1));
        vector<int> indeg(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            int m;

            cin >> m;

            if(adj[i][0] == -1) {
                adj[i][0] = m;

                if(adj[m][0] == -1) adj[m][0] = i;
                else if(adj[m][1] == -1) adj[m][1] = i;
            }
            else if(adj[i][1] == -1 && adj[i][0] != m) {
                adj[i][1] = m;

                if(adj[m][0] == -1) adj[m][0] = i;
                else if(adj[m][1] == -1) adj[m][1] = i;
            }
        }

        for(int i = 1; i <= n; i++) {
            if(adj[i][0] != -1 && adj[i][1] != -1) indeg[i] = 2;
            else indeg[i] = 1;
        }

        vector<bool> vis(n + 1, false);
        int count1 = 0, count2 = 0;

        for(int i = 1; i <= n; i++) {
            if(vis[i] == false) {
                bool c = dfs(adj, vis, indeg, i, -1);

                if(c) count1++;
                else count2++;
            }
        }

        int mini = count1;

        if(count2 > 0) mini++;

        int maxi = count1 + count2;

        cout << mini << " " << maxi << '\n';
    }

    return 0;
}
