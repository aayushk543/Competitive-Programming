#include<bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp;

long long f(vector<int>& h1, vector<int>& h2, int index, int prev) {
    int n = h1.size();

    if(index == n) return 0;

    if(dp[index][prev] != -1) return dp[index][prev];

    long long skip = f(h1, h2, index + 1, prev);

    long long take;

    if(prev == 1) take = h2[index] + f(h1, h2, index + 1, 2);
    else take = h1[index] + f(h1, h2, index + 1, 1);

    return dp[index][prev] = max(skip, take);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if(1) {
       int n;
       cin >> n;

       dp.resize(n, vector<long long>(3, -1));

       vector<int> h1(n);
       vector<int> h2(n);

       for(int i = 0; i < n; i++) cin >> h1[i];
       for(int i = 0; i < n; i++) cin >> h2[i];

       cout << max(f(h1, h2, 0, 1), f(h1, h2, 0, 2)) << '\n';
    }
    return 0;
}