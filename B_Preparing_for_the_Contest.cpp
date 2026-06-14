#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main() {
        int n,m;
        ll s;

        cin >> n >> m >> s;

        vector<ll> a(m);
        vector<pair<ll,ll>> b(n);

        for(int i = 0; i < m; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i].first;
        for(int i = 0; i < n; i++) cin >> b[i].second;

        sort(b.begin(), b.end());
        bool p = true;

        vector<ll> ans;

        for(int i = 0; i < m; i++){
            ll diff = a[i];
            int j = n-1;
            ll mini = b[j].second;
            while(j >= 0 && b[j].first <= diff){
                mini = min(mini, b[j].second);
                j--;
            }
            
            if(s >= mini) ans.push_back(b[j].first);
            else {
                p = false;
                cout << "NO" << '\n'; 
                break;
            }
        }
        if(p){
            cout << "YES" << '\n';
            for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
            cout << '\n';
        }
    
    return 0;
}