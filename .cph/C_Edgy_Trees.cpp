#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int find_parent(vector<int>& parent, int index) {

    if(parent[index] != index) return parent[index] = find_parent(parent, parent[index]);

    return index;
}

long long expo(int num, int k) {
    long long ans = 1;

    while(k--) ans = (ans * num) % mod;

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if(1) {
       int n,k;
       cin >> n >> k;

       vector<vector<vector<int>>> adj(n + 1);
       vector<int> size(n + 1, 1);
       vector<int> parent(n + 1);

       for(int i = 1; i <= n; i++) parent[i] = i;

       for(int i = 1; i <= n - 1; i++) {
        int u,v,c;

        cin >> u >> v >> c;

        adj[u].push_back({v, c});
        adj[v].push_back({u, c});

        if(c == 1) continue;
        else {

            int parent1 = find_parent(parent, u);
            int parent2 = find_parent(parent, v);

            int size1 = size[parent1];
            int size2 = size[parent2];

            if(parent1 == parent2) continue;
            else {

                if(size1 < size2) {
                    size[parent2] += size1;
                    parent[parent1] = parent2;
                }
                else {
                    size[parent1] += size2;
                    parent[parent2] = parent1;
                }
            }
        }
       }

       long long res = 0;

       for(int i = 1; i <= n; i++) {

        if(find_parent(parent, parent[i]) == i) {

            res = (res + expo(size[i], k)) % mod;
        }
       }

       long long total = expo(n, k) % mod;

       cout << (total - res + mod) % mod << '\n';


    }
    return 0;
}