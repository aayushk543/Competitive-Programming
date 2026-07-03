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

int find_parent(int index, vector<int>& parent) {
    if(index != parent[index]) return parent[index] = find_parent(parent[index], parent);

    return index;
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
        vector<int> size(n + 1, 1);

        vis[1] = true;

        int ans = 0;

        vector<int> parent(n + 1);

        for(int i = 1; i <= n; i++) parent[i] = i;
        

        for(int i = 1; i < n; i++) {
            int a,b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);

            if(vis[a]) {
                vis[b] = true;
                if(a != 1) ans += size[b];
            }
            else if(vis[b]) {
                vis[a] = true;
                if(b != 1) ans += size[a];
            }
            else if(!vis[a] && !vis[b]) {
                int parent1 = find_parent(a, parent);
                int parent2 = find_parent(b, parent);

                int size1 = size[parent1];
                int size2 = size[parent2];

                if(parent1 == parent2) continue;

                if(size1 > size2) {
                    parent[parent1] = parent2;
                    size[parent2] += size1;
                }
                else {
                    parent[parent2] = parent1;
                    size[parent1] += size2; 
                }
            }

            
        }

        // for(int i = 1; i <= n; i++)
        // cout << count[i] << '\n';

        

        

        cout << ans << '\n';
    }
    return 0;
}