#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int index, vector<int>& ans, vector<int>& child) {
    int count = 0;

    for(int i = 0; i < adj[index].size(); i++) {

        if(child[adj[index][i]] == 1) count++;
    }

    for(int i = 0; i < adj[index].size(); i++) {

        dfs(adj, adj[index][i], ans, child);
    }

    if(count == adj[index].size() && child[index] == 1) ans.push_back(index);

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if(1) {
        int n; 
        cin >> n;

        vector<vector<int>> adj(n + 1, vector<int>());
        vector<int> child(n + 1, 0);

        int root = -1;

        for(int i = 1; i <= n; i++) {
            int p,c;
            cin >> p >> c;

            if(p != -1) adj[p].push_back(i);
            child[i] = c;

            if(p == -1) root = i;
        }

        vector<int> ans;

        dfs(adj, root, ans, child);

        sort(ans.begin(), ans.end());

        if(ans.size() == 0) {
            cout << -1 << '\n';
        } 
        else {
            for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

            cout << '\n';
        }
    }
}