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

        ll k;
        cin >> k;

        map<ll,vector<int>> mp;

        for(int i = 0; i < n; i++){
            ll m;
            cin >> m;
            m %= k;
            if(m == 0) cout << i + 1 << " ";
            else mp[m].push_back(i+1);
        }
      
        for (auto it = mp.rbegin(); it != mp.rend(); it++) {
            ll key = it->first;
            vector<int> &v = it->second;

            for (int x : v) cout << x << " ";
        }

        cout << '\n';


    }
    return 0;
}