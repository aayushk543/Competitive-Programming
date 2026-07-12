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

        map<int,int> mp;
        long long ans = 0;

        for(int i = 1; i <= n; i++) {
            int m;
            cin >> m;

            mp[m - i]++;
        }

        for(auto it = mp.begin(); it != mp.end(); it++){
            int num = it->second;
            ans +=  ((long long)num * (num - 1)) / 2LL; 
        }

        cout << ans << '\n';
    }
    return 0;
}