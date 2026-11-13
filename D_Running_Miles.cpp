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

        vector<long long> suf(n);
        vector<long long> pre(n);

        for(int i = n - 1; i >= 0; i--) {
            suf[i] = arr[i] - i;
            if(i < n - 1) suf[i] = max(suf[i], suf[i+1]);
        }
        for(int i = 0; i < n; i++) {
            pre[i] = arr[i] + i;

            if(i > 0) pre[i] = max(pre[i], pre[i-1]);
        }

        long long ans = 0;

        for(int i = 1; i < n - 1; i++) {
            ans = max(ans, pre[i-1] + arr[i] + suf[i+1]);
        }

        cout << ans << '\n';
    }
    return 0;
}