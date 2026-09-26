#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;

        if(n % 2 == 0) {
            if(k > n) k = k % n;
            if(k == 0) k = n;
            cout << k % (n + 1) << '\n';
        }
        else {

            int num = (n/2);
            int req = ((k - 1)/num);

            int ans = (k + req) % (n);
            if(ans == 0) ans = n;

            cout << ans << '\n';
        }
    }
}