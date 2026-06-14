#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool y = false;

        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            if(m == 67) y = true;
        }

        if(y) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
