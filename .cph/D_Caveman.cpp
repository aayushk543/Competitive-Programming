#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n,m;

       cin >> n >> m;

       vector<vector<int>> adj(n + 1);

       for(int i = 1; i <= n; i++) {
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
       }

       bool flag0 = false;

       for(int i = 1; i <= n; i++) {
        if(adj[i].size() == 0) flag0 = true;
       }

       if(flag0) cout << "Brain Melt" << '\n';
       else {
        
       }
    }
    return 0;
}