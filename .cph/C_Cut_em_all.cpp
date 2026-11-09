#include<bits/stdc++.h>
using namespace std;

int size(vector<vector<int>>& adj, int index, vector<int>& sz) {
    int curr = 1;
    sz[index] = -2;

    //cout << index << '\n';

    for(int i = 0; i < adj[index].size(); i++) {
        int node = adj[index][i];

        if(sz[node] == -1) curr += size(adj, node, sz);
    }

    //cout << index << " " << curr << '\n';
    sz[index] = curr;
    return curr;
}

int check(vector<vector<int>>& adj, int index, vector<int>& sz, int parent) {
    int score = 0;

    for(int i = 0; i < adj[index].size(); i++) {
        int node = adj[index][i];

        if(node == parent) continue;

        if(sz[node] == 0) score += 1 + check(adj, node, sz, index);
        else score += check(adj, node, sz, index);
    }

    return score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if(1) {
       int n;
       cin >> n;

       vector<vector<int>> adj(n+1, vector<int>());

       for(int i = 1; i <= n - 1; i++) {
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
       }

       if(n % 2 == 1) {
        cout << -1 << '\n';
        return 0;
       }

       vector<int> sz(n + 1, -1);
       size(adj, 1, sz);

       for(int i = 1; i <= n; i++) {
        sz[i] = sz[i] % 2;
        //cout << sz[i] << " ";
       }


    //    if(sz[1] == 1) {
    //     cout << -1 << '\n';
    //     return 0;
    //    }

       cout << check(adj, 1, sz, -1) << '\n';
    }
    return 0;
}