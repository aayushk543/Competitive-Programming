#include<bits/stdc++.h>
using namespace std;

int dfs(int index, vector<vector<int>>& adj, vector<int>& pos, int p, vector<int>& ans, vector<bool>& vis) {
    if(vis[index]) return 0;
    
    vis[index] = true;
    int count2 = 0;

    if(pos[index] == 1) count2++;

    for(int i = 0; i < adj[index].size(); i++) {
        if(!vis[adj[index][i]]) count2 += dfs(adj[index][i], adj, pos, index, ans, vis);
    }

    if(count2 > 1) {
        ans.push_back(p);
    }

    return count2;
}

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> ans;

        //cout << "c2";

        vector<vector<int>> adj(n + 1);
        for(int i = 2; i <= n; i++) {
            int u;

            cin >> u;

            if(u != i) adj[u].push_back(i);
            //adj[i].push_back(u);
        }

        int m;

        cin >> m;

        vector<int> pos(n + 1,0);
        vector<bool> vis(n + 1, false);

        for(int i = 0; i < m; i++) {
            int index;
            cin >> index;

            pos[index] = 1;
        }

        //cout << "c1";

        bool one = false;


        for(int i = 0; i < adj[1].size(); i++) {
            
            int count2 = dfs(adj[1][i], adj, pos, -1, ans, vis);

            if(pos[1] == 1) count2++;

            if(one == false && count2 == 1) {
                one = true;
                ans.push_back(1);
            } 
        }

        //cout << "c2";

        cout << ans.size() << " ";

        for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

        cout << '\n';
    }
    return 0;
}