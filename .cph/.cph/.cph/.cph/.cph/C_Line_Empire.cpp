#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,a,b;
        cin >> n >> a >> b;

        vector<long long> arr(n + 1, 0);
        long long pre = 0;

        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
            pre += arr[i];
        }

        long long ans = b * pre;

        for(int i = 1; i <= n; i++) {
            pre -= (arr[i] - arr[i-1]) * (n + 1 - i);
            long long cost = (a + b) * (arr[i]) + b * (pre);

            ans = min(ans, cost);
        }

        cout << ans << '\n';


    }
    return 0;
}