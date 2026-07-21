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

       vector<long long> adj(n + 1);

       for(int i = 1; i <= n; i++) {
        cin >> adj[i];
       }

       long long gang1 = -1, gang2 = -1;
       int city1 = -1, city2 = -1;

       for(int i = 1; i <= n; i++) {
        if(gang1 == -1) {
            gang1 = adj[i];
            city1 = i;
        }
        else if(gang1 != adj[i]) {
            gang2 = adj[i];
            city2 = i;
        }

        if(gang1 != -1 && gang2 != -1) break;
       }

       if(gang2 == -1) {
        cout << "NO" << '\n';
        continue;
       }

       cout << "YES" << '\n';

       for(int i = 1; i <= n; i++) {
        if(adj[i] != gang1) {
            cout << i << " " << city1 << '\n'; 
        } 
       }

       for(int i = 1; i <= n; i++) {
        if(adj[i] == gang1 && i != city1) {
            cout << i << " " << city2 << '\n';
        }
       }


    }
    return 0;
}