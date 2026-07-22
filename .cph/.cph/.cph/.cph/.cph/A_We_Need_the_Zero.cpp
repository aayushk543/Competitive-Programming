#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        long long ans = 0;

        for(int i = 0; i < n; i++) {
            int curr;
            cin >> curr;

            if(i == 0) ans = curr;
            else ans ^= curr;
        }

        if(n % 2 == 0) {
            if(ans == 0) cout << 0 << '\n';
            else cout << -1 << '\n';
        }
        else {
            cout << ans << '\n';
        }
    }
    return 0;
}
