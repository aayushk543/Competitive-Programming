#include<bits/stdc++.h>
using namespace std;

map<pair<long long, long long>, long long> dp;

long long f(long long n, long long k){
    if(n == k) return 0;
    if(n < k) return LLONG_MAX;
    
    pair<long long, long long> state = {n, k};
    if(dp.find(state) != dp.end()) return dp[state];
    
    if(n % 2 == 0){
        return dp[state] = (f(n/2, k) == LLONG_MAX ? LLONG_MAX : f(n/2, k) + 1);
    }
    else{
        long long opt1 = f(n/2 + 1, k);
        long long opt2 = f(n/2, k);
        
        long long result = LLONG_MAX;
        if(opt1 != LLONG_MAX) result = min(result, opt1 + 1);
        if(opt2 != LLONG_MAX) result = min(result, opt2 + 1);
        
        return dp[state] = result;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        
        dp.clear();
        long long ans = f(n, k);
        
        if(ans == LLONG_MAX){
            ans = -1;
        }
        
        cout << ans << '\n';
    }
    return 0;
}