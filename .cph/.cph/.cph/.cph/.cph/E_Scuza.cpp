#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<long long> a(n + 1);
        vector<long long> pref(n + 1, 0);
        vector<long long> mx(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pref[i] = pref[i - 1] + a[i];
            mx[i] = max(mx[i - 1], a[i]);
        }

        while (q--) {
            long long k;
            cin >> k;

            int pos = upper_bound(mx.begin() + 1, mx.end(), k) - mx.begin() - 1;

            cout << pref[pos] << " ";
        }

        cout << '\n';
    }

    return 0;
}