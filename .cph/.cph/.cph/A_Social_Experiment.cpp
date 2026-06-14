#include<bits/stdc++.h>
using namespace std;

long long f(long long n, long long k, vector<long long>& dp){
    if(n < k) return LLONG_MAX;
    if(n == k) return 0;
    if(dp[n] != -1) return dp[n];

    if(n % 2 == 0){
        dp[n] = 1 + f(n/2, k, dp);
    } else {
        dp[n] = 1 + min(f(n/2, k, dp), f(n/2 + 1, k, dp));
    }
    return dp[n];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n,k;
        cin >> n >> k;

        vector<long long> dp(n+5, -1);
        long long ans = f(n, k, dp);
        if(ans == LLONG_MAX) ans = -1;

        cout << ans << '\n';


    }
    return 0;
}
