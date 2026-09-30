#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n;
       cin >> n;

       vector<vector<int>> adj(n + 1);
       vector<int> vis(n + 1, -1);
       vector<int> deg(n + 1, 0);

       bool flag = true;

       for(int i = 0; i < n; i++) {
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

        deg[u]++; 
        deg[v]++;

        if(deg[u] > 2 || deg[v] > 2) flag = false;

       }

       for(int i = 1; i <= n; i++) {

        if(vis[i] == -1) {
            queue<int> q;
            q.push(i);
            vis[i] = 1;

            while(!q.empty()) {
                int x = q.front();
                q.pop();

                for(int i = 0; i < adj[x].size(); i++) {

                    if(vis[adj[x][i]] == -1) {

                        if(vis[x] == 1) vis[adj[x][i]] = 2;
                        else vis[adj[x][i]] = 1; 

                        q.push(adj[x][i]);
                    }
                    else if(vis[x] == vis[adj[x][i]]) {
                        flag = false;
                        break;
                    }

                }
            }
        }
       }

       if(flag) cout << "YES" << '\n';
       else cout << "NO" << '\n';

    }
    return 0;
}