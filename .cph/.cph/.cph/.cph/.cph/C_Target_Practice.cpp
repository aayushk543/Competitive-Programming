#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int ans = 0;

        for(int i = 1; i <= 10; i++) {
            for(int j = 1; j <= 10; j++) {
                char c;
                cin >> c;
                if(c == 'X') ans += min(i, min(j, min(11 - i, 11 - j)));
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
