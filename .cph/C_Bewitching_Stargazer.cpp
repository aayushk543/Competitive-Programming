#include<bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp;

long long f(long long l, long long r, long long k) {
    if(r - l + 1 < k) return 0;

    long long m = (l + r) >> 1;

    if(dp[l][r] != -1) {
        return dp[l][r];
    }

    if((r - l + 1) % 2 == 0) {
        return dp[l][r] = f(m + 1, r, k) + f(l, m, k);
    }
    else {
        return dp[l][r] = m + f(l, m - 1, k) + f(m + 1, r, k);
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        long long n,k;
        cin >> n >> k;
        
        long long ans = 0;
        long long count = 1;
        long long curr = n;

        while(curr >= k) {
            
            if(curr % 2 == 1) {
                ans += (count * (n + 1)) / 2;;
                //cout << ans << '\n';
            }

            curr /= 2;
            count *= 2;
        }

        cout << ans << '\n';
    }
    return 0;
}