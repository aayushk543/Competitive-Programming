#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        ll x,y;
        
        cin >> n >> x >> y;

        vector<pair<ll,ll>> v;

        for(int i = 0; i < n; i++){
            ll m;
            cin >> m;

            ll m1 = m/x;

            v.push_back({m1*y, m - m1*y});
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b){
        return a.second < b.second;
        });

        ll ans = v[n-1].first + v[n-1].second;

        for(int i = 0; i < n-1; i++){
            ans += v[i].first;
        }

        cout << ans << '\n';


    }
    return 0;
}