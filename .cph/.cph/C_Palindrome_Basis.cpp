#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;

vector<vector<long long>> dp;

bool check(int n) {
    vector<int> curr;

    while(n > 0) {

        curr.push_back(n % 10);
        n /= 10;

    }

    int i = 0, j = curr.size() - 1;

    while(i < j) {
        if(curr[i++] != curr[j--]) return false;
    }

    return true;
}

long long f(int num, int index, vector<int>& arr) {
    if(num == 0) return 1;
    if(index < 0 || num < 0) return 0;

    if(dp[num][index] != -1) return (dp[num][index]) % mod;

    if(num < arr[index]) return dp[num][index] = (f(num, index - 1, arr)) % mod;

    return dp[num][index] = (f(num - arr[index], index, arr) + f(num, index - 1, arr)) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr;

    for(int i = 1; i <= 40000; i++) {
        if(check(i)) arr.push_back(i);
    }

    dp.resize(40001, vector<long long>(arr.size(), -1));

    int t;
    cin >> t;
    while(t--) {
       int n;

       cin >> n;

       long long ans = f(n, arr.size() - 1, arr);

       cout << ans << '\n';
    }
    return 0;
}