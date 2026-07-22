#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;

        cin >> n >> k;

        if(n <= k) {
            cout << 1 << '\n';
            continue;
        }

        long long ans = n;

        for(long long i = 1; i * i <= n && i <= k; i++) {
            if(n % i == 0) {
                ans = min(ans, n / i);
                if(n / i <= k) ans = min(ans, i);
            }
        }

        cout << ans << '\n';

    }

    return 0;
}
