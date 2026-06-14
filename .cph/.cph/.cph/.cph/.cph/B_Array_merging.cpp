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

        int ans = 1;
        
        int x = 0;

        for(int i = 0; i < 2*n; i++){
            cin >> x;
            mp[x]++;
            ans = max(ans, mp[x]);
        }

        cout << ans << '\n';
    }

    return 0;
}
