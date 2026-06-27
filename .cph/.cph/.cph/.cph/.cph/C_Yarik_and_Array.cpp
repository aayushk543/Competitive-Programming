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

       vector<int> v(n);
       int sum = 0;

       vector<int> dp(n);

       for(int i = 0; i < n; i++) {
        cin >> v[i];
        dp[i] = v[i];
       }

       int ans = dp[n-1];

       for(int i = n - 1; i >= 0; i--){ 
        int max_sum = dp[i];
        
        if(i + 1 < n && ((abs(v[i+1]) % 2 == 0 && abs(v[i]) % 2 == 1)|| (abs(v[i+1]) % 2 == 1 && abs(v[i]) % 2 == 0))) dp[i] = max(max_sum, max_sum + dp[i+1]);
        //if(i == 3) cout << ans << '\n'; 
        ans = max(ans, dp[i]);
        //if(i == 3) cout << ans << '\n'; 
       }

       //for(int i = 0; i < n; i++) cout << dp[i] << '\n';

       cout << ans << '\n';
    }
    return 0;
}