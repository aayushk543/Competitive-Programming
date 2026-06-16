#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        const long long MOD = 1000000007;
const long long INV6 = 166666668; // 6^(MOD-2) mod MOD

long long a = n % MOD;
long long b = (n + 1) % MOD;
long long c = (4 * (n % MOD) - 1 + MOD) % MOD;

long long ans = a;
ans = ans * b % MOD;
ans = ans * c % MOD;
ans = ans * INV6 % MOD;
ans = ans * 2022 % MOD;

cout << ans << '\n';
    }

    return 0;
}