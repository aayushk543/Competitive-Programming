#include<bits/stdc++.h>
using namespace std;

void cal_leaf(vector<vector<int>>& adj, int index, vector<int>& leaf, vector<int>& vis) {
    vis[index] = 1;

    int count = 0;

    for(int i = 0; i < adj[index].size(); i++) {
        int node = adj[index][i];

        if(vis[node] == 0) {
            count++;
            cal_leaf(adj, node, leaf, vis);
        }
    }

    if(count == 0) leaf[index] = 1;
}

void len(vector<vector<int>>& adj, int index, vector<int>& arr) {


    for(int i = 0; i < adj[index].size(); i++) {
        int node = adj[index][i];

        if((arr.size() > 0 && arr[arr.size() - 1] != node) || arr.size() == 0) {
            arr.push_back(index);
            len(adj, node, arr);
        }
    }
    return;
}

void dfs2(vector<vector<int>>& adj, int index, int count, vector<int>& c) {
    c[index] = count;

    for(int i = 0; i < adj[index].size(); i++) {
        int node = adj[index][i];

        if(c[node] == -1) dfs2(adj, node, count, c);
    }
}

void dfs(vector<vector<int>>& adj, int index, vector<int>& c) {

    int count = 1;
    c[index] = 0;

    for(int i = 0; i < adj[index].size(); i++) {
        int node = adj[index][i];

        dfs2(adj, node, count++, c);
    }
}

bool f(vector<vector<int>>& adj, int n, int n1, int target) {
    vector<int> c(n + 1, -1);

    dfs(adj, target, c);

    bool flag1 = false;

    for(int i = 1; i <= n; i++) {
        int index1 = n1 - i;
        int index2 = i;

        if(index1 > 0 && index1 <= n && index2 > 0 && index2 <= n && index1 != index2) {

            if(c[index1] != c[index2]) {
                flag1 = true;
                break;
            }
        }
    }

    return flag1;

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

        for(int i = 1; i <= n - 1; i++) {
            int u,v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if(n % 2 == 0) {
            cout << n + 1 << '\n';
        }
        else {
            int n1 = n;
            int index1 = n;
            
            if(f(adj, n, n1, index1)) {
                cout << n1 << '\n';
                continue;
            }

            int n2 = n + 1;
            int index2 = (n + 1) / 2;

            if(f(adj, n, n2, index2)) {
                cout << n2 << '\n';
                continue;
            }


            cout << n + 2 << '\n';
            continue;

        }
    }
    return 0;
}