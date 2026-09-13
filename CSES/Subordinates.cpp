#include <bits/stdc++.h>
using namespace std;

int dfs(int index, vector<vector<int>>& adj, vector<int>& vec) {

    int count = 0;

    for(int i = 0; i < adj[index].size(); i++) {
        count += dfs(adj[index][i], adj, vec);
    }

    vec[index] = count;

    return count + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> vec(n + 1, 0);
    // vector<int> parent(n + 1);

    vector<vector<int>> adj(n + 1);

    for(int i = 2; i <= n; i++) {
        int curr;
        cin >> curr;

        adj[curr].push_back(i);
    }

    dfs(1, adj, vec);

    for(int i = 1; i <= n; i++) cout << vec[i] << " ";

    cout << '\n';

}    