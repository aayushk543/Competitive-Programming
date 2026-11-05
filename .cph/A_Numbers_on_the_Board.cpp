#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int l,r;
        cin >> l >> r;

        if(l == r) cout << 0 << '\n';
        else if((l > 0 && r > 0) || (l < 0 && r < 0)) cout << abs(r - l) << '\n';
        else if(l == 0 || r == 0) cout << abs(r - l) - 1 << '\n';
        else {
            l *= -1;

            cout << max(0, abs(l - r) - 1) << '\n';
        }

    }
    return 0;
}