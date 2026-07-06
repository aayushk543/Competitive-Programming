#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int k;
       cin >> k;

       long long maxi = 0;
       int count_p = 0;

       for(int i = 1; i <= k; i++) {
        long long m;
        cin >> m;
        maxi = max(maxi, m);
        if(m > 1) count_p++; 
       }

       if(maxi > 2 || count_p > 1) cout << "YES" << '\n';
       else cout << "NO" << '\n';
    }
    return 0;
}