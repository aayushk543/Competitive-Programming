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

       priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
       vector<vector<long long>> adj(n + 1);

       set<vector<long long>> s;

       for(int i = 0; i < n; i++) {
        long long l,r;

        cin >> l >> r;

        s.insert({l, r});
        pq.push({r, l});
       }

       for(int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
       }

       int count = n - 2;
       long long ans = 0;

       while() {

        vector<long long> curr;
        s.erase(pq.top());
       }


    }
    return 0;
}