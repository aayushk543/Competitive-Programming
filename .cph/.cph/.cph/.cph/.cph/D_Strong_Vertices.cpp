#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<int>& vis, int index, stack<int>& st) {
    vis[index] = 1;

    for(int i = 0; i < adj[index].size(); i++) {
        if(vis[adj[index][i]] == -1) dfs(adj, vis, adj[index][i], st);
    }

    // vis[index] = 1;
    st.push(index);
}

void dfs2(vector<vector<int>>& adj, vector<int>& vis, int index, vector<int>& comp, int scc) {
    vis[index] = 1;
    comp[index] = scc;

    for(int i = 0; i < adj[index].size(); i++) {
        if(vis[adj[index][i]] == -1) dfs2(adj, vis, adj[index][i], comp, scc);
    }

    // vis[index] = 1;
    // st.push(index);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n+1);
        vector<int> b(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];

        int maxi = INT_MIN;

        for(int i = 1; i <= n; i++) {
            maxi = max(maxi, a[i] - b[i]);
        }

        vector<int> ans;

        for(int i = 1; i <= n; i++) {
            if(a[i] - b[i] == maxi) ans.push_back(i);
        }

        cout << ans.size() << '\n';

        for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

        cout << '\n';

        // vector<int> vis(n + 1, -1);
        // stack<int> st;

        // for(int i = 1; i <= n; i++){
        //     if(vis[i] == -1) dfs(adj, vis, i, st);
        // }

        // vector<vector<int>> adj2(n + 1, vector<int>());

        // for(int i = 1; i <= n; i++) {
        //     vis[i] = -1;
        //     for(int j = 0; j < adj[i].size(); j++) {
        //         adj2[adj[i][j]].push_back(i);
        //     }
        // }

        // vector<int> ans;
        // vector<int> comp(n + 1);
        // int scc = 0;

        // while(!st.empty()) {
        //     int curr = st.top();
        //     st.pop();

        //     if(vis[curr] == -1) {
        //         // ans.push_back(curr);
        //         dfs2(adj2, vis, curr, comp, scc);
        //         scc++;
        //     }
        // }

        // vector<int> indeg(scc, 0);

        // for(int i = 1; i <= n; i++) {
        //     for(int j = 0; j < adj[i].size(); j++) {
        //         if(comp[i] != comp[adj[i][j]]) indeg[comp[adj[i][j]]]++;
        //     }
        // }

        // int source = -1;
        // int count = 0;

        // for(int i = 0; i < scc; i++) {
        //     if(indeg[i] == 0) {
        //         source = i;
        //         count++;
        //     }
        // }

        // if(count == 1){
        //     for(int i = 1; i <= n; i++) {
        //         if(comp[i] == source) ans.push_back(i);
        //     }
        // }

        // cout << ans.size() << '\n';

        // for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

        // cout << '\n';

    }
    return 0;
}