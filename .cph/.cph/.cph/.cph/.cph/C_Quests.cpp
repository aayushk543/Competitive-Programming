#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n,k;
       cin >> n >> k;

       vector<pair<int,int>> vp;
       int prev;

       int m;
       cin >> m;
       vp.push_back({m, 0});
       prev = m;

       for(int i = 1; i < n; i++){
            int n;
            cin >> n;
            vp.push_back({n + prev, 0});
            prev += n;
       }

       for(int i = 0; i < n; i++){
            cin >> vp[i].second;
       }

       int ans = 0;
       int maxi_b = 0;

       for(int i = 0; i < min(n,k); i++){
            maxi_b = max(maxi_b, vp[i].second);
            ans = max(ans, vp[i].first + (k-i-1)*maxi_b);
       }

       cout << ans << '\n';

    }
    return 0;
}