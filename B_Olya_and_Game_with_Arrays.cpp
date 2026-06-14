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
        cin >> n;

        vector<pair<ll,ll>> v;

        long long mini = INT_MAX;

        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            ll a1 = INT_MAX,a2 = INT_MAX;
            for(int i = 0; i < m; i++){
                
                ll m2;
                cin >> m2;

                mini = min(mini, m2);

                if(a1 >= m2){
                    a2 = a1;
                    a1 = m2;
                }
                else a2 = min(a2,m2);

                if(i == m-1){
                    v.push_back({a1,a2});
                }
            }
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b){
        return a.second < b.second;
        });

        long long ans = 0;

        for(int i = n-1; i >= 1; i--){
            ans += v[i].second;
        }
        ans += mini;

        cout << ans << '\n';
    }
    return 0;
}