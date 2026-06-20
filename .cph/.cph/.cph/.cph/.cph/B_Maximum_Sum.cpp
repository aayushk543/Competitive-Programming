#include<bits/stdc++.h>
using namespace std;

long long f(vector<vector<long long>>& dp, vector<long long>& arr, int i, int j, int k){

    if(dp[i][j] != -1) return dp[i][j];

    if(k <= 1) {
        return dp[i][j] = min(arr[i] + arr[i+1], arr[j]);
    }

    long long m1 = arr[i] + arr[i+1] + f(dp, arr, i+2, j, k-1);
    long long m2 = arr[j] + f(dp, arr, i, j-1, k-1);

    return dp[i][j] = min(m1, m2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n, k;
       cin >> n >> k;

       vector<long long> arr(n);

       long long sum = 0;

       for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
       }

       sort(arr.begin(), arr.end());

       vector<vector<long long>> dp(2*k + 1, vector<long long>(n, -1));

       if(k == 0) cout << sum << '\n';
       else cout << sum - f(dp, arr, 0, n-1, k) << '\n';
    }
    return 0;
}