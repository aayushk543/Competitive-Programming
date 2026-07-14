#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;

        vector<long long> vec(n + 1, 0);
        vector<long long> prefix(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            cin >> vec[i];
            prefix[i] = vec[i];
            if(i > 0) prefix[i] += prefix[i-1];
        }

        long long ans = b*(prefix[n]);

        for(int i = 1; i <= n; i++) {
            ans = min(ans, (prefix[i] - prefix[i-1])*(a+b) + b*((n - i + 1)*prefix[i]));
        }

        cout << ans << '\n';
    }
    return 0;
}