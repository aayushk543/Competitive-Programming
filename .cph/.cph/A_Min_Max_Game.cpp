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

        int count = 0;

        for(int i = 0; i < n; i++) {
            int curr;
            cin >> curr;

            if(curr == 1) count++;
        }

        if(count >= n - count) cout << "Bessie" << '\n';
        else cout << "Elsie" << '\n';
    }
}