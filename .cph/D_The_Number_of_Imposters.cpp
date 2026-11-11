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

        vector<vector<pair<int, string>>> adj(n + 1, vector<pair<int, string>>());

        for(int i = 1; i <= m; i++) {
            int u,v;
            string s;

            cin >> u >> v >> s;

            adj[u].push_back({v, s});
        }

        vector<int> role(n + 1, -1);
    }
    
    return 0;
}