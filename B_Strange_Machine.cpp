#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const unsigned int THRESH = 1u << 20;

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        int cntA = count(s.begin(), s.end(), 'A');
        int cntB = n - cntA;

        vector<unsigned long long> queries(q);
        for (int i = 0; i < q; ++i) cin >> queries[i];

        for (auto x : queries) {
            if (cntB == 0) {
                // All A
                cout << x << '\n';
                continue;
            }
            if (cntA == 0) {
                // All B
                if (x == 0) cout << 0 << '\n';
                else {
                    int bits = 64 - __builtin_clzll(x);
                    cout << 1ULL * bits * n << '\n';
                }
                continue;
            }

            // Mixed machines
            unsigned long long steps = 0;
            while (x > THRESH) {
                for (char c : s) {
                    if (x == 0) break;
                    if (c == 'A') x--;
                    else x >>= 1;
                    steps++;
                }
            }

            // Small x, simulate step by step
            while (x > 0) {
                for (char c : s) {
                    if (x == 0) break;
                    steps++;
                    if (c == 'A') x--;
                    else x >>= 1;
                }
            }

            cout << steps << '\n';
        }
    }

    return 0;
}
