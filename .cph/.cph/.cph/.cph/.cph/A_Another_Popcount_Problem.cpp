#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long n, k;
        cin >> n >> k;

        long long ans = 0;

        for (long long p = 0; p < 60; p++) {
            long long cost = 1LL << p;
            if (cost > n) break;

            long long take = min(k, n / cost);
            ans += take;
            n -= take * cost;
        }

        cout << ans << '\n';
    }

    return 0;
}