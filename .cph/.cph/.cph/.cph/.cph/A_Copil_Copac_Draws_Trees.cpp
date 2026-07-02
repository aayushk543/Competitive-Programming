#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& vis, int index, vector<int>& count, int num) {
    vis[index] = true;
    count[index] = num;

    for(int i = 0; i < adj[index].size(); i++) {
        if(vis[adj[index][i]] == false) dfs(adj, vis, adj[index][i], count, num);
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

        vector<vector<int>> adj(n + 1, vector<int>());
        vector<bool> vis(n + 1, false);
        vector<int> count(n + 1, 0);

        vis[1] = true;
        count[1] = 1;
        

        for(int i = 1; i < n; i++) {
            int a,b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);

            if(vis[a]) {
                
                vis[b] = true;
                count[b] = count[a];

                //cout << a << " " << count[a] << '\n';

                for(int i = 0; i < adj[b].size(); i++) {
                    if(vis[adj[b][i]] == false) dfs(adj, vis, adj[b][i], count, count[a] + 1);
                }
                
            }
            else if(vis[b]) {

                vis[a] = true;
                count[a] = count[b];

                for(int i = 0; i < adj[a].size(); i++) {
                    if(vis[adj[a][i]] == false) dfs(adj, vis, adj[a][i], count, count[b] + 1);
                }

            }

            
        }

        for(int i = 1; i <= n; i++)
        cout << count[i] << '\n';

        int ans = 1;

        for(int i = 1; i <= n; i++) ans = max(ans, count[i]);

        //cout << ans << '\n';
    }
    return 0;
}