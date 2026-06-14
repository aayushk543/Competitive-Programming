#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, x, y, z;
        cin >> n >> x >> y >> z;

        double t1 = (double)n / (x + y);

        if (t1 <= (double)10 * z / 9) {
            cout << (long long)ceil(t1) << '\n';
        } else {
            double t2 = (double)(n + 10LL * y * z) / (x + 10 * y);
            cout << (long long)ceil(t2) << '\n';
        }
    }

    return 0;
}