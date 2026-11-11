#include<bits/stdc++.h>
using namespace std;

//int check(int index, vector<int>& dp>)

int bs(vector<int>& vis, int dist) {
    int l = 0, r = vis.size() - 1;

    while(l < r) {
        int mid = (l + r) >> 1;


    }
}

string solve(int n, int m, int l, vector<int>& ms, vector<vector<int>>& adj) {
    vector<vector<int>> vis(n + 1, vector<int>(2, INT_MAX));

    queue<pair<int,int>> q;

    vis[1][0] = 0;
    q.push({0, 1});

    while(!q.empty()) {
        auto [dist, index] = q.front();
        q.pop();

        int p = (dist + 1) % 2;

        for(int i = 0; i < adj[index].size(); i++) {
            int node = adj[index][i];

            if(vis[node][p] > dist + 1) {
                vis[node][p] = 1 + dist;
                q.push({vis[node][p], node});
            }
        }
    }


    int mini_1 = INT_MAX;
    long long sum = 0;

    for(int i = 0; i < l; i++) {
        if(ms[i] % 2 == 1) mini_1 = min(mini_1, ms[i]);
        sum += ms[i];
    }

    long long sum_2 = -1, sum_1 = -1;

    if(sum % 2 == 0) {
        sum_2 = sum;
        if(mini_1 != INT_MAX) sum_1 = sum - mini_1;
        else sum_1 = 0;
    }
    else if(sum % 2 == 1) {
        sum_1 = sum;
        if(mini_1 != INT_MAX) sum_2 = sum - mini_1;
        else sum_2 = 0;
    }

    string ans = "";

    for(int i = 1; i <= n; i++) {
        int dist_1 = vis[i][1];
        int dist_2 = vis[i][0];

        if(dist_1 != INT_MAX && sum_1 >= dist_1) {
            ans += '1';
        }
        else if(dist_2 != INT_MAX && sum_2 >= dist_2) {
            ans += '1';
        }
        else ans += '0';

    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,m,l;
        cin >> n >> m >> l;

        vector<int> ms;

        for(int i = 1; i <= l; i++) {
            int curr;
            cin >> curr;

            ms.push_back(curr);
        }

        vector<vector<int>> adj(n + 1, vector<int>());

        for(int i = 1; i <= m; i++) {
            int u,v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << solve(n, m, l, ms, adj) << '\n';
    }
    
    return 0;
}