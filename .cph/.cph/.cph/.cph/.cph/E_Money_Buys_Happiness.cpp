#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        
        long long m,x;

       cin >> m >> x;

       vector<vector<long long>> h(m);

       long long sum = 0;

       for(int i = 0; i < m; i++) {
        long long m1, m2;
        cin >> m1 >> m2;

        sum += m2;

        h[i] = {m1, m2};
       }

       vector<vector<long long>> dp(m + 1, vector<long long>(sum + 1, LLONG_MAX));

       dp[0][0] = 0;

       for(int i = 1; i <= m; i++) {

        long long m1 = h[i-1][0];
        long long m2 = h[i-1][1];

        for(int j = 0; j <= sum; j++) {

            dp[i][j] = dp[i-1][j];

            if(j >= m2 && dp[i-1][j - m2] != LLONG_MAX && dp[i-1][j - m2] + m1 <= (i - 1)*x) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-m2] + m1);
            }
        }
       }

       long long ans = 0;

       for(int i = sum; i >= 0; i--) {
        if(dp[m][i] != LLONG_MAX) {
            ans = i;
            break;
        }
       }

       cout << ans << '\n';

       
    }
    return 0;
}   