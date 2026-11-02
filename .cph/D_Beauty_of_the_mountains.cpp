#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    //cout << "yes" << '\n';
    while(t--) {
       int n,m,k;
       cin >> n >> m >> k;

       vector<vector<int>> adj(n + 1, vector<int>(m + 1));

       for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cin >> adj[i][j];
       }

       vector<vector<int>> snow(n + 1, vector<int>(m + 1));
       long long snow_cap = 0, w_snow_cap = 0;

       for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for(int j = 1; j <= m; j++) {
            snow[i][j] = (s[j] - '0');

            if(snow[i][j] == 0) snow_cap += adj[i][j];
            else w_snow_cap += adj[i][j];
        }
       }

       vector<vector<int>> pre(n + 1, vector<int>(m + 1));

       for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            pre[i][j] = (pre[i-1][j-1] + adj[i][j]);
        }
       }

       for(int i = 1; i <= n; i++) {

       }


    }
    return 0;
}