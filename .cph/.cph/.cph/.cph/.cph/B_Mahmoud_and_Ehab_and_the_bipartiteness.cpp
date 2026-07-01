#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1, vector<int>());

    for(int i = 1; i <= n - 1; i++) {
        int p,q;
        cin >> p >> q;

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    vector<int> vis(n + 1, -1);

    for(int i = 1; i <= n; i++){
        if(vis[i] == -1) {
            vis[i] = 1;
            queue<int> q;
            q.push(i);

            while(!q.empty()){
                int curr = q.front();
                q.pop();

                for(int j = 0; j < adj[curr].size(); j++){
                    if(vis[adj[curr][j]] == -1) {
                        if(vis[curr] == 1) vis[adj[curr][j]] = 2;
                        if(vis[curr] == 2) vis[adj[curr][j]] = 1;
                        q.push(adj[curr][j]);
                    }
                }
            }
        }
    }

    int count = 0;

    for(int i = 1; i <= n; i++) {
        if(vis[i] == 1) count++;
    }

    cout << (long long)count * (n - count) - n + 1 << '\n';

    return 0;
}