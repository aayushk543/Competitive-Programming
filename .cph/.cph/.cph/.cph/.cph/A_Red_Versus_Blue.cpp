#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        double n, r, b;
        cin >> n >> r >> b;

        int count = (r / b);
        if(count > 2 && b == 1) count -= 1;
        string ans = "";

        for(int i = 1; i <= n; i++) {
            if(i % count == 0) ans += 'B';
            else ans += 'R';
        }

        cout << ans << '\n';
    }
    return 0;
}