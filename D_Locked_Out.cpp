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
        vector<int> a(n);
        for (int &x : a) cin >> x;

        int max_a = *max_element(a.begin(), a.end());
        vector<int> freq(max_a + 2, 0);

        for (int x : a) freq[x]++;

        vector<long long> dp(max_a + 2, 0);
        dp[1] = freq[1];
        for (int i = 2; i <= max_a; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + freq[i]);
        }

        long long keep = dp[max_a];
        cout << n - keep << "\n";
    }
}
