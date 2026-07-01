#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

bool check(long long n, long long k, int r) {
    i128 sum = 1;
    i128 cur = 1;

    for (int i = 1; i <= r; i++) {
        cur *= k;
        sum += cur;

        if (sum > n)
            return false;
    }

    return sum == n;
}

pair<long long, int> findKR(long long n) {
    int maxR = log2l(n);

    for (int r = maxR; r >= 1; r--) {
        long long k = powl((long double)n, 1.0L / r);

        for (long long cand = max(2LL, k - 2);
             cand <= k + 2;
             cand++) {
            if (check(n, cand, r))
                return {cand, r};
        }
    }

    return {-1, -1};
}

int main() {
    long long n;
    cin >> n;

    auto [k, r] = findKR(n);

    if (k == -1)
        cout << "No solution\n";
    else
        cout << "k = " << k << ", r = " << r << '\n';
}