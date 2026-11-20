#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,j,k;
        cin >> n >> j >> k;

        int winn = -1, maxi = INT_MIN;

        for(int i = 1; i <= n; i++) {
            int curr;
            cin >> curr;

            if(i == j) winn = curr;
            maxi = max(maxi, curr);
        }

        if(k > 1) cout << "YES" << '\n';
        else if(maxi != winn) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    return 0;
}