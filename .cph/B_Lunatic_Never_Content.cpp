#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n;
       cin >> n;

       vector<long long> arr(n);

       for(int i = 0; i < n; i++) cin >> arr[i];

       long long ans = INT_MAX;

       for(int i = 0; i < n/2; i++) {
        if(arr[i] != arr[n - i - 1]) ans = min(ans, max(arr[i], (arr[n - i - 1])) - min(arr[i], (arr[n - i - 1])));
       }

       if(ans == INT_MAX) cout << 0 << '\n';
       else cout << ans << '\n';

    }
    return 0;
}