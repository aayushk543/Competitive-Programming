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

        
        ll sum = 0;
        for (int i = 0; i < n-1; i++) {
            int m;
            cin >> m;
            sum += m;
        }

        cout << -1*sum << '\n';


    }

    return 0;
}
