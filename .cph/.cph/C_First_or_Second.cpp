#include <bits/stdc++.h>
using namespace std;

vector<long long> a;
vector<long long> dp;
int n;

long long f(int i) {
    if (i >= n - 1) return 0;

    if (dp[i] != LLONG_MIN) return dp[i];

    return dp[i] = max(
        a[i]     + f(i + 1),
       -a[i + 1] + f(i + 2)
    );
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        dp.assign(n, LLONG_MIN);

        cout << f(0) << '\n';
    }
    return 0;
}
